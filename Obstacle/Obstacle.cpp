#include "Obstacle.hpp"

Obstacle::Obstacle(int _position_x,int _position_y,std::string _path)
{
    m_position_x = _position_x;
    m_position_y = _position_y;

    m_sprite.setPosition(m_position_x,m_position_y);
    auto handle = TexturesManager::getHandleTo(_path);
    m_sprite.setTexture(TexturesManager::getTexture(handle));
    m_size_x = m_sprite.getGlobalBounds().width;
    m_size_y = m_sprite.getGlobalBounds().height;
}

Obstacle::~Obstacle()
{
    //dtor
}
bool Obstacle::isCollision(float _player_x,float _player_y)
{
    if( _player_x >= m_position_x && _player_x >= m_position_x + m_size_x)
    {
        if(_player_y >= m_position_y && _player_y >= m_position_y + m_size_y)return true;
    }
}
void Obstacle::draw(sf::RenderWindow & _window)
{
    _window.draw(m_sprite);
}
void Obstacle::update(int _miliseconds)
{

}
