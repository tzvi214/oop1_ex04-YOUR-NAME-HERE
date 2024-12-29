#include "Painter.h"
#include <iostream>

void Painter::run()
{

    std::cout << "Enter width and height\n";
    // First width, then height!
    unsigned int boardHeight, boardWidth;
    std::cin >> boardWidth >> boardHeight;

    unsigned int heightPixel = boardHeight * m_PixelSize;
    unsigned int widthPixel = boardWidth * m_PixelSize;
    m_toolBar.setToolbarWidht(widthPixel);
    m_toolBar.updateVecButten();





    // create new window in the requested size
    auto window = sf::RenderWindow(sf::VideoMode(widthPixel, heightPixel + m_toolbarHeight), "SFML: Hello Hanan");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                auto location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                if (m_toolBar.pressIntoolbar(location))
                {
                    handlePress(window, location);
                }
            }

            window.clear();
            m_toolBar.draw(window);
            m_gameWindow.draw(window);
            window.display();
        }

    }
}

//--------- private_function -------


void Painter::handlePress( sf::RenderWindow& window, sf::Vector2f& location)
{
    char c = m_toolBar.getCharPress(location);
    if (nedd2add(c))
    {
        AddingObjects(window, location, c);
    }
   
   /* else if(nedd2save)
    else if (nedd2...)*/

}

bool Painter::nedd2add(char c) const
{
    return (c == '!' || c == '/' || c == 'D' || c == '@' || c == '#');
}

void Painter::AddingObjects( sf::RenderWindow& window, sf::Vector2f& location, char c)
{
    
    do
    {
        sf::Event event;
        while (window.waitEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                auto location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                if (!m_toolBar.pressIntoolbar(location))
                {
                    m_gameWindow.handleNewClick(location, c);

                    window.clear();
                    m_toolBar.draw(window);
                    m_gameWindow.draw(window);
                    window.display();
                }
                else
                    return;
            }
            
            else
                continue;
            
        }
     

    } while (!m_toolBar.pressIntoolbar(location));

}

   
