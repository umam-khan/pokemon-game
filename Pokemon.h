#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include <memory>

class Move;

class Pokemon {
private:
    std::string name;
    std::string type;
    int health;
    int maxHealth;
    int attack;
    int defense;
    int specialAttack;
    int specialDefense;
    int speed;
    int level;
    int experience;
    std::vector<std::shared_ptr<Move>> moves;
    bool isWild;
    bool isPoisoned;
    bool isParalyzed;

public:
    Pokemon(std::string name, std::string type, int health, int attack, int defense, 
            int specialAttack, int specialDefense, int speed, int level, bool isWild);

    void attackOpponent(Pokemon &opponent, std::shared_ptr<Move> move);
    void takeDamage(int damage);
    void gainExperience(int exp);
    void levelUp();
    void learnMove(std::shared_ptr<Move> move);
    int getStat(std::string stat) const;
    std::string getName() const;
    void evolve(std::string newName, int newHealth, int newAttack, int newDefense, int newSpecialAttack, int newSpecialDefense, int newSpeed);
    void applyStatusEffect(std::string effect);
    void handleStatusEffects();
    std::vector<std::shared_ptr<Move>> getMoves() const;
};

#endif // POKEMON_H
