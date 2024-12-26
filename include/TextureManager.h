#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager() = default;
	void setTexture(sf::Texture&, char);// Possible errors : Transferring the texture in reference.Maybe this causes problems ? !
	sf::Texture getTexture(char);

private:
	sf::Texture m_guardTex;
	sf::Texture m_doorTex;
	sf::Texture m_robotTex;
	sf::Texture m_wallTex;
	sf::Texture m_bombTex;
};
