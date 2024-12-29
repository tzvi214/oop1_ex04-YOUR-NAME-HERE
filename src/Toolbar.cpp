#include "Toolbar.h"
#include <iostream>
#include <fstream>
#include <string>
#include "TextureManager.h"

//ToolBar::ToolBar() 
//{

	/*
	You need to read the characters in it from the board.txt file, and create the buttons.
The buttons will be created by a loop that will create a new object of type "Button" each time and give the "Button" constructor the appropriate texture by using the getTexture function of the "TextureManager" class (which accepts a character and returns a texture)
And the "Button" constructor should also receive the position of the button (consider that there are 8 buttons and divide them across the entire width of the toolbar), then do a pushback to the vector of the buttons.
- Notes:
It should be noted that the size of the images is not necessarily equal, so you should use the "SCALE" function of TEXTURE and adjust the size. If I'm not mistaken, it should be in the button class.

** Possible errors:
Transferring the texture in reference. Maybe this causes problems?!

*/
//}

ToolBar::ToolBar() : m_toolbarWidht(0) {}

void ToolBar::updateVecButten()
{
	std::string nameFile = "Toolbar.txt";
	std::ifstream file(nameFile);

	if (!file.is_open()) {
		std::cerr << "Error: Unable to open the file!" << std::endl;
		return;
	}


	int counter = 0;
	char ch;
	TextureManager tempTexture; // יצירת אובייקט קבוע
	unsigned int widht;
	while (file.get(ch))
	{ // קריאת תו-תו עד סוף הקובץ

		widht = (m_toolbarWidht / 8) * counter;
		Button button(tempTexture.getTexture(ch), sf::Vector2f(widht, 0.f)); // לפי counter.

		m_buttensVec.push_back(button);

		counter++;
	}


	widht = (m_toolbarWidht / 8) * counter;
	Button button1(tempTexture.getTexture('E'), sf::Vector2f(widht, 0.f)); // לפי counter.
	m_buttensVec.push_back(button1);

	counter++;
	widht = (m_toolbarWidht / 8) * counter;
	Button button2(tempTexture.getTexture('S'), sf::Vector2f(widht, 0.f)); // לפי counter.
	m_buttensVec.push_back(button2);

	counter++;
	widht = (m_toolbarWidht / 8) * counter;
	Button button3(tempTexture.getTexture('C'), sf::Vector2f(widht, 0.f)); // לפי counter.
	m_buttensVec.push_back(button3);


	/*
	int counter = 0;
char ch;
TextureManager tempTexture; // יצירת אובייקט קבוע
unsigned int widht;

while (file.get(ch)) {
	// קריאת תו-תו עד סוף הקובץ

	widht = (m_toolbarWidht / 8) * counter;
	Button button(tempTexture.getTexture(ch), sf::Vector2f(widht, 0.f));
	m_buttensVec.push_back(button);

	counter++;
}

// Add buttons for 'E', 'S', and 'C'
for (char specialChar : {'E', 'S', 'C'}) {
	widht = (m_toolbarWidht / 8) * counter;
	Button button(tempTexture.getTexture(specialChar), sf::Vector2f(widht, 0.f));
	m_buttensVec.push_back(button);

	counter++;
}*/
}

void ToolBar::draw(sf::RenderWindow& window) const
{
	auto background = sf::RectangleShape(sf::Vector2f(window.getSize().x, m_toolbarHeight));
	background.setFillColor(sf::Color::Green);
	window.draw(background);

	for (auto i = size_t(0); i < m_buttensVec.size(); ++i)
	{
		m_buttensVec[i].draw(window);
	}
}

void ToolBar::setToolbarWidht(unsigned int toolbarWidht)
{
	m_toolbarWidht = toolbarWidht;
}

bool ToolBar::pressIntoolbar(const sf::Vector2f& location)
{
	if (location.x < 0 || location.x > m_toolbarWidht)
		return false;
	if (location.y < 0 || location.y > m_toolbarHeight)
		return false;

	return true;
}


char ToolBar::getCharPress(const sf::Vector2f& location)
{
	for (auto i = size_t(0); i < m_buttensVec.size(); i++)
	{
		if (m_buttensVec[i].create().getGlobalBounds().contains(location))
		{
			TextureManager textureMan;
			return textureMan.getChar(m_buttensVec[i].getTexture());
		}
	}

	return 0;
}

