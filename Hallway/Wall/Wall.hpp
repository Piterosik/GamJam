#ifndef WALL_HPP
#define WALL_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include "./Tile.hpp"
#include "../../Obstacle/Obstacle.hpp"
class Wall
{
    public:
        Wall();
        void init(int _size_x,int _size_y,const std::string & _pathBackgroundTexture);
        virtual ~Wall();
        void draw(sf::RenderWindow & _window);
        void update(int _miliseconds);
    protected:
    private:
        Tile ** m_tiles;
        int m_size_x;
        int m_size_y;
        std::vector<Obstacle*> m_obstaclesList;
};

#endif // WALL_HPP
