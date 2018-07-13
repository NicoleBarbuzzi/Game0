//
// Created by nicole.
//

#ifndef GAME0_WEAPON_H
#define GAME0_WEAPON_H


#include <string>

class Weapon {
public:

    Weapon(int damage, std::string type) : attackDamage(damage), type(type){}
    virtual ~Weapon(){};

    int getAttackDamage() const {
        return attackDamage;
    }

    void setAttackDamage(int attackDamage) {
        Weapon::attackDamage = attackDamage;
    }


    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        Weapon::type = type;
    }


protected:
    int attackDamage;
    std::string type;
};


#endif //GAME0_WEAPON_H
