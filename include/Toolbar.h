#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "vector"

const float m_toolbarHeight = 150;

class ToolBar
{
public:
	ToolBar();
	void updateVecButten();
	void draw(sf::RenderWindow& window) const;
	void setToolbarWidht(unsigned int);
	bool pressIntoolbar(const sf::Vector2f&);
	char getCharPress(const sf::Vector2f&);//?????????????????

private:
	std::vector<Button> m_buttensVec;
	unsigned int m_toolbarWidht;
};