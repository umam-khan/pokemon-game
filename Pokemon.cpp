#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <cstdlib>

Pokemon::Pokemon(std::string name, std::string type, int health, int attack, int defense, 
                 int specialAttack, int specialDefense, int speed, int level, bool isWild)
    : name(name), type(type), health(health), maxHealth(health), attack(attack), defense(defense),
      specialAttack(specialAttack), specialDefense(specialDefense), speed(speed),
      level(level), experience(0), isWild(isWild), isPoisoned(false), isParalyzed(false) {}

void Pokemon::attackOpponent(Pokemon &opponent, std::shared_ptr<Move> move) {
    if (rand() % 100 < move->getAccuracy()) {
        int damage = move->getPower() + (attack + rand() % 10) - opponent.defense;
        damage = (damage < 0) ? 0 : damage; // Ensure damage is not negative
        opponent.takeDamage(damage);
        move->applyEffect(opponent);
        std::cout << name << " used " << move->getName() << " causing " << damage << " damage to " << opponent.getName() << "!\n";
        std::cout << opponent.getName() << "'s current HP: " << opponent.getStat("health") << "/" << opponent.getStat("maxHealth") << "\n";
    } else {
        std::cout << name << "'s attack missed!\n";
    }
}

void Pokemon::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        health = 0;
        std::cout << name << " has fainted!\n";
    }
}

void Pokemon::gainExperience(int exp) {
    experience += exp;
    if (experience >= level * 10 && level < 100) {
        levelUp();
    }
}

void Pokemon::levelUp() {
    if (level < 100) {
        level++;
        health += 5;
        maxHealth += 5;
        attack += 2;
        defense += 2;
        specialAttack += 2;
        specialDefense += 2;
        speed += 1;
        std::cout << name << " leveled up to " << level << "!\n";
    } else {
        std::cout << name << " is already at the maximum level!\n";
    }
}

std::vector<std::shared_ptr<Move>> Pokemon::getMoves() const {
    return moves;
}

void Pokemon::learnMove(std::shared_ptr<Move> move) {
    if (moves.size() < 4) {
        moves.push_back(move);
        std::cout << name << " learned " << move->getName() << "!\n";
    }
}

std::string Pokemon::getName() const {
    return name;
}

int Pokemon::getStat(std::string stat) const {
    if (stat == "health") return health;
    if (stat == "attack") return attack;
    if (stat == "defense") return defense;
    if (stat == "specialAttack") return specialAttack;
    if (stat == "specialDefense") return specialDefense;
    if (stat == "speed") return speed;
    if (stat == "maxHealth") return maxHealth;
    return 0;
}

void Pokemon::applyStatusEffect(std::string effect) {
    if (effect == "poison") {
        isPoisoned = true;
        std::cout << name << " is poisoned!\n";
    } else if (effect == "paralysis") {
        isParalyzed = true;
        std::cout << name << " is paralyzed!\n";
    }
}

void Pokemon::handleStatusEffects() {
    if (isPoisoned) {
        health -= maxHealth / 10;
        std::cout << name << " takes poison damage!\n";
    }

    if (isParalyzed) {
        if (rand() % 2 == 0) {
            std::cout << name << " is fully paralyzed and can't move!\n";
        }
    }
}
