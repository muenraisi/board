#include "board_damage_computer.h"


void BoardDamageComputer::set_attack(float power, int population) {
	_attack = Attack(power, population);
	_set_attack_flag = true;
}

void BoardDamageComputer::set_defend(float armor) {
	_defend = Defend(armor);
	_set_defend_flag = true;
}

float BoardDamageComputer::compute() const {
	ERR_FAIL_COND_V_MSG(!_set_attack_flag, 0, "Unset attack info");
	ERR_FAIL_COND_V_MSG(!_set_defend_flag, 0, "Unset defend info");
	float damage = (_attack.power - _defend.armor) * _attack.population;
	return damage;
}

void BoardDamageComputer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("compute"), &BoardDamageComputer::compute);
	ClassDB::bind_method(D_METHOD("set_attack", "power","population"), &BoardDamageComputer::set_attack);
	ClassDB::bind_method(D_METHOD("set_defend", "armor"), &BoardDamageComputer::set_defend);
	
}

