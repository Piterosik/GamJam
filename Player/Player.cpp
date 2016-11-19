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
    m_lastFrame = 3;
    m_frame = 0;
    auto handle = TexturesManager::getHandleTo("./data/player["+ intToStr(m_frame) +"].png");
    m_player.setTexture(TexturesManager::getTexture(handle));
    m_speed = -0.2;
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
    auto handle = TexturesManager::getHandleTo("./data/player["+ intToStr(m_frame) +"].png");
    m_player.setTexture(TexturesManager::getTexture(handle));

    float rotacja = m_player.getRotation();
	float vx = sin(( rotacja * M_PI ) / 180.0f );
	float vy = -cos(( rotacja * M_PI ) / 180.0f );

	m_player.move(m_speed*vx,m_speed*vy);

    sf::Vector2f norm = sf::Vector2f(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y) - m_player.getPosition();
	float rot = atan2(norm.y,norm.x);
	rot = rot * 180.f/M_PI;
    rot = rot + 180;
	m_player.setRotation(rot);
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
