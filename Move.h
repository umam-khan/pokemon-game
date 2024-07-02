#ifndef MOVE_H
#define MOVE_H

#include <string>

class Pokemon;

class Move {
private:
    std::string name;
    std::string type;
    int power;
    int accuracy;
    std::string category;
    std::string effect;

public:
    Move(std::string name, std::string type, int power, int accuracy, std::string category, std::string effect = "");

    void applyEffect(Pokemon &target);
    std::string getName() const { return name; }
    int getPower() const { return power; }
    int getAccuracy() const { return accuracy; }
};

#endif // MOVE_H
