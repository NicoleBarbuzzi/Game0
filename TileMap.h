//
// Created by nicole.
//

#ifndef GAME0_TILEMAP_H
#define GAME0_TILEMAP_H

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>


class TileMap : public sf::Drawable, public sf::Transformable {
public:
    int setArray(std::vector<sf::RectangleShape> &mapArray);
    bool load(std::string tileName, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::VertexArray m_vertice;
    sf::Texture m_tileset;

};


#endif //GAME0_TILEMAP_H
