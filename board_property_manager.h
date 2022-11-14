

#ifndef BOARD_PROPERTY_H
#define BOARD_PROPERTY_H

#include "core/object/ref_counted.h"
#include "core/templates/hash_map.h"
#include "core/variant/array.h"
#include "core/variant/variant.h"

class BoardPropertyManager : public RefCounted {
	GDCLASS(BoardPropertyManager, RefCounted);

	struct BoardProperty {
		Variant var;
		Variant low;
		Variant upp;

		BoardProperty(){};

		BoardProperty(Variant var_, Variant low_, Variant upp_) :
				var(var_), low(low_), upp(upp_){};

		Variant get_var() {
			if (var.get_type() == Variant::CALLABLE) {
				return Callable(var).callv(Array());
			} else {
				return var;
			}
		}

		Variant get_low() {
			if (low.get_type() == Variant::CALLABLE) {
				return Callable(low).callv(Array());
			} else {
				return low;
			}
		}

		Variant get_upp() {
			if (upp.get_type() == Variant::CALLABLE) {
				return Callable(upp).callv(Array());
			} else {
				return upp;
			}
		}

		bool is_low() {
			if (low != Variant()) {
				return Variant::evaluate(Variant::OP_LESS_EQUAL, get_var(), get_low());		
			} else {
				return false;
			}
		}

		bool is_upp() {
			if (upp != Variant()) {
				return Variant::evaluate(Variant::OP_GREATER_EQUAL, get_var(), get_upp());
			} else {
				return false;
			}
		}

		void clamp_var() {
			if (var != Variant()) {
				if (is_low()) {
					var = low;
					return;
				}
				if (is_upp()) {
					var = upp;
					return;
				}
			}
		};
	};

	struct BoardPropertyProcessor {
		BoardProperty base;
		Array extends;

		BoardPropertyProcessor(){};
		BoardPropertyProcessor(BoardProperty &base_, Array &extends_) :
				base(base_), extends(extends_){};
		BoardPropertyProcessor(Variant var_, Variant low_, Variant upp_, Array &extends_) :
				base(BoardProperty(var_, low_, upp_)), extends(extends_){};

		BoardProperty get_final() {
			BoardProperty final;
			if (extends.is_empty()) {
				final = base;
			} else {
				WARN_PRINT_ONCE("[TODO]: Array extends is not empty and the code is undone");
				// TODO: calc final with extends
			}
			final.clamp_var();
			return final;
		}
	};

private:
	HashMap<StringName, BoardPropertyProcessor> _data;

protected:
	static void _bind_methods();

public:
	bool has(StringName name);

	void insert(StringName name, Variant var = Variant(), Variant low = Variant(), Variant upp = Variant(), Array extend = Array());
	void set_full(StringName name, Variant var, Variant low, Variant upp, Array extend = Array());

	void set_base(StringName name, BoardProperty &base);
	BoardProperty get_base(StringName name);
	void set_var(StringName name, Variant var);
	Variant get_var(StringName name);
	void set_low(StringName, Variant low);
	Variant get_low(StringName name);
	void set_upp(StringName, Variant upp);
	Variant get_upp(StringName name);

	void increase_var(StringName name, Variant increasement);

	void as_low(StringName name);
	void as_upp(StringName name);

	bool is_low(StringName name);
	bool is_upp(StringName name);

	void set_range(StringName name, Variant low, Variant upp);

	BoardProperty get_final(StringName name);
	Variant get_final_var(StringName name);
	Variant get_final_low(StringName name);
	Variant get_final_upp(StringName name);

	BoardPropertyManager(){};
};

#endif // BOARD_PROPERTY_H
