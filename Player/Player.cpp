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
    m_pos_x = 2.5*64;
    m_pos_y = 0;
    m_player.setPosition(m_pos_x,m_pos_y);
    m_player.setOrigin(32,32);
    m_lastFrame = 3;
    m_frame = 0;
    auto handle = TexturesManager::getHandleTo("./data/player["+ intToStr(m_frame) +"].png");
    m_player.setTexture(TexturesManager::getTexture(handle));
    m_speed = 0.4;
    m_rotation = 0;
    for(int i =0;i < m_lastFrame;i++)
    {
        auto handle = TexturesManager::getHandleTo("./data/player["+ intToStr(i) +"].png");
        m_textureHandles[i] = handle;
    }
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
    m_elapsedTime = m_elapsedTime + _milseconds;
    if(m_elapsedTime > 160)
    {
        m_frame++;
        if(m_frame > m_lastFrame-1)m_frame = 1;
        m_elapsedTime = 0;
    }
    auto handle = m_textureHandles[m_frame];
    m_player.setTexture(TexturesManager::getTexture(handle));


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_pos_x -= 4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_pos_x += 4;
    }
    m_pos_y = m_pos_y + m_speed * (_milseconds);

    if(m_pos_x > 6*64-32)m_pos_x = 6*64-32;
    if(m_pos_x < 1*64-40)m_pos_x = 1*64-40;
	m_player.setPosition(m_pos_x,m_pos_y);

}
