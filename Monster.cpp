//
// Created by nicole.
//

#include "Monster.h"


Monster::Monster(float speed, int hp, int attackDamage) : Character(speed, hp, attackDamage){
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(200,200);
    rect.setTextureRect(sf::IntRect(counterWalking*32,0,32,32));
}

int Monster::generateRandom(int max) {
    int randomNum = rand();
    float random = (randomNum % max) + 1;
    int myRandom = random;
    return myRandom;
}


void Monster::update() {
    sprite.setPosition(rect.getPosition());
}

void Monster::movement() {

    if(direction == Character::Direction::Up)
    {
        if(moveUp == true)
        {
            rect.move(0, -speed);
            sprite.setTextureRect(sf::IntRect(counterWalking*32, 32*3, 32, 32));
            moveUp = true;
            moveDown = true;
            moveLeft = true;
            moveRight = true;
        }
    }
    else if(direction == Character::Direction::Down)
    {
        if(moveDown == true)
        {
            rect.move(0, speed);
            sprite.setTextureRect(sf::IntRect(counterWalking*32, 0, 32, 32));
            moveUp = true;
            moveDown = true;
            moveLeft = true;
            moveRight = true;
        }
    }
    else if(direction == Character::Direction::Left)
    {
        if(moveLeft == true)
        {
            rect.move(-speed, 0);
            sprite.setTextureRect(sf::IntRect(counterWalking*32, 32*1, 32, 32));
            moveUp = true;
            moveDown = true;
            moveLeft = true;
            moveRight = true;
        }
    }
    else if(direction == Character::Direction::Right)
    {
        if(moveRight == true)
        {
            rect.move(speed, 0);
            sprite.setTextureRect(sf::IntRect(counterWalking*32, 32*2, 32, 32));
            moveUp = true;
            moveDown = true;
            moveLeft = true;
            moveRight = true;
        }
    }
    else
        {
            //no movement
        }


    counterWalking++;
    if(counterWalking == 3){
        counterWalking = 0;
    }

    counter++;
    if(counter >= movementLength)
    {
        direction = static_cast<Direction >(generateRandom(5));
        counter = 0;
    }
}


