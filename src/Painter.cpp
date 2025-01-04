#include "Painter.h"
#include <iostream>
#include <filesystem>

void Painter::run()
{
    unsigned int boardHeight = 0, boardWidth = 0;

    bool userClearAll = false;
    bool temp = true;
    // first time temp = true, and the user will need to enter the dimensions, after that temp is false.
    // if the user press "clear all", the window will close, and the user will need to enter the dimensions again.
    // if the user don't press "clear all", and close the window, the user will not need to enter the dimensions again.
    while (userClearAll || temp)
    {
        temp = false;

        // if user clear all, the dimensions will be 0, and the user will need to enter the dimensions again.
        loadBoardDimensions(boardHeight, boardWidth, userClearAll);
        userClearAll = false;
        // ���� ������
        std::cout << "Final dimensions: Width = " << boardWidth << ", Height = " << boardHeight << "\n";


        unsigned int heightPixel = boardHeight * m_PixelSize;
        unsigned int widthPixel = boardWidth * m_PixelSize;
        m_toolBar.setToolbarWidht(widthPixel);
        m_toolBar.updateVecButten();

        // set size board for GamWindow.
        m_gameWindow.setRow(boardHeight);
        m_gameWindow.setCol(boardWidth);



        // create new window in the requested size
        auto window = sf::RenderWindow(sf::VideoMode(widthPixel, heightPixel + m_toolbarHeight), "SFML: Hello Hanan");


        while (window.isOpen())
        {
            window.clear();
            m_toolBar.draw(window); // draw "Toolbar"
            m_gameWindow.draw(window); // draw "gameWindow"
            window.display();

            sf::Event event;
            while (window.pollEvent(event))
            {
                // close window
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                // action.
                if (event.type == sf::Event::MouseButtonReleased)
                {
                    auto location = window.mapPixelToCoords(
                        { event.mouseButton.x, event.mouseButton.y });

                    // if press into "Toolbar"
                    if (m_toolBar.pressIntoolbar(location))
                    {
                        handlePress(window, location, userClearAll);
                    }
                }

                if (userClearAll) // if the user press "clear all", the window will close, and the user will need to enter the dimensions again.
                {
                    break;
                }
            }

        }
    }
}


//--------- private_function -------


void Painter::handlePress(sf::RenderWindow& window, sf::Vector2f& location, bool& userClearAll)
{
    while (window.isOpen())
    {
        // check what was the user press ?
        char c = m_toolBar.getCharPress(location);
        if (nedd2save(c))
        {
            // save Function.
            save();
            std::cout << "saving... \n \n";
            return;
        }
        else if (need2clear(c))
        {
            // clear all
            std::cout << "clearing All... \n ";
            clearing();
            window.close();
            userClearAll = true;
            return;
        }
        else if (need2add(c))
        {
            AddingObjects(window, location, c);
        }
    }

}

bool Painter::need2add(char c) const
{
    return (c == '!' || c == '/' || c == 'D' || c == '@' || c == '#' || c == 'E');
}

void Painter::AddingObjects(sf::RenderWindow& window, sf::Vector2f& location, char c)
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

            location = window.mapPixelToCoords(
                { event.mouseButton.x, event.mouseButton.y });

            // if -> this new location are on "GameWindoa" 
            if (!m_toolBar.pressIntoolbar(location))
            {
                m_gameWindow.handleNewClick(location, c);

                window.clear();
                m_toolBar.draw(window);
                m_gameWindow.draw(window);
                window.display();
            }

            else if (m_toolBar.pressIntoolbar(location))
            {
                return;
            }
        }

        else
            continue;
    }
}

void Painter::save()
{
    m_gameWindow.save();
}

void Painter::clearing()
{
	m_gameWindow.clearing();
    m_toolBar.clear();

}

void Painter::loadBoardDimensions(unsigned int& boardHeight, unsigned int& boardWidth, bool userClearAll)
{
    const std::string fileName = "board.txt";
    if (std::filesystem::exists(fileName) && !userClearAll)
    {
        std::cout << "The file '" << fileName << "' exists. Reading dimensions from the file...\n";

        std::ifstream file(fileName);
        if (file.is_open())
        {

            file >> boardHeight; // ����� ������ �������
            file >> boardWidth; // ����� ������ 

            file.close();

            std::cout << "Read dimensions: Width = " << boardWidth << ", Height = " << boardHeight << "\n";
        }
        else {
            std::cerr << "Failed to open the file '" << fileName << "'.\n";
            return exit(EXIT_FAILURE); // ����� �� ��� �����
        }
    }
    else {
        std::cout << "The file '" << fileName << "' does not exist.\n";
        std::cout << "Enter width and height\n";
        // First width, then height!
        std::cin >> boardWidth >> boardHeight;
    }
}