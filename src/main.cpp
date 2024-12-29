#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include "Painter.h"
#include <filesystem>  //c++ 17

int main()
{
	Painter().run();
	return EXIT_SUCCESS;
}

/*
* 	std::string fileName = "Board.txt";

	if (std::filesystem::exists(fileName)) // if exist
	{
		std::cout << "Board.txt exists\n";

		std::ifstream Board(fileName);
		if (Board.is_open()) {
			Board >> sizewindow.length >> sizewindow.width;
			std::cout << "length is: " << sizewindow.length << " width is: " << sizewindow.width << std::endl;
			Board.close();
		}
	}
	else // if not exist
	{
		std::cout << "Board.txt NOT exists\n";
		std::cout << "Enter Length and Width (type: float)\n";
		std::cin >> sizewindow.length >> sizewindow.width;

		// ����� ����� ������ ���� �� �������
		std::ofstream outputBoard(fileName);
		if (outputBoard.is_open()) {
			outputBoard << sizewindow.length << " " << sizewindow.width;
			std::cout << "Data written to Board.txt\n";
			outputBoard.close();  // ����� �����
		}
		else {
			std::cout << "Error opening the file to write.\n";
		}
*
*
	auto window = sf::RenderWindow(sf::VideoMode(1100, 800), "SFML: Hellow Hanan!");
	auto texGuard = sf::Texture();
	if (!texGuard.loadFromFile("guard.jpg"))
	{
		std::cerr << " not founded image \n";
		return -1;
	}

	auto sprGuard = sf::Sprite(texGuard);
	sprGuard.setScale(0.25f, 0.25f); // ����� ��� ���� �� 50% ����� ������
	sprGuard.setPosition(200.0f, 100.0f); // ����� ������ ���� X=200 �-Y=100

	sf::RectangleShape toolbar(sf::Vector2f(1100.0f, 50.0f)); // ���� ����� 50 �������
	toolbar.setFillColor(sf::Color::Cyan);
	toolbar.setPosition(0, 0);

	std::vector<sf::RectangleShape> buttons; // ����� ���� �� �������

	float buttonWidth = 100.0f;// ����� �� �� �����
	float buttonHeight = 40.0f;
	float spacing = 20.0f;

	for (int i = 0; i < 9; i++)
	{
		sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
		button.setFillColor(sf::Color::Red);
		button.setPosition(10.0f + i * (buttonWidth + spacing), 5.0f);
		buttons.push_back(button);
	}

	// choose font
	sf::Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		std::cerr << "Font ''ARIEL.TTF'' not Founded \n";
		return -1;
	}


	// ����� ���� ��� �����
	std::vector<sf::Text>buttonLabels;
	for (int i=0;i<buttons.size();i++)
	{
		sf::Text label
		("Button " + std::to_string(i + 1), font, 16);

		// ����� ����� �� ������
		sf::Vector2f buttonPosition = buttons[i].getPosition();
		label.setPosition(buttonPosition.x + 10.0f, buttonPosition.y + 5.0f); // ���� ��� ���� ������
		label.setFillColor(sf::Color::Black); // ��� �����


		buttonLabels.push_back(label);
	}


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();  // ���� �� ����� �� ���� �� ����� �����
			}
		}


		window.clear(sf::Color::White);

		window.draw(toolbar);
		window.draw(sprGuard);

		for (int i = 0; i < buttons.size(); i++)
			window.draw(buttons[i]);

		for (int i = 0; i < buttonLabels.size(); i++)
			window.draw(buttonLabels[i]);


		window.display();
	}

	*/


	//#include <iostream>
	//#include <fstream>
	//#include <string>
	//#include <filesystem>  // ������ filesystem �-C++17
	//
	//class sizeWindow {
	//public:
	//    float length;
	//    float width;
	//};
	//
	//int main() {
	//    sizeWindow sizewindow;
	//    std::string fileName = "Board.txt";
	//
	//    // ����� ���� ����� ����� std::filesystem
	//    if (std::filesystem::exists(fileName)) {
	//        std::cout << "Board.txt exists\n";
	//
	//        std::ifstream Board(fileName);
	//        if (Board.is_open()) {
	//            Board >> sizewindow.length >> sizewindow.width;
	//            std::cout << "length is: " << sizewindow.length << " width is: " << sizewindow.width << std::endl;
	//            Board.close();  // ����� �����
	//        }
	//    }
	//    else {
	//        std::cout << "Board.txt NOT exists\n";
	//        std::cout << "Enter Length and Width (type: float)\n";
	//        std::cin >> sizewindow.length >> sizewindow.width;
	//
	//        // ����� ����� ������ ���� �� �������
	//        std::ofstream outputBoard(fileName);
	//        if (outputBoard.is_open()) {
	//            outputBoard << sizewindow.length << " " << sizewindow.width;
	//            std::cout << "Data written to Board.txt\n";
	//            outputBoard.close();  // ����� �����
	//        }
	//        else {
	//            std::cout << "Error opening the file to write.\n";
	//        }
	//    }
	//
	//    return 0;
	//}