#ifndef CGAME_HPP
#define CGAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "./Reporter/Report.hpp"
class CGame
{
public:
    CGame();
    void init();
    void update(const sf::Time & _elapsedTime);
    void display(sf::RenderWindow & _window);
private:
};

#endif // CGAME_HPP
