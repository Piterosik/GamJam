#include "Hallway.hpp"

Hallway::Hallway()
{
    m_currentWall = 2;///0 - sufit, 1 - prawa sciana,2 -podloga,3 - lewa sciana
    floor.init(6,90,"./data/tileHallway.png");
    ceiling.init(6,90,"./data/tileHallway2.png");
    LWall.init(6,90,"./data/tileHallway2.png");
    RWall.init(6,90,"./data/tileHallway2.png");
}

Hallway::~Hallway()
{

}
void Hallway::draw(sf::RenderWindow & _window)
{
    switch(m_currentWall)
    {
        case 0:
            ceiling.draw(_window);
        break;
        case 1:
            RWall.draw(_window);
        break;
        case 2:
            floor.draw(_window);
        break;
        case 3:
            LWall.draw(_window);
        break;
    }
}
void Hallway::update( int _milseconds)
{
    switch(m_currentWall)
    {
        case 0:
            ceiling.update(_milseconds);
        break;
        case 1:
            RWall.update(_milseconds);
        break;
        case 2:
            floor.update(_milseconds);
        break;
        case 3:
            LWall.update(_milseconds);
        break;
    }
}
