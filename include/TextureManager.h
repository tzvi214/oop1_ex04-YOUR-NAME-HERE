#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextureManager
{
public:
	TextureManager();
	sf::Texture& getTexture(const char);// maybe to changt it to getSprite
	const sf::Texture& getTexture(const std::string&) const;// maybe to change it to getSprite
	char getChar(const std::string&)const;
	std::string getString(const char) const;

	void draw(sf::RenderWindow& , std::string,  sf::Vector2f) const;// i need to finish this function
	void draw(sf::RenderWindow& , char, const sf::Vector2f&) const;// this function will be for toolbar

private:
	sf::Texture m_guardTex;
	sf::Texture m_doorTex;
	sf::Texture m_robotTex;
	sf::Texture m_wallTex;
	sf::Texture m_rockTex;
	sf::Texture m_saveTex;
	sf::Texture m_eraserTex;
	sf::Texture m_clearPageTex;
	sf::Texture m_tileTex;
};
