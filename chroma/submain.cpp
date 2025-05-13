#include <iostream>
#include <vector>
#include <string>
#include<ctime>
#include<cstdlib>
#include <cmath>
#include <algorithm>


#include<fstream>
#include<sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>


#include "interact.h"
#include "global.h"




//------------------- MAIN GAME STATES ------------------------





void drawmenu(sf::RenderWindow& window, sf::Font& font)
{

	sf::Text name(font, "- CHROMA -", 100);
	sf::Text startbutton(font, "START", 60);
	sf::Text helpbutton(font, "HELP", 60);
	sf::Text creditsbutton(font, "CREDITS", 60);
	sf::Text exitbutton(font, "EXIT", 60);

	sf::FloatRect bounds = name.getGlobalBounds();
	sf::FloatRect bounds1 = startbutton.getGlobalBounds();
	sf::FloatRect bounds2 = helpbutton.getGlobalBounds();
	sf::FloatRect bounds3 = creditsbutton.getGlobalBounds();
	sf::FloatRect bounds4 = exitbutton.getGlobalBounds();

	name.setOrigin({ bounds.position.x + bounds.size.x / 2, 0.f });
	startbutton.setOrigin({ bounds1.position.x + bounds1.size.x / 2, 0.f });
	helpbutton.setOrigin({ bounds2.position.x + bounds2.size.x / 2, 0.f });
	creditsbutton.setOrigin({ bounds3.position.x + bounds3.size.x / 2, 0.f });
	exitbutton.setOrigin({ bounds4.position.x + bounds4.size.x / 2, 0.f });


	name.setPosition({ 960.f, 150.f });
	startbutton.setPosition({ 960.f, 400.f });
	helpbutton.setPosition({ 960.f, 550.f });
	creditsbutton.setPosition({ 960.f, 700.f });
	exitbutton.setPosition({ 960.f, 850.f });

	auto mouse_pos = sf::Vector2f(sf::Mouse::getPosition(window));
	interactmenu(mouse_pos, startbutton, helpbutton, creditsbutton, exitbutton);


	window.draw(name);

	window.draw(startbutton);
	window.draw(helpbutton);
	window.draw(creditsbutton);
	window.draw(exitbutton);

}

void drawlvls(sf::RenderWindow& window, sf::Font& font, sf::Texture& startgameT)
{
	int txtsize = 50;

	// all lvls for selection
	sf::RectangleShape startgame({ 800, 800 });
	startgame.setOrigin(sf::Vector2f(400, 400));
	startgame.setTexture(&startgameT);
	startgame.setPosition({ 960.f, 540.f });

	sf::Text lvlt1(font, "LEVEL1", txtsize);
	sf::FloatRect bounds1 = lvlt1.getGlobalBounds();
	lvlt1.setOrigin({ bounds1.position.x + bounds1.size.x / 2, bounds1.position.y + bounds1.size.y / 2 });
	lvlt1.setPosition({ 760.f,390.f });


	sf::Text lvlt2(font, "LEVEL2", txtsize);
	sf::FloatRect bounds2 = lvlt2.getGlobalBounds();
	lvlt2.setOrigin({ bounds2.position.x + bounds2.size.x / 2, bounds2.position.y + bounds2.size.y / 2 });
	lvlt2.setPosition(lvlt1.getPosition() + sf::Vector2f{ 170.f,-50.f });

	sf::Text lvlt3(font, "LEVEL3", txtsize);
	sf::FloatRect bounds3 = lvlt3.getGlobalBounds();
	lvlt3.setOrigin({ bounds3.position.x + bounds3.size.x / 2, bounds3.position.y + bounds3.size.y / 2 });
	lvlt3.setPosition(lvlt2.getPosition() + sf::Vector2f{ 170.f,40.f });


	sf::Text lvlt4(font, "LEVEL4", txtsize);
	sf::FloatRect bounds4 = lvlt4.getGlobalBounds();
	lvlt4.setOrigin({ bounds4.position.x + bounds4.size.x / 2, bounds4.position.y + bounds4.size.y / 2 });
	lvlt4.setPosition(lvlt3.getPosition() + sf::Vector2f{ 110.f,160.f });



	auto mouse_pos = sf::Vector2f(sf::Mouse::getPosition(window));
	interactlvls(mouse_pos, lvlt1, lvlt2, lvlt3, lvlt4);


	window.draw(startgame);

	window.draw(lvlt1);

	window.draw(lvlt2);

	window.draw(lvlt3);

	window.draw(lvlt4);

}

void drawhelp(sf::RenderWindow& window, sf::Font& font, std::vector<sf::Texture>& helpicons, std::vector<std::string>& helpLines)
{


	sf::Text line(font);
	line.setCharacterSize(50);
	sf::FloatRect bounds = line.getGlobalBounds();
	line.setOrigin({ bounds.position.x + bounds.size.x / 2, 0.f });
	line.setFillColor(sf::Color::Black);


	for (int i = 0; i < helpLines.size(); ++i)
	{
		line.setString(helpLines[i]);
		line.setPosition({ 80.f, 80.f * (i + 1) });
		window.draw(line);
	}



	sf::RectangleShape arrow_keys;
	arrow_keys.setSize(sf::Vector2f(400, 200));
	arrow_keys.setPosition(sf::Vector2f{ 1000.f,300.f });

	sf::RectangleShape spacebar;
	spacebar.setSize(sf::Vector2f(400, 200));
	spacebar.setPosition(sf::Vector2f{ 1200.f,550.f });


	sf::RectangleShape enter;
	enter.setSize(sf::Vector2f(200, 200));
	enter.setPosition(sf::Vector2f{ 1500.f,1300.f });

	sf::RectangleShape mouseleft;
	mouseleft.setSize(sf::Vector2f(280, 200));
	mouseleft.setPosition(sf::Vector2f{ 400.f,1590.f });

	sf::RectangleShape backspace;
	backspace.setSize(sf::Vector2f(300, 120));
	backspace.setPosition(sf::Vector2f{ 1100.f,1600.f });




	arrow_keys.setTexture(&helpicons[0]);
	spacebar.setTexture(&helpicons[1]);
	enter.setTexture(&helpicons[2]);
	mouseleft.setTexture(&helpicons[3]);
	backspace.setTexture(&helpicons[4]);



	window.draw(arrow_keys);
	window.draw(spacebar);
	window.draw(enter);
	window.draw(mouseleft);
	window.draw(backspace);

}

void drawcredits(sf::RenderWindow& window, sf::Font& font, std::vector<std::string>& creditslines)
{
	sf::Text line(font);
	line.setCharacterSize(50);
	sf::FloatRect bounds = line.getGlobalBounds();
	line.setOrigin({ bounds.position.x + bounds.size.x / 2, 0.f });
	line.setFillColor(sf::Color::Black);


	for (int i = 0; i < creditslines.size(); ++i)
	{
		line.setString(creditslines[i]);
		line.setPosition({ 80.f, 80.f * i });
		window.draw(line);
	}

}






//--------------------- LVLS AND GAMEPLAY -------------------





void drawlvl1(sf::RenderWindow& window, const std::vector<sf::Texture>& actscenes)
{

	sf::RectangleShape ACT1_scene;
	ACT1_scene.setSize(sf::Vector2f(1920, 1080));



	if (currentact1scene == "Act1scene1")
	{
		ACT1_scene.setTexture(&actscenes[0]);
	}
	else if (currentact1scene == "Act1scene2")
	{
		ACT1_scene.setTexture(&actscenes[1]);

	}
	else if (currentact1scene == "Act1scene3")
	{
		ACT1_scene.setTexture(&actscenes[2]);
	}
	else if (currentact1scene == "")
	{
		currentact1scene = "Act1scene1";
	}

	window.draw(ACT1_scene);

}

void rungmaeplay1(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls)
{
	window.clear(sf::Color(128, 128, 128));

	// Load walls only if the vector is empty (i.e., first time entering this state)
	if (walls.empty())
	{
		std::fstream mazefile;
		mazefile.open("assets\\mazes\\maze1.txt", std::ios::in); // Open file in read mode

		if (mazefile.is_open())
		{
			std::string line;
			while (getline(mazefile, line)) // Read each line
			{
				std::istringstream iss(line);
				std::string x_str, y_str;
				if (getline(iss, x_str, ',') && getline(iss, y_str)) // Split by ',' (y_str takes rest of line)
				{
					float x = std::stof(x_str);
					float y = std::stof(y_str);
					sf::RectangleShape wall(sf::Vector2f(60.f, 60.f)); // Set wall size (adjust as needed)
					wall.setPosition({ x, y });
					wall.setFillColor(sf::Color::Black);
					walls.push_back(wall); // Add wall to vector
				}
			}
			mazefile.close();
		}
	}


	sf::Vector2f startPos = { 30.f,30.f };
	// collision transition maybe better
	if (player.getGlobalBounds().findIntersection(next_door.getGlobalBounds()))
	{
		lvl2locked = false;
		currentState = "lvl2";
		player.setPosition(startPos);
	}

}



void drawlvl2(sf::RenderWindow& window, const std::vector<sf::Texture>& act2scenes)
{
	sf::RectangleShape ACT2_scene;
	ACT2_scene.setSize(sf::Vector2f(1920, 1080));



	if (currentact2scene == "Act2scene1")
	{
		ACT2_scene.setTexture(&act2scenes[0]);
	}
	else if (currentact2scene == "Act2scene2")
	{
		ACT2_scene.setTexture(&act2scenes[1]);

	}
	else if (currentact2scene == "Act2scene3")
	{
		ACT2_scene.setTexture(&act2scenes[2]);
	}
	else if (currentact2scene == "Act2scene4")
	{
		ACT2_scene.setTexture(&act2scenes[3]);
	}
	else if (currentact2scene == "")
	{
		currentact2scene = "Act2scene1";
	}

	window.draw(ACT2_scene);
}

void rungmaeplay2(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls)
{

	window.clear(sf::Color(128, 128, 128));

	// Load walls only if the vector is empty (i.e., first time entering this state)
	if (walls.empty())
	{
		std::fstream mazefile;
		mazefile.open("assets\\mazes\\maze3.txt", std::ios::in); // Open file in read mode

		if (mazefile.is_open())
		{
			std::string line;
			while (getline(mazefile, line)) // Read each line
			{
				std::istringstream iss(line);
				std::string x_str, y_str;
				if (getline(iss, x_str, ',') && getline(iss, y_str)) // Split by ',' (y_str takes rest of line)
				{
					float x = std::stof(x_str);
					float y = std::stof(y_str);
					sf::RectangleShape wall(sf::Vector2f(60.f, 60.f)); // Set wall size (adjust as needed)
					wall.setPosition({ x, y });
					wall.setFillColor(sf::Color::Black);
					walls.push_back(wall); // Add wall to vector
				}
			}
			mazefile.close();
		}
	}


	//na99el lil interact wkhw
	sf::Vector2f startPos = { 20.f,30.f };
	// collision transition maybe better
	if (bombsPlaced == true)
	{
		if (player.getGlobalBounds().findIntersection(next_door.getGlobalBounds()))
		{
			lvl3locked = false;
			currentState = "lvl3";
			player.setPosition(startPos);
		}
	}
}



void drawlvl3(sf::RenderWindow& window, const std::vector<sf::Texture>& act3scenes)
{
	sf::RectangleShape ACT3_scene;
	ACT3_scene.setSize(sf::Vector2f(1920, 1080));



	if (currentact3scene == "Act3scene1")
	{
		ACT3_scene.setTexture(&act3scenes[0]);
	}
	else if (currentact3scene == "Act3scene2")
	{
		ACT3_scene.setTexture(&act3scenes[1]);

	}
	else if (currentact3scene == "Act3scene3")
	{
		ACT3_scene.setTexture(&act3scenes[2]);
	}
	else if (currentact3scene == "Act3scene4")
	{
		ACT3_scene.setTexture(&act3scenes[3]);
	}
	else if (currentact3scene == "")
	{
		currentact3scene = "Act3scene1";
	}

	window.draw(ACT3_scene);
}

void rungmaeplay3(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls)
{

	window.clear(sf::Color(128, 128, 128));

	// Load walls only if the vector is empty (i.e., first time entering this state)
	if (walls.empty())
	{
		std::fstream mazefile;
		mazefile.open("assets\\mazes\\maze4.txt", std::ios::in); // Open file in read mode

		if (mazefile.is_open())
		{
			std::string line;
			while (getline(mazefile, line)) // Read each line
			{
				std::istringstream iss(line);
				std::string x_str, y_str;
				if (getline(iss, x_str, ',') && getline(iss, y_str)) // Split by ',' (y_str takes rest of line)
				{
					float x = std::stof(x_str);
					float y = std::stof(y_str);
					sf::RectangleShape wall(sf::Vector2f(60.f, 60.f)); // Set wall size (adjust as needed)
					wall.setPosition({ x, y });
					wall.setFillColor(sf::Color::Black);
					walls.push_back(wall); // Add wall to vector
				}
			}
			mazefile.close();
		}
	}


	//na99el lil interact wkhw
	sf::Vector2f startPos = { 30.f,20.f };
	// collision transition maybe better
	if (player.getGlobalBounds().findIntersection(next_door.getGlobalBounds()))
	{
		lvl4locked = false;
		currentState = "lvl4";
		player.setPosition(startPos);
		player.setFillColor(sf::Color::White);
	}
}



void drawlvl4(sf::RenderWindow& window, const std::vector<sf::Texture>& act4scenes)
{
	sf::RectangleShape ACT4_scene;
	ACT4_scene.setSize(sf::Vector2f(1920, 1080));



	if (currentact4scene == "Act4scene1")
	{
		ACT4_scene.setTexture(&act4scenes[0]);
	}
	else if (currentact4scene == "Act4scene2")
	{
		ACT4_scene.setTexture(&act4scenes[1]);

	}
	else if (currentact4scene == "Act4scene3")
	{
		ACT4_scene.setTexture(&act4scenes[2]);
	}
	else if (currentact4scene == "")
	{
		currentact4scene = "Act4scene1";
	}

	window.draw(ACT4_scene);
}

void rungmaeplay4(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls, sf::Clock& countdownClock, sf::Text& countdownText, float countdownDuration)
{
	window.clear(sf::Color(128, 128, 128));

	if (walls.empty())
	{
		std::fstream mazefile;
		mazefile.open("assets\\mazes\\maze5.txt", std::ios::in); // read file
		if (mazefile.is_open())
		{
			std::string line;
			while (getline(mazefile, line))
			{
				std::istringstream iss(line);
				std::string x_str, y_str;
				if (getline(iss, x_str, ',') && getline(iss, y_str)) // split coordinates using ',' 
				{
					float x = std::stof(x_str);
					float y = std::stof(y_str);
					sf::RectangleShape wall(sf::Vector2f(60.f, 60.f));
					wall.setPosition({ x, y });
					wall.setFillColor(sf::Color::Black);
					walls.push_back(wall);
				}
			}
			mazefile.close();
		}
		countdownClock.restart(); // Start countdown when entering gameplay4
	}

	float remainingTime = countdownDuration - countdownClock.getElapsedTime().asSeconds();
	if (remainingTime > 0) {
		countdownText.setString("Time left: " + std::to_string(static_cast<int>(remainingTime + 0.5f)));
		timeSup = false;
	}
	else {
		countdownText.setString("Time left: 0");
		timeSup = true;
	}

	sf::Vector2f startPos = { 30.f, 30.f };

	if (player.getGlobalBounds().findIntersection(next_door.getGlobalBounds()) && !timeSup)
	{
		currentState = "lvl5";
		player.setPosition(startPos);
		player.setFillColor(sf::Color::White);
	}
	if (timeSup)
	{
		player.setPosition(startPos);
		countdownClock.restart(); // Restart countdown on early attempt
	}

}


void drawlvl5(sf::RenderWindow& window, const std::vector<sf::Texture>& act4scenes)
{
	sf::RectangleShape ACT5_scene;
	ACT5_scene.setSize(sf::Vector2f(1920, 1080));



	if (currentact5scene == "Act5scene1")
	{
		ACT5_scene.setTexture(&act4scenes[3]);
	}
	else if (currentact5scene == "Act5scene2")
	{
		ACT5_scene.setTexture(&act4scenes[4]);

	}
	else if (currentact5scene == "Act5scene3")
	{
		ACT5_scene.setTexture(&act4scenes[5]);
	}
	else if (currentact5scene == "")
	{
		currentact5scene = "Act5scene1";
	}

	window.draw(ACT5_scene);
}

void rungameplay5(sf::RenderWindow& window, sf::RectangleShape& player, sf::Font& font)
{
	window.clear(sf::Color(128, 128, 128));
	// draw game finished image with able to roam freely
	sf::Text Ftxt(font, "ALL EFFORTS WERE IN VAIN AND YOU BROUGHT THE APOCALYPSE...", 70);
	sf::FloatRect bounds = Ftxt.getGlobalBounds();
	Ftxt.setOrigin({ bounds.position.x + bounds.size.x / 2, bounds.position.y + bounds.size.y / 2 });
	Ftxt.setPosition({ 1920.f / 2 , 1080.f / 2 });

	if (player.getGlobalBounds().findIntersection(Ftxt.getGlobalBounds()))
	{
		Ftxt.setFillColor(sf::Color::Red);
	}
	else
	{
		Ftxt.setFillColor(sf::Color::Black);
	}



	window.draw(Ftxt);
}


