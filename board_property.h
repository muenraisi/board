/* board_property.h */

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
		Variant min;
		Variant max;

		BoardProperty(){};

		BoardProperty(Variant var_, Variant min_, Variant max_) :
				var(var_), min(min_), max(max_){};

		void clamp_var() {
			if (min != Variant() && var < min)
				var = min;
			if (max != Variant() && max < var)
				var = max;
		};
	};

	struct BoardPropertyProcessor {
		BoardProperty base;
		Array extends;

		BoardPropertyProcessor(){};
		BoardPropertyProcessor(BoardProperty &base_, Array &extends_) :
				base(base_), extends(extends_){};
		BoardPropertyProcessor(Variant var_, Variant min_, Variant max_, Array &extends_) :
				base(BoardProperty(var_, min_, max_)), extends(extends_){};

		BoardProperty get_final() {
			BoardProperty final;
			if (extends.is_empty()) {
				final = base;
			} else {
				// TODO: calc final with extends
			}
			final.clamp_var();
			WARN_PRINT("Array extends is not empty and the code is undone");
			return final;
		}
	};

private:
	HashMap<StringName, BoardPropertyProcessor> _data;

protected:
	static void _bind_methods();

public:
	bool has(StringName name);

	void insert(StringName name, Variant base = Variant(), Variant min = Variant(), Variant max = Variant(), Array extend = Array());
	void set_full(StringName name, Variant var, Variant min, Variant max, Array extend = Array());

	void set_base(StringName name, BoardProperty &base);
	BoardProperty get_base(StringName name);
	void set_var(StringName name, Variant var);
	Variant get_var(StringName name);
	void set_min(StringName, Variant min);
	Variant get_min(StringName name);
	void set_max(StringName, Variant max);
	Variant get_max(StringName name);

	void set_range(StringName name, Variant min, Variant max);

	BoardProperty get_final(StringName name);
	Variant get_final_var(StringName name);
	Variant get_final_min(StringName name);
	Variant get_final_max(StringName name);

	BoardPropertyManager(){};
};

#endif // BOARD_PROPERTY_H
