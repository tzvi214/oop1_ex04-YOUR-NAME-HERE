#include "Painter.h"


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

        /*if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }*/
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // starting the main function
            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2f location(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
                if (m_toolBar.pressIntoolbar(location))
                {
                    handlePress(window, location);
                }
            }



            window.clear();
            m_toolBar.draw(window);
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
    GameWindow gameWindow;

    do
    {
        gameWindow.handleNewClick(location, c);
        sf::Event event;
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
        if (event.type == sf::Event::MouseLeft)
        {
            sf::Vector2f location(sf::Mouse::getPosition(window));
        }
        gameWindow.print(window);
        window.display();

    } while (!m_toolBar.pressIntoolbar(location));

}

   
