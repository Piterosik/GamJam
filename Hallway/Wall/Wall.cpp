#include "Wall.hpp"
Wall::Wall()
{

}
void Wall::init(int _size_x,int size_y)
{
    m_tiles = new Tile * [m_size_x];///liczba wierszy
    for(int i=0;i<m_size_x;i++)
    {
        m_tiles[i] = new Tile[size_y]; //przydzielenie dla każdego wiersza po _size_x komórek
    }
    m_size_x = _size_x;
    m_size_y = size_y;
    /*for(int i=0;i<m_size_x;i++)
    {
        for(int j=0;j<m_size_y;j++)
        {
            m_tiles[i][j].init(i*64,j*64,"./data/tileguguHallway.png");
        }
    }*/
}

Wall::~Wall()
{
    /*for(int i=0;i<m_size_y;i++)
    {
        delete m_tiles[i];
    }
    delete m_tiles;*/
}
void Wall::draw(sf::RenderWindow & _window)
{
    /*for(int i=0;i<m_size_x;i++)
    {
        for(int j=0;j<m_size_y;j++)
        {
            m_tiles[i][j].draw(_window);
        }
    }*/
}
void Wall::update(int _miliseconds)
{
    /*for(int i=0;i<m_size_x;i++)
    {
        for(int j=0;j<m_size_y;j++)
        {
            m_tiles[i][j].update(_miliseconds);
        }
    }*/
}
