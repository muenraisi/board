/* board_property.cpp */

#include "board_property.h"

bool BoardPropertyManager::has(StringName name) {
	if (_data.find(name) == _data.end()) {
		return false;
	} else {
		return true;
	}
}

void BoardPropertyManager::insert(StringName name, Variant var, Variant min, Variant max, Array extend) {
	ERR_FAIL_COND_MSG(has(name), vformat("Board Property has alerady had %s property!", name));
	_data[name] = BoardPropertyProcessor(var, min, max, extend);
}

void BoardPropertyManager::set_full(StringName name, Variant var, Variant min, Variant max, Array extend) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name] =  BoardPropertyProcessor(var, min, max, extend);
}

void BoardPropertyManager::set_base(StringName name, BoardProperty& base) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name].base = base;
}

BoardPropertyManager::BoardProperty BoardPropertyManager::get_base(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), BoardProperty(), vformat("Board Property has not %s property!", name));
	return _data[name].base;
}


void BoardPropertyManager::set_var(StringName name, Variant var) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s  property!", name));
	_data[name].base.var = var;
}

Variant BoardPropertyManager::get_var(StringName name) {
	return get_base(name).var;
}


void BoardPropertyManager::set_min(StringName name, Variant min) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s  property!", name));
	_data[name].base.min = min;
}

Variant BoardPropertyManager::get_min(StringName name) {
	return get_base(name).min;
}

void BoardPropertyManager::set_max(StringName name, Variant max) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name].base.max = max;
}

Variant BoardPropertyManager::get_max(StringName name) {
	return get_base(name).max;
}

void BoardPropertyManager::set_range(StringName name, Variant min, Variant max) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property has not %s property!", name));
	_data[name].base.min = min;
	_data[name].base.max = max;
}

BoardPropertyManager::BoardProperty BoardPropertyManager::get_final(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), BoardProperty(), vformat("Board Property has not %s property!", name));
	return _data[name].get_final();
}

Variant BoardPropertyManager::get_final_var(StringName name) {
	return get_final(name).var;
}

Variant BoardPropertyManager::get_final_min(StringName name) {
	return get_final(name).min;
}

Variant BoardPropertyManager::get_final_max(StringName name) {
	return get_final(name).max;
}

void BoardPropertyManager::_bind_methods() {
	ClassDB::bind_method(D_METHOD("has", "name"), &BoardPropertyManager::has);

	ClassDB::bind_method(D_METHOD("insert", "name", "base", "min", "max", "extends"), &BoardPropertyManager::insert, Variant(), Variant(), Variant(), Array());
	ClassDB::bind_method(D_METHOD("set_full", "name", "base", "min", "max", "extends"), &BoardPropertyManager::set_full, Array());

	//ClassDB::bind_method(D_METHOD("set_base", "name", "base"), &BoardPropertyManager::set_base);
	//ClassDB::bind_method(D_METHOD("get_base", "name"), &BoardPropertyManager::get_base);
	ClassDB::bind_method(D_METHOD("set_var", "name", "var"), &BoardPropertyManager::set_var);
	ClassDB::bind_method(D_METHOD("get_var", "name"), &BoardPropertyManager::get_min);
	ClassDB::bind_method(D_METHOD("set_min", "name", "min"), &BoardPropertyManager::set_min);
	ClassDB::bind_method(D_METHOD("get_min", "name"), &BoardPropertyManager::get_min);
	ClassDB::bind_method(D_METHOD("set_max", "name", "max"), &BoardPropertyManager::set_max);
	ClassDB::bind_method(D_METHOD("get_max", "name"), &BoardPropertyManager::get_max);

	ClassDB::bind_method(D_METHOD("set_range", "name", "min", "max"), &BoardPropertyManager::set_range);

	//ClassDB::bind_method(D_METHOD("get_final", "name"), &BoardPropertyManager::get_final);
	ClassDB::bind_method(D_METHOD("get_final_var", "name"), &BoardPropertyManager::get_final_var);
	ClassDB::bind_method(D_METHOD("get_final_min", "name"), &BoardPropertyManager::get_final_min);
	ClassDB::bind_method(D_METHOD("get_final_max", "name"), &BoardPropertyManager::get_final_max);
}
