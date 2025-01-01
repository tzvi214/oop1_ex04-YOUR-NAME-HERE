#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager();
	sf::Texture& getTexture(const char);
	char getChar(const sf::Texture&) const; 
private:
	bool compareImages(const sf::Image& img1, const sf::Image& img2) const;
	sf::Texture m_guardTex;
	sf::Texture m_doorTex;
	sf::Texture m_robotTex;
	sf::Texture m_wallTex;
	sf::Texture m_bombTex;
	sf::Texture m_saveTex;
	sf::Texture m_eraserTex;
	sf::Texture m_clearPageTex;
};
