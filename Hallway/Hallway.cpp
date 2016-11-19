#include "Hallway.hpp"

Hallway::Hallway()
{
    auto handle = TexturesManager::getHandleTo("./data/tileHallway.png");
    m_size.x = 6;
    m_size.y = 30;

    for(int i = 0; i < m_size.x;i++)
    {///Kolumna nr i
        for(int j = 0; j< m_size.y;j++)
        {///Wiersz nr j
            sf::Sprite* tmp = new sf::Sprite;
            tmp->setTexture(TexturesManager::getTexture(handle));
            tmp->setPosition(i*64+2*64,j*64);
            m_tilesList.push_back(tmp);
            std::cout << "Sprite at " << i*64 << " " << j*64 << std::endl;
        }
    }

}

Hallway::~Hallway()
{

}
void Hallway::draw(sf::RenderWindow & _window)
{
     for (std::vector<sf::Sprite*>::iterator it=m_tilesList.begin(); it != m_tilesList.end(); ++it)
     {
        _window.draw(*(*it));
     }
}
void Hallway::update( int _milseconds)
{

}
