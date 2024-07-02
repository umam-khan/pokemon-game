#include "Pokemon.h"
#include "Move.h"
#include "Item.h"
#include "Trainer.h"
#include "Pokeball.h"
#include <iostream>
#include <memory>
#include <string>

int main() {
    std::string trainer1Name, trainer2Name;
    std::cout << "Enter name for Trainer 1: ";
    std::getline(std::cin, trainer1Name);
    std::cout << "Enter name for Trainer 2: ";
    std::getline(std::cin, trainer2Name);

    // Creating Trainers
    Trainer trainer1(trainer1Name);
    Trainer trainer2(trainer2Name);

    // Creating Pokémon
    auto charmander = std::make_shared<Pokemon>("Charmander", "Fire", 200, 52, 43, 60, 50, 65, 5, true);
    auto staryu = std::make_shared<Pokemon>("Staryu", "Water", 200, 45, 55, 70, 55, 85, 5, true);

    // Creating Moves
    auto ember = std::make_shared<Move>("Ember", "Fire", 40, 100, "Special", "poison");
    auto scratch = std::make_shared<Move>("Scratch", "Normal", 40, 100, "Physical");
    auto flamethrower = std::make_shared<Move>("Flamethrower", "Fire", 90, 100, "Special");
    auto dragonClaw = std::make_shared<Move>("Dragon Claw", "Dragon", 80, 100, "Physical");

    auto waterGun = std::make_shared<Move>("Water Gun", "Water", 40, 100, "Special");
    auto tackle = std::make_shared<Move>("Tackle", "Normal", 40, 100, "Physical");
    auto bubbleBeam = std::make_shared<Move>("Bubble Beam", "Water", 65, 100, "Special");
    auto swift = std::make_shared<Move>("Swift", "Normal", 60, 100, "Special");

    // Learning Moves
    charmander->learnMove(ember);
    charmander->learnMove(scratch);
    charmander->learnMove(flamethrower);
    charmander->learnMove(dragonClaw);

    staryu->learnMove(waterGun);
    staryu->learnMove(tackle);
    staryu->learnMove(bubbleBeam);
    staryu->learnMove(swift);

    // Adding Pokémon to Trainers
    trainer1.catchPokemon(charmander);
    trainer2.catchPokemon(staryu);

    // Start Battle
    trainer1.battle(trainer2);

    return 0;
}
