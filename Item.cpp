#include "Item.h"
#include "Pokemon.h"
#include <iostream>

Item::Item(std::string name, std::string type, std::string effect) 
    : name(name), type(type), effect(effect) {}

void Item::use(std::shared_ptr<Pokemon> target) {
    if (effect == "heal") {
        target->takeDamage(-20); // Heal 20 health points
    }
    std::cout << name << " used on " << target->getName() << "!\n";
}
