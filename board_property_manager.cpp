/* board_property.cpp */

#include "board_property_manager.h"

bool BoardPropertyManager::has(StringName name) {
	return _data.has(name);
}

void BoardPropertyManager::insert(StringName name, Variant var, Variant low, Variant upp, Array extend) {
	ERR_FAIL_COND_MSG(has(name), vformat("Board Property Manager has alerady had %s property!", name));
	_data[name] = BoardPropertyProcessor(var, low, upp, extend);
}

void BoardPropertyManager::set_full(StringName name, Variant var, Variant low, Variant upp, Array extend) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property Manager has not %s property!", name));
	_data[name] = BoardPropertyProcessor(var, low, upp, extend);
}

void BoardPropertyManager::set_base(StringName name, BoardProperty& base) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property Manager has not %s property!", name));
	_data[name].base = base;
}

BoardPropertyManager::BoardProperty BoardPropertyManager::get_base(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), BoardProperty(), vformat("Board Property Manager has not %s property!", name));
	return _data[name].base;
}


void BoardPropertyManager::set_var(StringName name, Variant var) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property Manager has not %s  property!", name));
	_data[name].base.var = var;
}

Variant BoardPropertyManager::get_var(StringName name) {
	return get_base(name).get_var();
}


void BoardPropertyManager::set_low(StringName name, Variant low) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property Manager has not %s  property!", name));
	_data[name].base.low = low;
}

Variant BoardPropertyManager::get_low(StringName name) {
	return get_base(name).get_low();
}

void BoardPropertyManager::set_upp(StringName name, Variant upp) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property Manager has not %s property!", name));
	_data[name].base.upp = upp;
}

Variant BoardPropertyManager::get_upp(StringName name) {
	return get_base(name).get_upp();
}

void BoardPropertyManager::increase_var(StringName name, Variant increasement) {
	set_var(name, Variant::evaluate(Variant::OP_ADD, get_var(name), increasement));
}

void BoardPropertyManager::as_low(StringName name) {
	set_var(name, get_final_low(name));
}

void BoardPropertyManager::as_upp(StringName name) {
	set_var(name, get_final_upp(name));
}

bool BoardPropertyManager::is_low(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), false, vformat("Board Property Manager has not %s property!", name));
	return _data[name].base.is_low();
}

bool BoardPropertyManager::is_upp(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), false, vformat("Board Property Manager has not %s property!", name));
	return _data[name].base.is_upp();
}

void BoardPropertyManager::set_range(StringName name, Variant low, Variant upp) {
	ERR_FAIL_COND_MSG(!has(name), vformat("Board Property Manager has not %s property!", name));
	_data[name].base.low = low;
	_data[name].base.upp = upp;
}

BoardPropertyManager::BoardProperty BoardPropertyManager::get_final(StringName name) {
	ERR_FAIL_COND_V_MSG(!has(name), BoardProperty(), vformat("Board Property Manager has not %s property!", name));
	return _data[name].get_final();
}

Variant BoardPropertyManager::get_final_var(StringName name) {
	return get_final(name).get_var();
}

Variant BoardPropertyManager::get_final_low(StringName name) {
	return get_final(name).get_low();
}

Variant BoardPropertyManager::get_final_upp(StringName name) {
	return get_final(name).get_upp();
}

void BoardPropertyManager::_bind_methods() {
	ClassDB::bind_method(D_METHOD("has", "name"), &BoardPropertyManager::has);

	ClassDB::bind_method(D_METHOD("insert", "name", "var", "low", "upp", "extends"), &BoardPropertyManager::insert, Variant(), Variant(), Variant(), Array());
	ClassDB::bind_method(D_METHOD("set_full", "name", "base", "low", "upp", "extends"), &BoardPropertyManager::set_full, Array());

	//ClassDB::bind_method(D_METHOD("set_base", "name", "base"), &BoardPropertyManager::set_base);
	//ClassDB::bind_method(D_METHOD("get_base", "name"), &BoardPropertyManager::get_base);
	ClassDB::bind_method(D_METHOD("set_var", "name", "var"), &BoardPropertyManager::set_var);
	ClassDB::bind_method(D_METHOD("get_var", "name"), &BoardPropertyManager::get_var);
	ClassDB::bind_method(D_METHOD("set_low", "name", "low"), &BoardPropertyManager::set_low);
	ClassDB::bind_method(D_METHOD("get_low", "name"), &BoardPropertyManager::get_low);
	ClassDB::bind_method(D_METHOD("set_upp", "name", "upp"), &BoardPropertyManager::set_upp);
	ClassDB::bind_method(D_METHOD("get_upp", "name"), &BoardPropertyManager::get_upp);

	ClassDB::bind_method(D_METHOD("increase_var", "name", "increasement"), &BoardPropertyManager::increase_var);

	ClassDB::bind_method(D_METHOD("as_low", "name"), &BoardPropertyManager::as_low);
	ClassDB::bind_method(D_METHOD("as_upp", "name"), &BoardPropertyManager::as_upp);

	ClassDB::bind_method(D_METHOD("is_low", "name"), &BoardPropertyManager::is_low);
	ClassDB::bind_method(D_METHOD("is_upp", "name"), &BoardPropertyManager::is_upp);

	ClassDB::bind_method(D_METHOD("set_range", "name", "low", "upp"), &BoardPropertyManager::set_range);

	//ClassDB::bind_method(D_METHOD("get_final", "name"), &BoardPropertyManager::get_final);
	ClassDB::bind_method(D_METHOD("get_final_var", "name"), &BoardPropertyManager::get_final_var);
	ClassDB::bind_method(D_METHOD("get_final_low", "name"), &BoardPropertyManager::get_final_low);
	ClassDB::bind_method(D_METHOD("get_final_upp", "name"), &BoardPropertyManager::get_final_upp);
}
