/* board_property.cpp */

#include "board_property.h"

bool BoardProperty::has(StringName name) {
	if (_data.find(name) == _data.end()) {
		return false;
	} else {
		return true;
	}
}

void BoardProperty::insert(StringName name, Variant base, Variant min, Variant max, Array extend) {
	ERR_FAIL_COND_MSG(has(name), vformat("Board Property has alerady had %s property!", name));
	_data[name] = BoardPropertyStruct(base, min, max, extend);
}

void BoardProperty::set_full(StringName name, Variant base, Variant min, Variant max, Array extend) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name] = BoardPropertyStruct(base, min, max, extend);
}

void BoardProperty::set_base(StringName name, Variant base) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name].base = base;
}

Variant BoardProperty::get_base(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), Variant(), vformat("Board Property has not %s property!", name));
	return _data[name].base;
}

void BoardProperty::set_min(StringName name, Variant min) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name].min = min;
}

Variant BoardProperty::get_min(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), Variant(), vformat("Board Property has not %s property!", name));
	return _data[name].min;
}

void BoardProperty::set_max(StringName name, Variant max) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name].max = max;
}

Variant BoardProperty::get_max(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), Variant(), vformat("Board Property has not %s property!", name));
	return _data[name].max;
}

void BoardProperty::set_range(StringName name, Variant min, Variant max) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name].min = min;
	_data[name].max = max;
}

Variant BoardProperty::get_final(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), Variant(), vformat("Board Property has not %s property!", name));
	if (_data[name].extend.is_empty()) {
		return _data[name].base;
	}
	ERR_FAIL_V_MSG( Variant(), "Array extend is not empty and the code is undone");
	return Variant();
}

void BoardProperty::_bind_methods() {
	ClassDB::bind_method(D_METHOD("has", "name"), &BoardProperty::has);

	ClassDB::bind_method(D_METHOD("insert", "name", "base", "min", "max", "extend"), &BoardProperty::insert, Array(), Variant(), Variant(), Variant());
	ClassDB::bind_method(D_METHOD("set_full", "name", "base", "min", "max", "extend"), &BoardProperty::set_full, Array());

	ClassDB::bind_method(D_METHOD("set_base", "name", "base"), &BoardProperty::set_base);
	ClassDB::bind_method(D_METHOD("get_base", "name"), &BoardProperty::get_base);
	ClassDB::bind_method(D_METHOD("set_min", "name", "min"), &BoardProperty::set_min);
	ClassDB::bind_method(D_METHOD("get_min", "name"), &BoardProperty::get_min);
	ClassDB::bind_method(D_METHOD("set_max", "name", "max"), &BoardProperty::set_max);
	ClassDB::bind_method(D_METHOD("get_max", "name"), &BoardProperty::get_max);

	ClassDB::bind_method(D_METHOD("set_range", "name", "min", "max"), &BoardProperty::set_range);

	ClassDB::bind_method(D_METHOD("get_final", "name"), &BoardProperty::get_final);
}
