//
// Created by nicole.
//

#include "Graphic.h"







int Graphic::loadTextures() {

    //Load Background
    /*if(!textureBackground.loadFromFile("../Risorse/mapOverload.png")){
        return EXIT_FAILURE;
    }
    spriteBackGround.setTexture(textureBackground);
    spriteBackGround.setPosition(0,100);*/


    //load Main Character Boy
    if(!textureBowMan.loadFromFile("../Risorse/complete0.png")){
        return EXIT_FAILURE;
    }

    //load Main Character Girl
    if(!textureKnight.loadFromFile("../Risorse/complete0.png")){
        return EXIT_FAILURE;
    }

    //load Enemies
    if(!textureMonsterMummy.loadFromFile("../Risorse/monster1.png")){
        return EXIT_FAILURE;
    }
    if(!textureMonsterGoblin.loadFromFile("../Risorse/monster2.png")){
        return EXIT_FAILURE;
    }
    if(!textureMonsterUpGoblin.loadFromFile("../Risorse/monster3.png")){
        return EXIT_FAILURE;
    }
    if(!textureMonsterBoss.loadFromFile("../Risorse/boss.png")){
        return EXIT_FAILURE;
    }


}

void Graphic::setMonster() {

    monsterMummy.rect.setPosition(500,100);
    monsterMummy.sprite.setScale(0.9, 0.9);
    monsterMummy.sprite.setTexture(textureMonsterMummy);

    monsterGoblin.rect.setPosition(500,300);
    monsterGoblin.sprite.setScale(0.9, 0.9);
    monsterGoblin.sprite.setTexture(textureMonsterGoblin);

    monsterUpGoblin.rect.setPosition(400,400);
    monsterUpGoblin.sprite.setScale(0.9, 0.9);
    monsterUpGoblin.sprite.setTexture(textureMonsterUpGoblin);

    monsterBoss.rect.setPosition(500,200);
    monsterBoss.sprite.setScale(0.9, 0.9);
    monsterBoss.sprite.setTexture(textureMonsterBoss);

}
