#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Toolbar.h"
#include "TextureManager.h"
#include "GameWindow.h"

class Painter
{
public:
	Painter() = default;
	void run();
	

private:

	const unsigned int m_PixelSize = 50;
	TextureManager m_texture;
	ToolBar m_toolBar;
	GameWindow m_gameWindow;

	//--- function ----
	
	void handlePress(sf::RenderWindow& window, sf::Vector2f& );
	bool nedd2add(char c) const;
	void  AddingObjects(sf::RenderWindow& window, sf::Vector2f& , char c);
};  

