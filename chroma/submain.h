#pragma once

//------------------- MAIN GAME STATES HANDLING ------------------------


void drawmenu(sf::RenderWindow& window, sf::Font& font);

void drawlvls(sf::RenderWindow& window, sf::Font& font, sf::Texture& startgameT);

void drawhelp(sf::RenderWindow& window, sf::Font& font, std::vector<sf::Texture>& helpicons, std::vector<std::string>& helpLines);

void drawcredits(sf::RenderWindow& window, sf::Font& font, std::vector<std::string>& creditslines);



//-------------------------- LVL HANDLING -----------------------------


void drawlvl1(sf::RenderWindow& window, const std::vector<sf::Texture>& act1scenes);

void rungmaeplay1(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls);


void drawlvl2(sf::RenderWindow& window, const std::vector<sf::Texture>& act2scenes);

void rungmaeplay2(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls);



void drawlvl3(sf::RenderWindow& window, const std::vector<sf::Texture>& act3scenes);

void rungmaeplay3(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls);



void drawlvl4(sf::RenderWindow& window, const std::vector<sf::Texture>& act4scenes);

void rungmaeplay4(sf::RenderWindow& window, sf::RectangleShape& player, sf::RectangleShape& next_door, std::vector<sf::RectangleShape>& walls, sf::Clock& countdownClock, sf::Text& countdownText, float countdownDuration);


void drawlvl5(sf::RenderWindow& window, const std::vector<sf::Texture>& act4scenes);

void rungameplay5(sf::RenderWindow& window, sf::RectangleShape& player, sf::Font& font);









