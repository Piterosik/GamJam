#include "Wall.hpp"
Wall::Wall()
{

}
void Wall::init(int _size_x,int _size_y)
{
    m_size_x = _size_x;
    m_size_y = _size_y;

    m_tiles = new Tile * [m_size_x];///liczba wierszy
    for(int i=0;i<m_size_x;i++)
    {
        m_tiles[i] = new Tile[_size_y]; //przydzielenie dla każdego wiersza po _size_x komórek
    }
    for(int i=0;i<m_size_x;i++)
    {
        for(int j=0;j<m_size_y;j++)
        {
            m_tiles[i][j].init(i*64,j*64,"./data/tileguguHallway.png");
        }
    }
}

Wall::~Wall()
{
}
void Wall::draw(sf::RenderWindow & _window)
{
    for(int i=0;i<m_size_x;i++)
    {
        for(int j=0;j<m_size_y;j++)
        {
            m_tiles[i][j].draw(_window);
        }
    }
}
void Wall::update(int _miliseconds)
{
    for(int i=0;i<m_size_x;i++)
    {
        for(int j=0;j<m_size_y;j++)
        {
            m_tiles[i][j].update(_miliseconds);
        }
    }
}
