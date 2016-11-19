#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "../Game.hpp"
#include "../TexturesManager/TexturesManager.hpp"


class Player
{
    public:
        Player();
        virtual ~Player();
        void draw(sf::RenderWindow & _window);
        void update( int _milseconds);
    protected:
    private:
    sf::Sprite m_player;
    int m_pos_x,m_pos_y;
    int m_lastFrame;
    int m_frame;
};

#endif // PLAYER_HPP
