#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Toolbar.h"
#include "TextureManager.h"
#include "GameWindow.h"
#include "SaveTXT.h"

class Painter
{
public:
	Painter() = default;
	void run();



private:
	const unsigned int m_PixelSize = 50; // change to float ? 
	TextureManager m_texture;
	ToolBar m_toolBar;
	GameWindow m_gameWindow;

	//--- function ----
	void handlePress(sf::RenderWindow& window, sf::Vector2f&, bool&);
	bool need2add(char c) const;
	void AddingObjects(sf::RenderWindow& window, sf::Vector2f&, char c);
	bool nedd2save(char c) const { return c == 'S'; }
	void save(); // No const!!
	bool need2clear(char c) const { return c == 'C'; }
	void clearing(); 
	void loadBoardDimensions(unsigned int&, unsigned int&, bool);

};
