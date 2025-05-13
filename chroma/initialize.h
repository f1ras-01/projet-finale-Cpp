#pragma once

//------------------------ INITIALIZE GAME HANDLING ---------------------


void initializefont(sf::Font& font);

void initializeScenes1(std::vector<sf::Texture>& act1scenes);

void initializeScenes2(std::vector<sf::Texture>& act2scenes);

void initializeScenes3(std::vector<sf::Texture>& act3scenes);

void initializeScenes4(std::vector<sf::Texture>& act4scenes);


void initializehelpicons(std::vector<sf::Texture>& helpicons);

void initializefiles(std::vector<std::string>& helpLines, std::vector<std::string>& creditsLines);

void initializeT(std::vector<sf::Texture>& Tss);

void initializeBombs(std::vector<sf::RectangleShape>& bombs, sf::Texture& bombT/*, std::vector<char>& placementOccupied*/);

void intializeplacements(std::vector<sf::RectangleShape>& placements);




