#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <vector>
#include "Image.h"
#include "SaveTXT.h"
#include <fstream>
#include <string>
#include <iostream>

class GameWindow
{
public:
	void setRow(unsigned int);
	void setCol(unsigned int);
	void save();
	void handleNewClick(const sf::Vector2f & location, char c);
	void draw(sf::RenderWindow& window) const;
	void clearing();
	void setImageVec(const Image& image); 
	bool robotExist() const { return m_robotExist; } 
	bool itsRobot(char c) const { return c == m_robot; } 
private:
	       //---data_member---
	std::vector <Image> m_ImageVec;
	char m_robot = '/';
	bool m_robotExist = false;
	std::vector <SaveTXT> m_SaveTxtVec;
	TextureManager m_textureManager;
	const float m_PixelSize = 50;
	unsigned int m_col;
	unsigned int m_row;
	
	         //---function----

	void drawTile(sf::RenderWindow& ) const;
	bool need2delete(char c) const { return c == 'E'; }
	void deleteObject(const sf::Vector2f & location, char c);
	void addObject(const sf::Vector2f& location, char c);
	void write2file() const;
	sf::Vector2f calculateCorrectLocation(const sf::Vector2f& location);
};