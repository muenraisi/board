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
	ERR_FAIL_COND_MSG(has(name), vformat("Board Property has alerady had %s property!", name));
	_data[name] = BoardPropertyStruct(value);
}



void BoardProperty::set_base(StringName name, Variant value) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	if (has(name)) {
		_data[name].base = value;
	} else {
		insert_base(name, value);
	}
}

Variant BoardProperty::get_base(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), NULL, vformat("Board Property has not %s property!", name));
	return _data[name].base;
}

Variant BoardProperty::get(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), NULL, vformat("Board Property has not %s property!", name));
	if (_data[name].extend.is_empty()) {
		return _data[name].base;
	}

	return Variant();
}


void BoardProperty::_bind_methods() {
	ClassDB::bind_method(D_METHOD("insert_base", "name", "value"), &BoardProperty::insert_base);
	ClassDB::bind_method(D_METHOD("set_base", "name", "value"), &BoardProperty::set_base);
	ClassDB::bind_method(D_METHOD("get_base", "name"), &BoardProperty::get_base);

}

