#include <iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Collision.h"
#include "TileMap.h"
#include "Character.h"
#include "Graphic.h"
#include "MainCharacter.h"
#include "Monster.h"

using namespace std;

int main() {

    float mainCharacterMovementSpeed = 2;
    int counter = 0;

    //Graphic Object
    Graphic graphic;
    Collision collision;

    TileMap map;

    //Main Window
    sf::RenderWindow window(sf::VideoMode(1000, 688), "My First Game!");
    window.setFramerateLimit(30);


    graphic.loadTextures();

    //Main Character
    MainCharacter player(2, 15, 5);
    player.sprite.setTexture(graphic.textureBowMan);


    //View - center camera
    sf::View view;
    view.reset(sf::FloatRect(0, 0, 1000, 688));
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    sf::Vector2f position(player.rect.getPosition().x, player.rect.getPosition().y);
    sf::Vector2f viewSize = view.getSize();


    if(!graphic.textureMap.loadFromFile("../Risorse/map1.png")){
        return  EXIT_FAILURE;
    }
    graphic.spriteMap.setTexture(graphic.textureMap);
    graphic.spriteMap.setPosition(0, 0);


    //Monster vector array
    vector<Monster> monsterArray;
    graphic.setMonster();
    monsterArray.push_back(graphic.monsterMummy);
    monsterArray.push_back(graphic.monsterGoblin);
    monsterArray.push_back(graphic.monsterUpGoblin);
    monsterArray.push_back(graphic.monsterBoss);


    //vector<sf::RectangleShape> wallArray;
    //map.setArray(wallArray);

    //Main Loop
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
           if(event.type == sf::Event::Closed)
           {
               window.close();
           }

           if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
           {
               window.close();
           }
        }
        window.clear();


        if(player.rect.getPosition().x > 1000 / 2)
            position.x = player.rect.getPosition().x;
        if(player.rect.getPosition().y > 700 / 2)
            position.y = player.rect.getPosition().y;
        if(player.rect.getPosition().x + viewSize.x/2 > 2000)
            position.x = 1420;
        if(player.rect.getPosition().y + viewSize.y/2 > 5000)
            position.y = 5000;

        //Player view
        view.setCenter(position);
        window.setView(view);
        window.draw(graphic.spriteMap);


        //Draw Background
       // window.draw(graphic.spriteBackGround);

        //Draw Monster
        counter = 0;
        for(auto iter = monsterArray.begin(); iter != monsterArray.end(); iter++)
        {
            monsterArray[counter].update();
            monsterArray[counter].movement();
            window.draw(monsterArray[counter].sprite);
            counter++;
        }

        //Update player
        player.update();
        player.movement();


        //Draw player
        window.draw(player.sprite);





       // mainCharacter.update(); // FIXME unire con updateMove



        window.display();
    }




//    MainCharacter mainCharacter;






    return 0;
}