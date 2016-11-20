#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../TexturesManager/TexturesManager.hpp"
class Obstacle
{
    public:
        Obstacle(int _position_x,int _position_y,std::string _path);
        virtual ~Obstacle();
        bool isCollision(float _player_x,float _player_y);
        void draw(sf::RenderWindow _window);
        void update(int _miliseconds);
    protected:
    private:
        int m_position_x;
        int m_position_y;
        sf::Sprite m_sprite;
};

#endif // OBSTACLE_HPP
