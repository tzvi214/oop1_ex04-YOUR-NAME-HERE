#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class TextureManager
{
public:
	TextureManager();
	const sf::Texture& getTexture(const char) const;
	const sf::Texture& getTexture(const std::string&) const;
	char getChar(const std::string&)const;
	std::string getString(const char) const;
	void draw(sf::RenderWindow& , std::string,  sf::Vector2f) const;

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
