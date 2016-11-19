#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "./Game.hpp"
#include "./TexturesManager/TexturesManager.hpp"
#include "./Hallway/Hallway.hpp"
#include "./Player/Player.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(640,480), "SFML works!");

    TexturesManager mgr;
    sf::Time timeLastUpdate = sf::Time::Zero;
    sf::Clock gameClock;
    const sf::Time stepTime = sf::seconds(1.f/60.f);

    Player player;
    Hallway hall;

    while (window.isOpen())
    {
        sf::Time time = gameClock.restart();
        timeLastUpdate += time;
        while(timeLastUpdate > stepTime)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)window.close();
            }
            timeLastUpdate -= stepTime;
            //update(stepTime);
            player.update(stepTime.asMilliseconds());
            hall.update(stepTime.asMilliseconds());
        }
        window.clear(sf::Color::Black);
        hall.draw(window);
        player.draw(window);
        window.display();
    }

    return 0;
}
