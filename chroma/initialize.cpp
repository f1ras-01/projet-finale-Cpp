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







//------------------------ INITIALIZE GAME ---------------------

void initializefont(sf::Font& font)
{
	if (!font.openFromFile("assets\\font\\Kingneverdie.ttf"))
	{
		std::cerr << "Failed to load font\n";
	}
}

void initializeScenes1(std::vector<sf::Texture>& act1scenes)
{
	/*sf::Texture Act1scene1T;
	sf::Texture Act1scene2T;
	sf::Texture Act1scene3T;

	if (!Act1scene1T.loadFromFile("assets\\storyTellings\\ACT1_1st_scene.png"))
	{
		std::cerr << "Failed to load scene\n";

	}
	else
	{
		act1scenes.push_back(Act1scene1T);
	}

	if (!Act1scene2T.loadFromFile("assets\\storyTellings\\ACT1_2nd_scene.png"))
	{
		std::cerr << "Failed to load scene\n";

	}
	else
	{
		act1scenes.push_back(Act1scene2T);
	}

	if (!Act1scene3T.loadFromFile("assets\\storyTellings\\ACT1_3rd_scene.png"))
	{
		std::cerr << "Failed to load scene\n";

	}
	else
	{
		act1scenes.push_back(Act1scene3T);
	}*/

	const std::vector<std::string> sceneFiles = {

		"assets\\storyTellings\\ACT1\\ACT1_1st_scene.png",
		"assets\\storyTellings\\ACT1\\ACT1_2nd_scene.png",
		"assets\\storyTellings\\ACT1\\ACT1_3rd_scene.png"

	};

	for (const auto& file : sceneFiles) {
		sf::Texture texture;
		if (!texture.loadFromFile(file)) {
			std::cerr << "Failed to load scene: " << file << std::endl;
		}
		else {
			act1scenes.push_back(texture);
		}
	}
}

void initializeScenes2(std::vector<sf::Texture>& act2scenes)
{
	/*sf::Texture Act1scene1T;
	sf::Texture Act1scene2T;
	sf::Texture Act1scene3T;

	if (!Act1scene1T.loadFromFile("assets\\storyTellings\\ACT1_1st_scene.png"))
	{
		std::cerr << "Failed to load scene\n";

	}
	else
	{
		act1scenes.push_back(Act1scene1T);
	}

	if (!Act1scene2T.loadFromFile("assets\\storyTellings\\ACT1_2nd_scene.png"))
	{
		std::cerr << "Failed to load scene\n";

	}
	else
	{
		act1scenes.push_back(Act1scene2T);
	}

	if (!Act1scene3T.loadFromFile("assets\\storyTellings\\ACT1_3rd_scene.png"))
	{
		std::cerr << "Failed to load scene\n";

	}
	else
	{
		act1scenes.push_back(Act1scene3T);
	}*/

	const std::vector<std::string> sceneFiles = {

		"assets\\storyTellings\\ACT2\\ACT2_1st_scene.png",
		"assets\\storyTellings\\ACT2\\ACT2_2nd_scene.png",
		"assets\\storyTellings\\ACT2\\ACT2_3rd_scene.png",
		"assets\\storyTellings\\ACT2\\ACT2_4th_scene.png"

	};

	for (const auto& file : sceneFiles) {
		sf::Texture texture;
		if (!texture.loadFromFile(file)) {
			std::cerr << "Failed to load scene: " << file << std::endl;
		}
		else {
			act2scenes.push_back(texture);
		}
	}
}

void initializeScenes3(std::vector<sf::Texture>& act3scenes)
{


	const std::vector<std::string> sceneFiles = {

		"assets\\storyTellings\\ACT3\\ACT3_1st_scene.png",
		"assets\\storyTellings\\ACT3\\ACT3_2nd_scene.png",
		"assets\\storyTellings\\ACT3\\ACT3_3rd_scene.png",
		"assets\\storyTellings\\ACT3\\ACT3_4th_scene.png"

	};

	for (const auto& file : sceneFiles) {
		sf::Texture texture;
		if (!texture.loadFromFile(file)) {
			std::cerr << "Failed to load scene: " << file << std::endl;
		}
		else {
			act3scenes.push_back(texture);
		}
	}
}

void initializeScenes4(std::vector<sf::Texture>& act4scenes)
{

	const std::vector<std::string> sceneFiles = {

		"assets\\storyTellings\\ACT4\\ACT4_1st_scene.png",
		"assets\\storyTellings\\ACT4\\ACT4_2nd_scene.png",
		"assets\\storyTellings\\ACT4\\ACT4_3rd_scene.png",
		"assets\\storyTellings\\ACT4\\ACT4_4th_scene.png",
		"assets\\storyTellings\\ACT4\\ACT4_5th_scene.png",
		"assets\\storyTellings\\ACT4\\ACT4_6th_scene.png"

	};

	for (const auto& file : sceneFiles) {
		sf::Texture texture;
		if (!texture.loadFromFile(file)) {
			std::cerr << "Failed to load scene: " << file << std::endl;
		}
		else {
			act4scenes.push_back(texture);
		}
	}
}

void initializehelpicons(std::vector<sf::Texture>& helpicons)
{


	const std::vector<std::string> sceneFiles = {
		"assets\\help icons\\arrow keys.jpg",
		"assets\\help icons\\spacebar key.jpg",
		"assets\\help icons\\enter key.jpg",
		"assets\\help icons\\mouseleft key.jpg",
		"assets\\help icons\\backspace key.jpg"
	};

	for (const auto& file : sceneFiles) {
		sf::Texture texture;
		if (!texture.loadFromFile(file)) {
			std::cerr << "Failed to load texture: " << file << std::endl;
		}
		else {
			helpicons.push_back(texture);
		}
	}
}

void initializefiles(std::vector<std::string>& helpLines, std::vector<std::string>& creditsLines)
{
	std::fstream file1;
	std::fstream file2;

	file1.open("assets\\texts\\help.txt", std::ios::in); // read
	if (file1.is_open())
	{
		std::string line;
		while (getline(file1, line))
		{
			helpLines.push_back(line);
		}
		file1.close();
	}

	file2.open("assets\\texts\\credits.txt", std::ios::in); // read
	if (file2.is_open())
	{
		std::string line;
		while (getline(file2, line))
		{
			creditsLines.push_back(line);
		}
		file2.close();
	}
}

void initializeT(std::vector<sf::Texture>& Tss)
{
	const std::vector<std::string> sceneFiles = {

		"assets\\textures\\bomb.png",
		"assets\\textures\\startgame.png"

	};

	for (const auto& file : sceneFiles) {
		sf::Texture texture;
		if (!texture.loadFromFile(file)) {
			std::cerr << "Failed to load scene: " << file << std::endl;
		}
		else {
			Tss.push_back(texture);
		}
	}
}

void initializeBombs(std::vector<sf::RectangleShape>& bombs, sf::Texture& bombT)
{
	bombs.clear();

	sf::RectangleShape bomb1(sf::Vector2f(50, 50));
	bomb1.setPosition({ 1080.f, 120.f });
	bomb1.setTexture(&bombT);
	bombs.push_back(bomb1);

	sf::RectangleShape bomb2(sf::Vector2f(50, 50));
	bomb2.setPosition({ 240.f, 720.f });
	bomb2.setTexture(&bombT);
	bombs.push_back(bomb2);

	sf::RectangleShape bomb3(sf::Vector2f(50, 50));
	bomb3.setPosition({ 600.f, 120.f });
	bomb3.setTexture(&bombT);
	bombs.push_back(bomb3);
}

void intializeplacements(std::vector<sf::RectangleShape>& placements)
{
	placements.clear();

	sf::RectangleShape place1;
	place1.setSize(sf::Vector2f(50, 50));
	place1.setFillColor(sf::Color(169, 169, 169));
	place1.setPosition(sf::Vector2f{ 1680.f,120.f });


	sf::RectangleShape place2;
	place2.setSize(sf::Vector2f(50, 50));
	place2.setFillColor(sf::Color(169, 169, 169));
	place2.setPosition(sf::Vector2f{ 0.f,120.f });


	sf::RectangleShape place3;
	place3.setSize(sf::Vector2f(50, 50));
	place3.setFillColor(sf::Color(169, 169, 169));
	place3.setPosition(sf::Vector2f{ 1440.f,360.f });


	placements.push_back(place1);
	placements.push_back(place2);
	placements.push_back(place3);
}
