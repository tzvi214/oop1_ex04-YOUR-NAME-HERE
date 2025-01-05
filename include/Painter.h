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
	const unsigned int m_PixelSize = 50; 
	TextureManager m_textureManager;
	ToolBar m_toolBar;
	GameWindow m_gameWindow;

	//--- function ----
	void handleWindowEvents(sf::RenderWindow& window, bool& userClearAll);
	void handlePress(sf::RenderWindow& window, sf::Vector2f&, bool&);
	bool need2add(char c) const;
	void AddingObjects(sf::RenderWindow& window, sf::Vector2f&, char c);
	bool nedd2save(char c) const { return c == 'S'; }
	void save(); 
	bool need2clear(char c) const { return c == 'C'; }
	void clearing(); 
	void loadBoardDimensions(unsigned int&, unsigned int&, bool);
	void readFromFile(std::ifstream& file, unsigned int& boardHeight, unsigned int& boardWidth);
};
