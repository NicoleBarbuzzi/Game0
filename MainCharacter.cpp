//
// Created by nicole.
//

#include "MainCharacter.h"

MainCharacter ::MainCharacter(float speed, int hp, int attackDamage) : Character(speed, hp, attackDamage){

    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(500,350);
    rect.setFillColor(sf::Color::Transparent);
    sprite.setPosition(rect.getPosition());
    sprite.setTextureRect(sf::IntRect(0,0,29.5,29.5));

}

void MainCharacter::update() {
    sprite.setPosition(rect.getPosition());

}

void MainCharacter::movement() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && moveUp)
    {
        rect.move(0, -speed);
        direction = Character::Direction ::Up;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;
        sprite.setTextureRect(sf::IntRect(counterWalking*29.5, 29.5*3,29.5,29.5));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && moveDown)
    {
        rect.move(0,speed);
        direction = Character::Direction ::Down;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;
        sprite.setTextureRect(sf::IntRect(counterWalking*29.5, 0, 29.5,29.5));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveLeft)
    {
        rect.move(-speed,0);
        direction = Character::Direction ::Left;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;
        sprite.setTextureRect(sf::IntRect((counterWalking*29.5)+(29.5*9), 0, 29.5, 29.5));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveRight)
    {
        rect.move(speed,0);
        direction = Character::Direction ::Right;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;
        sprite.setTextureRect(sf::IntRect((counterWalking*29.5)+(29.5*9), 29.5*3, 29.5,29.5));
    }

    counterWalking++;
    if(counterWalking==2)
    {
        counterWalking=0;
    }

}