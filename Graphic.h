//
// Created by nicole.
//

#ifndef GAME0_GRAPHICS_H
#define GAME0_GRAPHICS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "MainCharacter.h"
#include "Monster.h"


class Graphic {
public:

    Graphic(float speed = 1, int hp = 3, int attack = 5) :monsterMummy(speed, hp, attack), monsterGoblin(speed, hp, attack),
                                                            monsterUpGoblin(speed, hp, attack), monsterBoss(speed, hp, attack) {}
    ~Graphic(){};

    int loadTextures();
    void setMonster();



    //Textures
    sf::Texture textureMap;
    sf::Texture textureBowMan;
    sf::Texture textureKnight;
    sf::Texture textureMonsterMummy;
    sf::Texture textureMonsterGoblin;
    sf::Texture textureMonsterUpGoblin;
    sf::Texture textureMonsterBoss;


    //Sprites
    sf::Sprite spriteMap;

    //Monster
    Monster monsterMummy;
    Monster monsterGoblin;
    Monster monsterUpGoblin;
    Monster monsterBoss;






};


#endif //GAME0_GRAPHICS_H
