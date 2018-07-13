//
// Created by nicole.
//

#ifndef GAME_PROVA2_MONSTER_H
#define GAME_PROVA2_MONSTER_H

#include "Character.h"


class Monster: public Character {

public:

    Monster(float speed, int hp, int attackDamage);




    void update();
    void movement() override;
    int generateRandom(int max);

private:
    int movementLength = 30;

};


#endif //GAME_PROVA2_MONSTER_H
