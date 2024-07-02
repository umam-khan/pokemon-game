#ifndef POKEBALL_H
#define POKEBALL_H

#include "Item.h"
#include "Pokemon.h"
#include <memory>

class Pokeball : public Item {
private:
    float catchRate;

public:
    Pokeball(std::string name, float catchRate);

    bool catchPokemon(std::shared_ptr<Pokemon> target);
};

#endif // POKEBALL_H
