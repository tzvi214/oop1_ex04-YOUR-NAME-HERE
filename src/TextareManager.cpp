#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
	m_guardTex.loadFromFile("guard.jpg");
	m_doorTex.loadFromFile("door.jpg");
	m_wallTex.loadFromFile("wall.jpg");
	m_robotTex.loadFromFile("robot.jpg");
	m_bombTex.loadFromFile("bomb.jpg");
	m_clearPageTex.loadFromFile("clearPage.jpg");
	m_saveTex.loadFromFile("save.jpeg");
	m_eraserTex.loadFromFile("eraser.jpg");
}

//void TextureManager::setTexture(sf::Texture &texture, char ch)
//{
//	switch (ch)
//	{
//	case('!'):
//		m_guardTex = texture;
//		return;
//	case('D'):
//		m_doorTex = texture;
//		return;
//	case('/'):
//		m_robotTex = texture;
//		return;
//	case('#'):
//		m_wallTex = texture;
//		return;
//	case('@'):
//		m_bombTex = texture;
//		return;
//	}
//	std::cerr << "setTexture: char not founded\n ";
//}

sf::Texture& TextureManager::getTexture(const char ch)
{
	switch (ch)
	{
	case('!'):
		return  m_guardTex;
	case('D'):
		return  m_doorTex;
	case('/'):
		return m_robotTex;
	case('#'):
		return m_wallTex;
	case('@'):
		return m_bombTex;
	case('S'):
		return m_saveTex;
	case('C'):
		return m_clearPageTex;
	case('E'):
		return m_eraserTex;
	}
	std::cerr << "setTexture: char not founded\n ";

}

char TextureManager::getChar(const sf::Texture& texture) const
{
	if (&texture == &m_guardTex) {
		return '!';
	}
	if (&texture == &m_doorTex) {
		return 'D';
	}
	if (&texture == &m_robotTex) {
		return '/';
	}
	if (&texture == &m_wallTex) {
		return '#';
	}
	if (&texture == &m_bombTex) {
		return '@';
	}
	if (&texture == &m_saveTex) {
		return 'S';
	}
	if (&texture == &m_clearPageTex) {
		return 'C';
	}
	if (&texture == &m_eraserTex) {
		return 'E';
	}

	std::cerr << "getChar: Texture not found\n";
	return '\0'; // תו null במידה ולא נמצאה התאמה
}

