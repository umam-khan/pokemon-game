#include "Trainer.h"
#include "Pokemon.h"
#include "Item.h"
#include "Move.h" // Include Move.h to access the full definition of the Move class
#include <iostream>
#include <limits>

Trainer::Trainer(std::string name) : name(name) {}

void Trainer::catchPokemon(std::shared_ptr<Pokemon> wildPokemon) {
    if (team.size() < 6) {
        team.push_back(wildPokemon);
        std::cout << name << " caught " << wildPokemon->getName() << "!\n";
    }
}

void Trainer::useItem(std::shared_ptr<Item> item, std::shared_ptr<Pokemon> target) {
    item->use(target);
}

void Trainer::battle(Trainer &opponent) {
    std::cout << name << " is battling " << opponent.name << "!\n";

    auto myPokemon = team.front();
    auto opponentPokemon = opponent.team.front();

    while (myPokemon->getStat("health") > 0 && opponentPokemon->getStat("health") > 0) {
        myPokemon->handleStatusEffects();
        if (myPokemon->getStat("health") <= 0) break;

        opponentPokemon->handleStatusEffects();
        if (opponentPokemon->getStat("health") <= 0) break;

        // Trainer 1's turn
        std::cout << "\n" << name << "'s turn:\n";
        std::vector<std::shared_ptr<Move>> myMoves = myPokemon->getMoves();
        for (size_t i = 0; i < myMoves.size(); ++i) {
            std::cout << i + 1 << ". " << myMoves[i]->getName() << " (Power: " << myMoves[i]->getPower() << ")\n";
        }
        int moveChoice;
        std::cout << "Choose a move: ";
        std::cin >> moveChoice;
        moveChoice--;  // To match vector index

        if (moveChoice >= 0 && moveChoice < myMoves.size()) {
            myPokemon->attackOpponent(*opponentPokemon, myMoves[moveChoice]);
            if (opponentPokemon->getStat("health") <= 0) {
                std::cout << opponentPokemon->getName() << " fainted!\n";
                myPokemon->gainExperience(10);
                break;
            }
        }

        if (opponentPokemon->getStat("health") > 0) {
            // Trainer 2's turn
            std::cout << "\n" << opponent.name << "'s turn:\n";
            std::vector<std::shared_ptr<Move>> opponentMoves = opponentPokemon->getMoves();
            for (size_t i = 0; i < opponentMoves.size(); ++i) {
                std::cout << i + 1 << ". " << opponentMoves[i]->getName() << " (Power: " << opponentMoves[i]->getPower() << ")\n";
            }
            int opponentMoveChoice;
            std::cout << "Choose a move: ";
            std::cin >> opponentMoveChoice;
            opponentMoveChoice--;  // To match vector index

            if (opponentMoveChoice >= 0 && opponentMoveChoice < opponentMoves.size()) {
                opponentPokemon->attackOpponent(*myPokemon, opponentMoves[opponentMoveChoice]);
                std::cout << myPokemon->getName() << "'s current HP: " << myPokemon->getStat("health") << "/" << myPokemon->getStat("maxHealth") << "\n";
                if (myPokemon->getStat("health") <= 0) {
                    std::cout << myPokemon->getName() << " fainted!\n";
                    opponentPokemon->gainExperience(10);
                    break;
                }
            }
        }
    }

    if (myPokemon->getStat("health") > 0) {
        std::cout << name << " wins the battle!\n";
        myPokemon->gainExperience(10); // Automatically level up if battle is won
    } else {
        std::cout << opponent.name << " wins the battle!\n";
    }
}

std::vector<std::shared_ptr<Pokemon>> Trainer::getTeam() const {
    return team;
}
