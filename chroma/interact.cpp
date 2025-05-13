#include <iostream>
#include <vector>
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


#include "global.h"
#include "func.h"



void interactmenu(const sf::Vector2f& mouse_pos, sf::Text& startbutton, sf::Text& helpbutton, sf::Text& creditsbutton, sf::Text& exitbutton)
{
	//-----------START BUTTON--------------
	if (startbutton.getGlobalBounds().contains(mouse_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			startbutton.setFillColor(sf::Color::Cyan);
			currentState = "startgame";


		}
		else {
			startbutton.setString("-> START <-");
			startbutton.setFillColor(sf::Color::Black);
			startbutton.setPosition({ 900.f, 400.f });
		}
	}
	else {
		startbutton.setFillColor(sf::Color::White);
	}
	//------------HELP BUTTON--------------
	if (helpbutton.getGlobalBounds().contains(mouse_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			helpbutton.setFillColor(sf::Color::Cyan);
			currentState = "help";


		}
		else {
			helpbutton.setString("-> HELP <-");
			helpbutton.setFillColor(sf::Color::Black);
			helpbutton.setPosition({ 900.f, 550.f });
		}
	}
	else {
		helpbutton.setFillColor(sf::Color::White);
	}
	//------------CREDITS BUTTON-------------
	if (creditsbutton.getGlobalBounds().contains(mouse_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			creditsbutton.setFillColor(sf::Color::Cyan);
			currentState = "credits";


		}
		else {
			creditsbutton.setString("-> CREDITS <-");
			creditsbutton.setFillColor(sf::Color::Black);
			creditsbutton.setPosition({ 900.f, 700.f });
		}
	}
	else {
		creditsbutton.setFillColor(sf::Color::White);
	}
	//------------EXIT BUTTON-------------
	if (exitbutton.getGlobalBounds().contains(mouse_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			exitbutton.setFillColor(sf::Color::Cyan);
			currentState = "exitgame";
		}
		else {
			exitbutton.setString("-> EXIT <-");
			exitbutton.setFillColor(sf::Color::Black);
			exitbutton.setPosition({ 900.f, 850.f });
		}
	}
	else {
		exitbutton.setFillColor(sf::Color::White);
	}

	/*startbutton.setFillColor(startbutton.getGlobalBounds().contains(mouse_pos) ? sf::Color::Black : sf::Color::White);
	helpbutton.setFillColor(helpbutton.getGlobalBounds().contains(mouse_pos) ? sf::Color::Black : sf::Color::White);
	creditsbutton.setFillColor(creditsbutton.getGlobalBounds().contains(mouse_pos) ? sf::Color::Black : sf::Color::White);*/

}

void interactlvls(const sf::Vector2f& mouse_pos, sf::Text& lvlt1, sf::Text& lvlt2, sf::Text& lvlt3, sf::Text& lvlt4)
{
	//-----------lvl1 BUTTON--------------
	if (lvlt1.getGlobalBounds().contains(mouse_pos))
	{
		if (!lvl1locked && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			lvlt1.setFillColor(sf::Color::Cyan);
			selectedlvl = "lvl1";
			currentState = selectedlvl;
			currentact1scene = "Act1scene1";
			currentSUBState = "";

		}
		else {
			lvlt1.setFillColor(sf::Color::Black);
		}
	}
	else {
		lvlt1.setFillColor(sf::Color::White);
	}
	//------------lvl2 BUTTON--------------
	if (lvlt2.getGlobalBounds().contains(mouse_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			lvlt2.setFillColor(sf::Color::Cyan);
			if (!lvl2locked)
			{
				selectedlvl = "lvl2";
				currentState = selectedlvl;
				currentact2scene = "Act2scene1";
				currentSUBState = "";
			}

		}
		else {
			lvlt2.setFillColor(sf::Color::Black);
		}
	}
	else {
		lvlt2.setFillColor(sf::Color::White);
	}
	//------------lvl3 BUTTON-------------
	if (lvlt3.getGlobalBounds().contains(mouse_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			lvlt3.setFillColor(sf::Color::Cyan);
			if (!lvl3locked)
			{
				selectedlvl = "lvl3";
				currentState = selectedlvl;
				currentact3scene = "Act3scene1";
				currentSUBState = "";

			}
		}
		else {
			lvlt3.setFillColor(sf::Color::Black);
		}
	}
	else {
		lvlt3.setFillColor(sf::Color::White);
	}
	//------------lvl4 BUTTON-------------
	if (lvlt4.getGlobalBounds().contains(mouse_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			lvlt4.setFillColor(sf::Color::Cyan);
			if (!lvl4locked)
			{
				selectedlvl = "lvl4";
				currentState = selectedlvl;
				currentact4scene = "Act4scene1";
				currentSUBState = "";

			}

		}
		else {
			lvlt4.setFillColor(sf::Color::Black);
		}
	}
	else {
		lvlt4.setFillColor(sf::Color::White);
	}
}



std::vector <std::string> lvls{ "lvl1","lvl2","lvl3","lvl4","lvl5" };

void interactState()
{
	auto it = find(lvls.begin(), lvls.end(), currentState);

	if (it != lvls.end())
	{
		currentState = "startgame";
		currentact1scene = "Act1scene1";
	}
	else
	{
		currentState = "mainmenu";
	}

}


//----------------------------------------- LVL1 ---------------------------------

std::vector <std::string> lvl1scenes{ "Act1scene1","Act1scene2","Act1scene3" };


void interactlvl1scenesFORWARD()
{
	if (currentact1scene == "Act1scene1")
	{
		currentact1scene = "Act1scene2";
	}
	else if (currentact1scene == "Act1scene2")
	{
		currentact1scene = "Act1scene3";
	}
	else if (currentact1scene == "Act1scene3")
	{
		currentSUBState = "gameplay1";
	}
	else
	{
		currentact1scene = "Act1scene1";
	}

}


void interactlvl1scenesBACKWARD()
{
	auto it = find(lvl1scenes.begin(), lvl1scenes.end(), currentact1scene);

	if (it != lvl1scenes.end())
	{
		if (currentact1scene == "Act1scene1")
		{
			currentState = "startgame";
			currentact1scene = "";
		}
		else
		{
			currentact1scene = lvl1scenes[(it - lvl1scenes.begin() - 1)];
		}
	}

}

//---------------------------------------------------------------------------------------

//------------------------------------------ LVL2 ----------------------------------------

std::vector <std::string> lvl2scenes{ "Act2scene1","Act2scene2","Act2scene3","Act2scene4" };


void interactlvl2scenesFORWARD()
{
	if (currentact2scene == "Act2scene1")
	{
		currentact2scene = "Act2scene2";
	}
	else if (currentact2scene == "Act2scene2")
	{
		currentact2scene = "Act2scene3";
	}
	else if (currentact2scene == "Act2scene3")
	{
		currentact2scene = "Act2scene4";
	}
	else if (currentact2scene == "Act2scene4")
	{
		currentSUBState = "gameplay2";
	}
	else
	{
		currentact2scene = "Act2scene1";
	}
}


void interactlvl2scenesBACKWARD()
{
	auto it = find(lvl2scenes.begin(), lvl2scenes.end(), currentact2scene);

	if (it != lvl2scenes.end())
	{
		if (currentact2scene == "Act2scene1")
		{
			currentState = "startgame";
			currentact2scene = "";
		}
		else
		{
			currentact2scene = lvl2scenes[(it - lvl2scenes.begin() - 1)];
		}
	}

}

//----------------------------------------------------------------------------------


//------------------------------------------ LVL3 ----------------------------------------

std::vector <std::string> lvl3scenes{ "Act3scene1","Act3scene2","Act3scene3","Act3scene4" };


void interactlvl3scenesFORWARD()
{
	if (currentact3scene == "Act3scene1")
	{
		currentact3scene = "Act3scene2";
	}
	else if (currentact3scene == "Act3scene2")
	{
		currentact3scene = "Act3scene3";
	}
	else if (currentact3scene == "Act3scene3")
	{
		currentact3scene = "Act3scene4";
	}
	else if (currentact3scene == "Act3scene4")
	{
		currentSUBState = "gameplay3";
	}
	else
	{
		currentact3scene = "Act3scene1";
	}
}


void interactlvl3scenesBACKWARD()
{
	auto it = find(lvl3scenes.begin(), lvl3scenes.end(), currentact3scene);

	if (it != lvl3scenes.end())
	{
		if (currentact3scene == "Act3scene1")
		{
			currentState = "startgame";
			currentact3scene = "";
		}
		else
		{
			currentact3scene = lvl3scenes[(it - lvl3scenes.begin() - 1)];
		}
	}

}

//----------------------------------------------------------------------------------


//----------------------------------------- LVL4 ---------------------------------

std::vector <std::string> lvl4scenes{ "Act4scene1","Act4scene2","Act4scene3" };


void interactlvl4scenesFORWARD()
{
	if (currentact4scene == "Act4scene1")
	{
		currentact4scene = "Act4scene2";
	}
	else if (currentact4scene == "Act4scene2")
	{
		currentact4scene = "Act4scene3";
	}
	else if (currentact4scene == "Act4scene3")
	{
		currentSUBState = "gameplay4";
	}
	else
	{
		currentact4scene = "Act4scene1";
	}

}


void interactlvl4scenesBACKWARD()
{
	auto it = find(lvl4scenes.begin(), lvl4scenes.end(), currentact4scene);

	if (it != lvl4scenes.end())
	{
		if (currentact4scene == "Act4scene1")
		{
			currentState = "startgame";
			currentact4scene = "";
		}
		else
		{
			currentact4scene = lvl4scenes[(it - lvl4scenes.begin() - 1)];
		}
	}

}

//---------------------------------------------------------------------------------------


//----------------------------------------- LVL5 ---------------------------------

std::vector <std::string> lvl5scenes{ "Act5scene1","Act5scene2","Act5scene3" };


void interactlvl5scenesFORWARD()
{
	if (currentact5scene == "Act5scene1")
	{
		currentact5scene = "Act5scene2";
	}
	else if (currentact5scene == "Act5scene2")
	{
		currentact5scene = "Act5scene3";
	}
	else if (currentact5scene == "Act5scene3")
	{
		currentSUBState = "gamefinished";
	}
	else
	{
		currentact5scene = "Act5scene1";
	}

}


void interactlvl5scenesBACKWARD()
{
	auto it = find(lvl5scenes.begin(), lvl5scenes.end(), currentact5scene);

	if (it != lvl5scenes.end())
	{
		if (currentact5scene == "Act5scene1")
		{
			currentState = "startgame";
			currentact5scene = "";
		}
		else
		{
			currentact5scene = lvl5scenes[(it - lvl5scenes.begin() - 1)];
		}
	}

}

//---------------------------------------------------------------------------------------
std::vector <std::string> subSTATES{ "gameplay1","gameplay2","gameplay3" ,"gameplay4","gamefinished" };

void interactSUBSTATEBACKWARD()
{
	auto it = find(subSTATES.begin(), subSTATES.end(), currentSUBState);
	if ((it != subSTATES.end()) && (currentSUBState != "gamefinished"))
	{
		currentState = "startgame";
		currentSUBState = "";
	}
	else
	{
		currentState = "mainmenu";
		currentSUBState = "";
	}
}




//void interactplayer(sf::RectangleShape& player, float speed,float dt,const std::vector<sf::RectangleShape>& walls, sf::Vector2f& startPos)
//{
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
//		player.setPosition({player.getPosition().x -speed*dt, player.getPosition().y});
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) 
//		//player.move({ speed,0.f });
//		player.setPosition({ player.getPosition().x + speed*dt, player.getPosition().y });
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) 
//		//player.move({ 0.f,-speed});
//		player.setPosition({ player.getPosition().x , player.getPosition().y - speed*dt });
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
//		//player.move({ 0.f,speed });
//		player.setPosition({ player.getPosition().x , player.getPosition().y + speed*dt });
//	
//	// not a great solution movement is very slow or jittery 
//
//	for (const auto& wall : walls)
//	{
//		if (player.getGlobalBounds().findIntersection(wall.getGlobalBounds()))
//		{
//			player.setPosition(startPos);
//		}
//	}
//
//}

//void interactplayer(sf::RectangleShape& player, float speed, float dt, const std::vector<sf::RectangleShape>& walls)
//{
//	// Calculate total movement for this frame
//	sf::Vector2f movement(0.f, 0.f);
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
//		movement.x -= speed * dt;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
//		movement.x += speed * dt;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
//		movement.y -= speed * dt;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
//		movement.y += speed * dt;
//
//	// Store current position
//	sf::Vector2f oldPos = player.getPosition();
//
//	// Apply horizontal movement and check collision
//	player.move({ movement.x, 0.f });
//	for (const auto& wall : walls)
//	{
//		if (player.getGlobalBounds().findIntersection(wall.getGlobalBounds()))
//		{
//			player.setPosition({ oldPos.x, player.getPosition().y }); // Revert X movement
//			break;
//		}
//	}
//
//	// Apply vertical movement and check collision
//	player.move({ 0.f, movement.y });
//	for (const auto& wall : walls)
//	{
//		if (player.getGlobalBounds().findIntersection(wall.getGlobalBounds()))
//		{
//			player.setPosition({ player.getPosition().x, oldPos.y }); // Revert Y movement
//			break;
//		}
//	}
//}


//------------------------------------------------- PLAYER INTERACTIONS ---------------------------------------


void interactplayer(sf::RectangleShape& player, float speed, float dt, const std::vector<sf::RectangleShape>& walls, sf::Vector2f windowSize)
{

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) && (player.getFillColor() != sf::Color::White))
	{
		player.setFillColor(sf::Color::White);
	}

	// Calculate total movement for this frame

	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		movement.x -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		movement.x += speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		movement.y -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		movement.y += speed * dt;

	// Store current position
	sf::Vector2f oldPos = player.getPosition();

	// Apply horizontal movement and check collision
	player.move({ movement.x, 0.f });
	for (const auto& wall : walls)
	{
		if (player.getGlobalBounds().findIntersection(wall.getGlobalBounds()))
		{
			player.setPosition({ oldPos.x, player.getPosition().y }); // Revert X movement
			break;
		}
	}

	// Apply vertical movement and check collision
	player.move({ 0.f, movement.y });
	for (const auto& wall : walls)
	{
		if (player.getGlobalBounds().findIntersection(wall.getGlobalBounds()))
		{
			player.setPosition({ player.getPosition().x, oldPos.y }); // Revert Y movement
			break;
		}
	}

	// Clamp player position within window borders
	sf::Vector2f pos = player.getPosition();
	sf::Vector2f playerSize = player.getSize();

	// Clamp x-axis
	if (pos.x < 0)
		pos.x = 0;
	else if (pos.x + playerSize.x > windowSize.x)
		pos.x = windowSize.x - playerSize.x;

	// Clamp y-axis
	if (pos.y < 0)
		pos.y = 0;
	else if (pos.y + playerSize.y > windowSize.y)
		pos.y = windowSize.y - playerSize.y;

	player.setPosition(pos);
}

void interactplayerF(sf::RectangleShape& player, float speed, float dt, const sf::RenderWindow& window)
{
	// Calculate total movement for this frame
	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		movement.x -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		movement.x += speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		movement.y -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		movement.y += speed * dt;

	// Apply movement in one step
	player.move(movement);

	// Clamp player position within window borders
	sf::Vector2f playerSize = player.getSize();
	sf::Vector2u windowSize = window.getSize();
	float minX = 0.f;
	float maxX = static_cast<float>(windowSize.x) - playerSize.x;
	float minY = 0.f;
	float maxY = static_cast<float>(windowSize.y) - playerSize.y;

	sf::Vector2f pos = player.getPosition();
	if (pos.x < minX) pos.x = minX;
	if (pos.x > maxX) pos.x = maxX;
	if (pos.y < minY) pos.y = minY;
	if (pos.y > maxY) pos.y = maxY;

	player.setPosition(pos);
}

void interactplayerBOMBS(sf::RectangleShape& player, std::vector<sf::RectangleShape>& placements, std::vector<sf::RectangleShape>& bombs, sf::Texture& bombT)
{
	if (!havingBOMB)
	{
		for (auto& bomb : bombs)
		{
			if (player.getGlobalBounds().findIntersection(bomb.getGlobalBounds())) {
				removeRectangle(bombs, bomb);
				havingBOMB = true;
				break;
			}
		}
	}
	else {
		//for (auto& place : placements)
		for (size_t i = 0; i < placements.size(); ++i)
		{
			if (placements[i].getTexture() != &bombT && player.getGlobalBounds().findIntersection(placements[i].getGlobalBounds()))
			{
				placements[i].setTexture(&bombT);
				havingBOMB = false;
				break;
			}
		}
	}
}

void interactplayerCOLORbloc(sf::RectangleShape& player, sf::RectangleShape& color, sf::RectangleShape& colorbloc)
{
	if (player.getGlobalBounds().findIntersection(color.getGlobalBounds()))
	{
		player.setFillColor(color.getFillColor());
	}

	sf::Vector2f startPos = { 20.f,30.f };
	if (player.getGlobalBounds().findIntersection(colorbloc.getGlobalBounds()))
	{
		if (player.getFillColor() != colorbloc.getFillColor())
		{
			player.setPosition(startPos);
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------