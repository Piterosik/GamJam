#include "Wall.hpp"
Wall::Wall()
{

}
void Wall::init(int _size_x,int _size_y,const std::string & _pathBackgroundTexture)
{
    m_size_x = _size_x;
    m_size_y = _size_y;

    m_tiles = new Tile * [m_size_x];///liczba kolumn
    for(int i=0;i<m_size_x;i++)
    {
        m_tiles[i] = new Tile[_size_y]; ///liczba wierszy
    }
    for(int i=0;i<m_size_x;i++)
    {
        for(int j=0;j<m_size_y;j++)
        {
            m_tiles[i][j].init(i*64,j*64,_pathBackgroundTexture);
        }
    }
    std::cout << m_size_x <<std::endl;
    int numberOfObstacles = ( std::rand() % 90 ) + 0;
    for(int i = 0; i < numberOfObstacles;i++)
    {
        int random_X =( std::rand() % m_size_x ) + 0;
        int random_Y =( std::rand() % m_size_y ) + 0;
        Obstacle * tmp = new Obstacle(random_X*64,random_Y*64,"./data/obstacle.png");
        m_obstaclesList.push_back(tmp);
        std::cout << "New at " << random_X*64 << " " << random_Y*64 << std::endl;
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
    for(std::vector<Obstacle*>::iterator it = m_obstaclesList.begin() ; it != m_obstaclesList.end(); ++it)
    {
        (*it)->draw(_window);
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
    for(std::vector<Obstacle*>::iterator it = m_obstaclesList.begin() ; it != m_obstaclesList.end(); ++it)
    {
        (*it)->update(_miliseconds);
    }
}
