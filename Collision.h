//
// Created by nicole.
//

#ifndef GAME0_COLLISION_H
#define GAME0_COLLISION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Graphic.h"
#include "MainCharacter.h"
#include "Monster.h"

class Collision {
public:
    void collisionMap(MainCharacter &mainCharacter, std::vector<sf::RectangleShape> &mapArray);
};


#endif //GAME0_COLLISION_H
