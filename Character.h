//
// Created by nicole.
//

#ifndef GAME_PROVA2_CHARACTER_H
#define GAME_PROVA2_CHARACTER_H

#include <SFML/Graphics.hpp>

class Character {
public:

    enum class Direction{
        Up, Down, Left, Right
    };


    Character(float sp, int hp, int attack) : speed(sp), hp(hp), attackDamage(attack){}; //costruttore
    virtual ~Character(){}

    virtual void movement() = 0;

    Direction getDirection() const;
    void setDirection(Direction direction);


    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;

    bool moveUp = true;
    bool moveDown = true;
    bool moveLeft = true;
    bool moveRight = true;

protected:
    float speed;

    Direction direction = Direction ::Down;
    int hp;
    int attackDamage;
    int counterWalking = 0;
    int counter = 0;


};


#endif //GAME_PROVA2_CHARACTER_H
