#include "TexturesManager.hpp"

TexturesManager::TexturesManager()
{
    m_1x1EmptyTexture->create(64,64);
}

TexturesManager::~TexturesManager()
{

}

std::size_t TexturesManager::getHandleTo(std::string _path)
{
    std::size_t _hash = std::hash<std::string>{}(_path);
    std::map<std::size_t,sf::Texture*>::iterator it = m_texturesMap.find( _hash );
    if( it == m_texturesMap.end() )
    {//Not loaded yet
        sf::Texture * ptr = new sf::Texture;
        if(ptr->loadFromFile(_path) != true)
        {///Can not open - error
            delete ptr;
            ptr = m_1x1EmptyTexture;
            std::string info = "Can not load file: " + _path;
            Logger::report(info);
        }
        std::cout << "Texture at handle " << _hash << std::endl;
        m_texturesMap.insert(std::pair<size_t,sf::Texture*>(_hash,ptr));
        Logger::report("Texture was loaded successfully");
        return TexturesManager::getHandleTo(_path);
    }
    return it->first;

}

const sf::Texture & TexturesManager::getTexture(std::size_t _handle)
{
    std::map<std::size_t,sf::Texture*>::iterator it = m_texturesMap.find( _handle );
    if( it == m_texturesMap.end() )
    {///Texture does not exist
        std::cout << "Can not found texture at handle " << _handle << std::endl;
        return *m_1x1EmptyTexture;
    }
    std::cout << "Texture at " << & it->second << std::endl;
    return *(it->second);
}
 std::map<std::size_t,sf::Texture*> TexturesManager::m_texturesMap;
 sf::Texture * TexturesManager::m_1x1EmptyTexture = new sf::Texture;
