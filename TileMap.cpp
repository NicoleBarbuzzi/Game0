//
// Created by nicole.
//


#include "SFML/Graphics.hpp"
#include "TileMap.h"


bool TileMap::load(std::string tileName, sf::Vector2u tileSize, const int *tiles,unsigned int width, unsigned int height) {

    //load the tileset texture
    if(!m_tileset.loadFromFile(tileName))
        return false;


    //resize the vertex array to fit the level size
    m_vertice.setPrimitiveType(sf::Quads);
    m_vertice.resize(width * height * 4);


    //populate the vertx array, with one quad per title
    for(unsigned int i = 0; i < width; ++i)
        for(unsigned int j = 0; j < height; ++j)
        {
            //get the current tile number
            int tileNumber = tiles[i + j * width];


            //find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x/tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x/tileSize.x);

            //get a pointer to the current tile's quad
            sf::Vertex *quad = &m_vertice[(i + j * width) * 4];


            //define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);


            //define its 4 textures coordinates
            quad[0].texCoords= sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

        }
        return  true;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    //apply the tranform
    states.transform *= getTransform();

    //apply the tileset texture
    states.texture = &m_tileset;

    //draw the vertex array
    target.draw(m_vertice, states);
}

