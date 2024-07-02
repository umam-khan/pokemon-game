#include "Move.h"
#include "Pokemon.h"
#include <iostream>

Move::Move(std::string name, std::string type, int power, int accuracy, std::string category, std::string effect)
    : name(name), type(type), power(power), accuracy(accuracy), category(category), effect(effect) {}

void Move::applyEffect(Pokemon &target) {
    if (effect == "poison") {
        target.applyStatusEffect("poison");
    } else if (effect == "paralysis") {
        target.applyStatusEffect("paralysis");
    }
    std::cout << name << " is used on " << target.getName() << "!\n";
}
