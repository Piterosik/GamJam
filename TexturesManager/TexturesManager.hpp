#ifndef TEXTURESMANAGER_HPP
#define TEXTURESMANAGER_HPP
#include <map>
#include <string>
#include ".././Reporter/Report.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>


class TexturesManager
{
public:
    TexturesManager();
   ~TexturesManager();
    static std::size_t getHandleTo(std::string _path);
    static const sf::Texture & getTexture(std::size_t _handle);
private:
    static std::map<std::size_t,sf::Texture*> m_texturesMap;
    static sf::Texture * m_1x1EmptyTexture;
};

#endif // TEXTURESMANAGER_HPP
