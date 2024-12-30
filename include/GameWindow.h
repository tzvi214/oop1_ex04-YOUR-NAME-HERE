#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <vector>
#include "Image.h"

class GameWindow
{
public:
	void handleNewClick(const sf::Vector2f & location, char c);
	void draw(sf::RenderWindow& window) const;
	void clearing();// i need to call to some dtor to delete the mammary 
private:
	       //---data_member---
	std::vector <Image> m_ImageVec;
	char m_robot = '/';
	bool m_robotExist = false;
	
	         //---function----
	bool robotExist() const { return m_robotExist; }
	bool itsRobot(char c) const {return c == m_robot ; }
	bool need2delete(char c) const { return c == 'E'; }
	void deleteObject(const sf::Vector2f & location, char c);
	void addObject(const sf::Vector2f& location, char c);
};