#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "../Game.hpp"
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
        sf::Vector2u m_size;
        std::vector<sf::Sprite*> m_tilesList;
};

#endif // HALLWAY_HPP
