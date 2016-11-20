#include "Tile.hpp"

Tile::Tile()
{

}
void Tile::init(int pos_x,int pos_y,const std::string &_path)
{
    m_sprite.setPosition(pos_x,pos_y);
    auto handle = TexturesManager::getHandleTo(_path);
    m_sprite.setTexture(TexturesManager::getTexture(handle));
}
Tile::~Tile()
{
    //dtor
}
void Tile::draw(sf::RenderWindow & _window)
{
    _window.draw(m_sprite);
}
void Tile::update(int _miliseconds)
{

}
