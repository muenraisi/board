/* board_property.h */

#ifndef BOARD_PROPERTY_H
#define BOARD_PROPERTY_H

#include "core/object/ref_counted.h"
#include "core/templates/hash_map.h"
#include "core/variant/array.h"
#include "core/variant/variant.h"

struct BoardPropertyStruct {
	Variant base;
	Variant min;
	Variant max;
	Array extend;

	BoardPropertyStruct() :
			base(Variant()), min(Variant()), max(Variant()), extend(Array()){};
	BoardPropertyStruct(Variant &base_) :
			base(base_), min(Variant()), max(Variant()), extend(Array()){};
	BoardPropertyStruct(Variant &base_, Variant &min_, Variant &max_) :
			base(base_), min(min_), max(max_), extend(Array()){};
	BoardPropertyStruct(Variant &base_, Variant &min_, Variant &max_, Array &extend_) :
			base(base_), min(min_), max(max_), extend(extend_){};
};

class BoardProperty : public RefCounted {
	GDCLASS(BoardProperty, RefCounted);

private:
	HashMap<StringName, BoardPropertyStruct> _data;

protected:
	static void _bind_methods();

public:
	bool has(StringName name);

	void insert(StringName name, Variant base = Variant(), Variant min = Variant(), Variant max = Variant(), Array extend = Array());
	void set_full(StringName name, Variant base, Variant min, Variant max, Array extend = Array());

	void set_base(StringName name, Variant base);
	Variant get_base(StringName name);
	void set_min(StringName, Variant min);
	Variant get_min(StringName name);
	void set_max(StringName, Variant max);
	Variant get_max(StringName name);

	void set_range(StringName name, Variant min, Variant max);

	Variant get_final(StringName name);

	BoardProperty(){};
};

#endif // BOARD_PROPERTY_H
