#include "TextureManager.h"
#include <iostream>
//--------------------------------
TextureManager::TextureManager()
{
    if (!m_guardTex.loadFromFile("guard.jpg"))
        std::cerr << "Failed to load guard.jpg\n";
    if (!m_doorTex.loadFromFile("door.jpg"))
        std::cerr << "Failed to load door.jpg\n";
    if (!m_wallTex.loadFromFile("wall.jpg"))
        std::cerr << "Failed to load wall.jpg\n";
    if (!m_robotTex.loadFromFile("robot.jpg"))
        std::cerr << "Failed to load robot.jpg\n";
    if (!m_rockTex.loadFromFile("bomb.jpg"))
        std::cerr << "Failed to load bomb.jpg\n";
    if (!m_clearPageTex.loadFromFile("clearPage.jpg"))
        std::cerr << "Failed to load clearPage.jpg\n";
    if (!m_saveTex.loadFromFile("save.jpeg"))
        std::cerr << "Failed to load save.jpeg\n";
    if (!m_eraserTex.loadFromFile("eraser.jpg"))
        std::cerr << "Failed to load eraser.jpg\n";
    if (!m_tileTex.loadFromFile("tile.jpg"))
        std::cerr << "Failed to load tile.jpg\n";
}

//--------------------------------
sf::Texture& TextureManager::getTexture(const char ch)
{
    switch (ch)
    {
    case '!': return m_guardTex;
    case 'D': return m_doorTex;
    case '/': return m_robotTex;
    case '#': return m_wallTex;
    case '@': return m_rockTex;
    case 'S': return m_saveTex;
    case 'C': return m_clearPageTex;
    case 'E': return m_eraserTex;
	case 'T': return m_tileTex;
    }
    std::cerr << "getTexture: char not found\n";
    throw std::runtime_error("Texture not found");
}
//--------------------------------
const sf::Texture& TextureManager::getTexture(const std::string& name) const
{
    if (name == "guard")  return m_guardTex;
    else if (name == "door")   return m_doorTex;
    else if (name == "robot")  return m_robotTex;
    else if (name == "wall")   return m_wallTex;
    else if (name == "rock")   return m_rockTex;
    else if (name == "save")   return m_saveTex;
    else if (name == "erase")  return m_eraserTex;
    else if (name == "clearPage")  return m_clearPageTex;
	else if (name == "tile")  return m_tileTex;// i think i dont need to add this line

    // if i didnt find the string
    std::cerr << "getTexture: string not found\n";
    throw std::runtime_error("Texture not found");
    
}
//--------------------------------
char TextureManager::getChar(const std::string& name) const
{
    if (name == "guard")  return '!';
    else if (name == "door")  return 'D';
    else if (name == "robot") return '/';
    else if (name == "wall")  return '#';
    else if (name == "rock")  return '@';
    else if (name == "save")  return 'S';
    else if (name == "erase") return 'E';
    else if (name == "clearPage")  return 'C';
	else if (name == "tile")  return 'T';// i think i dont need to add this line


    // if i didnt find the string
    std::cerr << "getChar: Texture not found\n";
    return '\0'; // Return null character if not found
}
//--------------------------------
std::string TextureManager::getString(const char name) const
{
    if (name == '!') return "guard";
    else if (name == 'D') return "door";
    else if (name == '/') return "robot";
    else if (name == '#') return "wall";
    else if (name == '@') return "rock";
    else if (name == 'S') return "save";
    else if (name == 'E') return "erase";
    else if (name == 'C') return "clearPage";
	else if (name == 'T') return "tile";// i think i dont need to add this line


    // if i didnt find the string
    std::cerr << "getTexture: char not found\n";
    throw std::runtime_error("Texture not found");

}
//--------------------------------
void TextureManager::draw(sf::RenderWindow& window, std::string name, sf::Vector2f location) const
{
    auto newObject = sf::Sprite();
    newObject.setPosition(location);
    newObject.setTexture(getTexture(name));
    newObject.setScale(0.25f, 0.25f);
    window.draw(newObject);
}
//--------------------------------
// i didnt check if this function working
void TextureManager::draw(sf::RenderWindow& window, char c, const sf::Vector2f& location) const
{
    /*auto newObject = sf::Sprite();
    newObject.setPosition(location);
    newObject.setTexture(getTexture(c));
    newObject.setScale(0.1f, 0.1f);
    window.draw(newObject);*/
}

