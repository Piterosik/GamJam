#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../../TexturesManager/TexturesManager.hpp"
class Tile
{
    public:
        Tile();
        void init(int pos_x,int pos_y,const std::string &_path);
        virtual ~Tile();
        void draw(sf::RenderWindow & _window);
        void update(int _miliseconds);
    private:
        sf::Sprite m_sprite;
};

#endif // TILE_HPP
