#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

class Pokemon;

class Item {
private:
    std::string name;
    std::string type;
    std::string effect;

public:
    Item(std::string name, std::string type, std::string effect);

    void use(std::shared_ptr<Pokemon> target);
};

#endif // ITEM_H
