/* board_property.h */

#ifndef BOARD_PROPERTY_H
#define BOARD_PROPERTY_H

#include "core/variant/variant.h"
#include "core/variant/array.h"
#include "core/templates/hash_map.h"
#include "core/object/ref_counted.h"

struct BoardPropertyStruct {
	Variant base;
	Array extend; 

	BoardPropertyStruct() :
			base(NULL), extend(Array()){};
	BoardPropertyStruct(Variant &base_) :
			base(base_), extend(Array()){};
};


class BoardProperty : public RefCounted {
	GDCLASS(BoardProperty, RefCounted);

private:
	HashMap<StringName, BoardPropertyStruct> _data;

protected:
	static void _bind_methods();

public:
	bool has(StringName name);

	void insert_base(StringName name, Variant value);
	void set_base(StringName name, Variant value);
	Variant get_base(StringName name);

	Variant get(StringName name);

	BoardProperty(){};
};

#endif // BOARD_PROPERTY_H
