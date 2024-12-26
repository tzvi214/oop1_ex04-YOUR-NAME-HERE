#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <vector>

class GameWindow
{
public:
	void handleNewClick(const sf::Vector2f & location, char c);// maybe i need also sf::Window

private:
	       //---data_mamber---
	sf::Sprite creat(const sf::Texture&, const sf::Vector2f& location);
	std::vector<sf::Sprite> m_textureVec;
	char m_robot = '/';
	bool m_robotExist = false;
	         //---function----
	bool robotExist() const { return m_robotExist; }
	bool itsRobot(char c) const {return c == m_robot ; }
	bool need2delete(char c) const { return c == 'A'; }
	void deleteObject(const sf::Vector2f & location, char c);
	void addObject(const sf::Vector2f& location, char c);
};