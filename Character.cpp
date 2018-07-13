//
// Created by nicole.
//

#include "Character.h"


Character::Direction Character::getDirection() const {
    return direction;
}

void Character::setDirection(Character::Direction direction) {
    Character::direction = direction;
}