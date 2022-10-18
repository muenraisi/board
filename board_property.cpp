/* board_property.cpp */

#include "board_property.h"



bool BoardProperty::has(StringName name) {
	if (_data.find(name) == _data.end()) {
		return false;
	} else {
		return true;
	}
}


void BoardProperty::insert_base(StringName name, Variant value) {
	_data[name] = BoardPropertyStruct(value);
}



void BoardProperty::set_base(StringName name, Variant value) {
	if (has(name)) {
		_data[name].base = value;
	} else {
		insert_base(name, value);
	}
}

Variant BoardProperty::get_base(StringName name) {
	if (has(name)) {
		return _data[name].base;
	} else {
		return NULL;
	}
}


void BoardProperty::_bind_methods() {
	ClassDB::bind_method(D_METHOD("insert_base", "name", "value"), &BoardProperty::insert_base);
	ClassDB::bind_method(D_METHOD("set_base", "name", "value"), &BoardProperty::set_base);
	ClassDB::bind_method(D_METHOD("get_base", "name", "value"), &BoardProperty::get_base);

}

