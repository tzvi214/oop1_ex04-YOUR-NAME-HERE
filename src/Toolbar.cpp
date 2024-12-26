#include "Toolbar.h"

ToolBar::ToolBar()
{
	/*
	You need to read the characters in it from the board.txt file, and create the buttons.
The buttons will be created by a loop that will create a new object of type "Button" each time and give the "Button" constructor the appropriate texture by using the getTexture function of the "TextureManager" class (which accepts a character and returns a texture)
And the "Button" constructor should also receive the position of the button (consider that there are 8 buttons and divide them across the entire width of the toolbar), then do a pushback to the vector of the buttons.
- Notes:
It should be noted that the size of the images is not necessarily equal, so you should use the "SCALE" function of TEXTURE and adjust the size. If I'm not mistaken, it should be in the button class.

** Possible errors:
Transferring the texture in reference. Maybe this causes problems?!

*/
}

void ToolBar::draw(sf::RenderWindow& window) const
{
	auto background = sf::RectangleShape(sf::Vector2f(window.getSize().x, toolbarHeight));
	background.setFillColor(sf::Color::Green);
	window.draw(background);

}
