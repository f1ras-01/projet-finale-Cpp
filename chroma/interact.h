#pragma once


void interactmenu(const sf::Vector2f& mouse_pos, sf::Text& startbutton, sf::Text& helpbutton, sf::Text& creditsbutton, sf::Text& exitbutton);

void interactlvls(const sf::Vector2f& mouse_pos, sf::Text& lvlt1, sf::Text& lvlt2, sf::Text& lvlt3, sf::Text& lvlt4);

void interactState();

void interactSUBSTATEBACKWARD();


//--------------------- LVL1 -------------------------

void interactlvl1scenesFORWARD();

void interactlvl1scenesBACKWARD();

//--------------------- LVL2 ---------------------------

void interactlvl2scenesFORWARD();

void interactlvl2scenesBACKWARD();

//--------------------- LVL3 ---------------------------

void interactlvl3scenesFORWARD();

void interactlvl3scenesBACKWARD();

//--------------------- LVL4 ---------------------------

void interactlvl4scenesFORWARD();

void interactlvl4scenesBACKWARD();

//--------------------- LVL5 ---------------------------

void interactlvl5scenesFORWARD();

void interactlvl5scenesBACKWARD();

//-------------------------------------------------------


//------------------------------------------------- PLAYER INTERACTIONS ---------------------------------------

void interactplayer(sf::RectangleShape& player, float speed, float dt, const std::vector<sf::RectangleShape>& walls, sf::Vector2f windowSize);


void interactplayerF(sf::RectangleShape& player, float speed, float dt, const sf::RenderWindow& window);


void interactplayerBOMBS(sf::RectangleShape& player, std::vector<sf::RectangleShape>& placements, std::vector<sf::RectangleShape>& bombs, sf::Texture& bombT /*,std::vector<char>& placementOccupied*/);

void interactplayerCOLORbloc(sf::RectangleShape& player, sf::RectangleShape& color, sf::RectangleShape& colorbloc);

//-----------------------------------------------------------------------------------------------------------------------#pragma once
