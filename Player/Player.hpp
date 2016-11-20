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
    public:
        sf::Sprite m_player;
        float m_pos_x,m_pos_y;
        int m_lastFrame;
        int m_frame;
        int m_elapsedTime;
        float m_speed;
        float m_rotation;
        std::size_t m_textureHandles[3];
};

#endif // PLAYER_HPP
