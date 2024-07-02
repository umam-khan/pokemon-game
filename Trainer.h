#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>
#include <memory>

class Pokemon;
class Item;

class Trainer {
private:
    std::string name;
    std::vector<std::shared_ptr<Pokemon>> team;
    std::vector<std::shared_ptr<Item>> inventory;

public:
    Trainer(std::string name);

    void catchPokemon(std::shared_ptr<Pokemon> wildPokemon);
    void useItem(std::shared_ptr<Item> item, std::shared_ptr<Pokemon> target);
    void battle(Trainer &opponent);
    std::vector<std::shared_ptr<Pokemon>> getTeam() const;
};

#endif // TRAINER_H
