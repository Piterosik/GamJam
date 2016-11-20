#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "./Wall/Wall.hpp"
#include "../TexturesManager/TexturesManager.hpp"

class Hallway
{
    public:
        Hallway();
        virtual ~Hallway();
        void draw(sf::RenderWindow & _window);
        void update( int _milseconds);
    protected:
    private:
        int m_currentWall;///0 - sufit, 1 - prawa sciana,2 -podloga,3 - lewa sciana
        Wall *floor;
        Wall *ceiling;
        Wall * LWall,*RWall;

};

#endif // HALLWAY_HPP
