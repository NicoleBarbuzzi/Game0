//
// Created by nicole.
//

#ifndef GAME_PROVA2_MAINCHARACTER_H
#define GAME_PROVA2_MAINCHARACTER_H

#include "Character.h"
#include <SFML/Graphics.hpp>
#include "Graphic.h"


class MainCharacter: public Character{
public:

    MainCharacter(float speed, int hp, int attackDamage); //costruttore

    void update();

    void movement() override;

    int coll = 0; //speed of collision

    bool bowMan = false;
    bool swordMan = false;


};

//mappa random o tile, collisioni su mainCharacter, mostri per ora no
//collegare mainCharacter ad un'arma


#endif //GAME_PROVA2_MAINCHARACTER_H
