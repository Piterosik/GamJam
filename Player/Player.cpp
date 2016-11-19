#include "Player.hpp"
#include <cmath>
std::string intToStr(int n)
{
     std::string tmp;
     if(n < 0) {
      tmp = "-";
      n = -n;
     }
     if(n > 9)
      tmp += intToStr(n / 10);
     tmp += n % 10 + 48;
     return tmp;
}
Player::Player()
{
    m_pos_x = 5*64;
    m_pos_y = 0;
    m_player.setPosition(m_pos_x,m_pos_y);
    m_player.setOrigin(32,32);
    m_lastFrame = 10;
    m_frame = 0;
    auto handle = TexturesManager::getHandleTo("./data/player["+ intToStr(m_frame) +"].png");
    m_player.setTexture(TexturesManager::getTexture(handle));
}

Player::~Player()
{
    //dtor
}
void Player::draw(sf::RenderWindow & _window)
{
    _window.draw(m_player);
}
void Player::update( int _milseconds)
{
    if(_milseconds > 90)
    {
        m_frame++;
        if(m_frame > m_lastFrame)m_frame = 0;
        std::cout << m_frame << std::endl;
    }
}
/*
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {

    }
    {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {

    }
    {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

    }
    {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {

    }
*/
