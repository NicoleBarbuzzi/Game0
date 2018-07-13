//
// Created by nicole.
//

#include "Collision.h"

void Collision::collisionMap(MainCharacter &mainCharacter, std::vector<sf::RectangleShape> &mapArray) {
    for (auto iter = mapArray.begin(); iter != mapArray.end(); iter++){
        if(mainCharacter.rect.getGlobalBounds().intersects(iter->getGlobalBounds())){
            if(mainCharacter.getDirection() == Character::Direction::Up){
                mainCharacter.moveUp = false;
                mainCharacter.rect.move(0, 1 + mainCharacter.coll);
                mainCharacter.setDirection(Character::Direction::Up);

            }else if(mainCharacter.getDirection() == Character::Direction::Down){
                mainCharacter.moveDown = false;
                mainCharacter.rect.move(0, -1 - mainCharacter.coll);
                mainCharacter.setDirection(Character::Direction::Down);

            }else if(mainCharacter.getDirection() == Character::Direction::Left){
                mainCharacter.moveLeft = false;
                mainCharacter.rect.move(1 + mainCharacter.coll, 0);
                mainCharacter.setDirection(Character::Direction::Left);

            }else if(mainCharacter.getDirection() == Character::Direction::Right){
                mainCharacter.moveRight = false;
                mainCharacter.rect.move(-1 - mainCharacter.coll, 0);
                mainCharacter.setDirection(Character::Direction::Right);
            }
        }
    }
}