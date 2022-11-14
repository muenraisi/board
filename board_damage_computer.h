#ifndef BOARD_DAMAGE_COMPUTER_H
#define BOARD_DAMAGE_COMPUTER_H

#include "core/object/ref_counted.h"

class BoardDamageComputer : public RefCounted {
	GDCLASS(BoardDamageComputer, RefCounted);

	struct Attack {
		float power;
		float population;

		Attack() :
				power(0), population(0){};
		Attack(float power_, float population_) :
				power(power_), population(population_){};
	};
	struct Defend {
		float armor;

		Defend() :
				armor(0){};
		Defend(float armor_) :
				armor(armor_){};
	};

private:
	Attack _attack;
	Defend _defend;
	bool _set_attack_flag = false;
	bool _set_defend_flag = false;

protected:
	static void _bind_methods();

public:
	void set_attack(float power, int population);
	void set_defend(float armor);
	float compute() const;

	BoardDamageComputer(){};
};

#endif
