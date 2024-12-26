#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "vector"

const float toolbarHeight = 150;

class ToolBar
{
public:
	ToolBar();
	void draw(sf::RenderWindow& window) const;

private:
	std::vector<Button> m_buttensVec;

};