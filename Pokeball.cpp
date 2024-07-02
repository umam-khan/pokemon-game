#include "Pokeball.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Pokeball::Pokeball(std::string name, float catchRate) 
    : Item(name, "Pokeball", ""), catchRate(catchRate) {
    std::srand(std::time(0)); // Seed for random number generation
}

bool Pokeball::catchPokemon(std::shared_ptr<Pokemon> target) {
    float catchChance = catchRate * ((float)target->getStat("maxHealth") / (float)target->getStat("health")) * (1.0f / target->getStat("level"));
    if (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) < catchChance) {
        std::cout << target->getName() << " was caught!\n";
        return true;
    } else {
        std::cout << target->getName() << " escaped!\n";
        return false;
    }
}

