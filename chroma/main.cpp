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
#include <SFML/Network.hpp>


#include "submain.h"
#include "interact.h"
#include "lvlsgameplay.h"
#include "global.h"
#include "initialize.h"
#include "func.h"




int main()
{
    //------------------------ INITIALIZE GAME ---------------------


    // MAKE A  WINDOW
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "CHROMA", sf::Style::Default, sf::State::Fullscreen, settings);

    // SET FRAME RATE
    window.setFramerateLimit(60);

    // SET VERTICAL SYNC
    window.setVerticalSyncEnabled(true);

    // CREATE DT
    sf::Clock dtClock;
    float dt;




    // CREATE THE CREDITS VIEW
    sf::View view({ 960.f, 540.f }, { 1920.f, 1080.f });


    // Game view (zoomed in 3x)
    sf::View gameView;
    gameView.setSize({ 1960.f / 3, 1080.f / 3 }); // Third of 1920x1080 for 2x zoom
    gameView.setViewport(sf::FloatRect({ 0.f, 0.f }, { 1.f, 1.f }));

    // Minimap view
    sf::View minimapView;
    minimapView.setSize({ 1920.f, 1080.f }); // Full level size
    minimapView.setCenter({ 1920.f / 2, 1080.f / 2 });
    minimapView.setViewport(sf::FloatRect({ 0.75f, 0.f }, { 0.25f, 0.25f })); // Top-right corner

    // Minimap background
    sf::RectangleShape minimapBackground(sf::Vector2f(1920.f, 1080.f));
    minimapBackground.setPosition({ 0.f, 0.f });


    //-------------------------- INITIALIZE GAME -------------------------

    // LOAD MUSIC
    sf::Music music;
    if (!music.openFromFile("assets\\music\\Sabre.ogg"))
    {
        std::cerr << "Failed to load music\n";
    }
    music.setLooping(true);
    music.setVolume(50.f);
    music.play();


    // FONT
    sf::Font font;
    initializefont(font);

    //  CREATE COUNTDOWN

    sf::Clock countdownClock;
    sf::Text countdownText(font, "", 60);
    countdownText.setFillColor(sf::Color::Red);
    countdownText.setPosition({ 10.f, 10.f }); // Top-left corner
    float countdownDuration = 120.f; // 120 seconds countdown

    // SCENES TEXTURES
    std::vector<sf::Texture> act1scenes;
    initializeScenes1(act1scenes);

    std::vector<sf::Texture> act2scenes;
    initializeScenes2(act2scenes);

    std::vector<sf::Texture> act3scenes;
    initializeScenes3(act3scenes);

    std::vector<sf::Texture> act4scenes;
    initializeScenes4(act4scenes);

    std::vector<sf::Texture> Tss;
    initializeT(Tss);




    // HELP ICONS TEXTURES
    std::vector<sf::Texture> helpicons;
    initializehelpicons(helpicons);

    // TEXT FILES 
    std::vector<std::string> helpLines, creditsLines;
    initializefiles(helpLines, creditsLines);




    //------------------------------- CREATE A PLAYER -----------------------------------------

    sf::RectangleShape player(sf::Vector2f(30.f, 30.f));
    player.setFillColor(sf::Color::White);
    sf::Vector2f startPos = { 30.f,30.f };
    float playerSpeed = 250.f;
    //float playerSpeed = 500.f;

    //--------------------------------------------------------------------------------------------

    // CREATE WALLS
    std::vector<sf::RectangleShape> walls1;    // List of walls
    std::vector<sf::RectangleShape> walls2;
    std::vector<sf::RectangleShape> walls3;
    std::vector<sf::RectangleShape> walls4;


    // CREATE 1ST DOOR
    sf::RectangleShape door1;
    door1.setSize(sf::Vector2f(60, 60));
    door1.setFillColor(sf::Color::Blue);
    door1.setPosition(sf::Vector2f{ 1560.f,840.f });
    //door1.setPosition(sf::Vector2f{ 200.f,140.f });

    // CREATE 2nd DOOR
    sf::RectangleShape door2;
    door2.setSize(sf::Vector2f(60, 60));
    door2.setFillColor(sf::Color::Blue);
    door2.setPosition(sf::Vector2f{ 1320.f,960.f });

    // CREATE BOMBS
    std::vector<sf::RectangleShape> bombs;

    // CREATE PLACEMENTS
    std::vector<sf::RectangleShape> placements;


    // CREATE 3rd DOOR
    sf::RectangleShape door3;
    door3.setSize(sf::Vector2f(60, 60));
    door3.setFillColor(sf::Color::Blue);
    door3.setPosition(sf::Vector2f{ 240.f,240.f });

    // CREATE COLOR
    sf::RectangleShape color;
    color.setSize(sf::Vector2f(40, 40));
    color.setFillColor(sf::Color::Green);
    color.setPosition(sf::Vector2f{ 1440.f,360.f });

    // CREATE COLOR BLOC
    sf::RectangleShape color_bloc;
    color_bloc.setSize(sf::Vector2f(60, 60));
    color_bloc.setFillColor(sf::Color::Green);
    color_bloc.setPosition(sf::Vector2f{ 540.f,360.f });


    // CREATE 4th DOOR
    sf::RectangleShape door4;
    door4.setSize(sf::Vector2f(60, 60));
    door4.setFillColor(sf::Color::Blue);
    door4.setPosition(sf::Vector2f{ 1200.f,120.f });

    // CREATE COLOR
    sf::RectangleShape color2;
    color2.setSize(sf::Vector2f(40, 40));
    color2.setFillColor(sf::Color::Red);
    color2.setPosition(sf::Vector2f{ 240.f,120.f });

    // CREATE COLOR BLOC
    sf::RectangleShape color_bloc2;
    color_bloc2.setSize(sf::Vector2f(60, 60));
    color_bloc2.setFillColor(sf::Color::Red);
    color_bloc2.setPosition(sf::Vector2f{ 660.f,960.f });

    //-----------------------------------------------------------------------------------------------



    //------------------------------------MAIN GAME LOOP---------------------------------------------
    while (window.isOpen())
    {
        //------------------------------- UPDATES AND ALL -----------------------------------------

        //update the dt variable with the time it takes to update and render one frame
        dt = dtClock.restart().asSeconds();


        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (currentState == "credits")
            {

                // create a view with its center and size
                if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
                {
                    if (mouseWheelScrolled->wheel == sf::Mouse::Wheel::Vertical)
                    {

                        // Adjust view position based on scroll direction
                        // Positive delta = scroll up, negative delta = scroll down
                        float newY = view.getCenter().y - mouseWheelScrolled->delta * 700.f * dt;
                        view.setCenter({ view.getCenter().x, std::clamp(newY,540.f,1600.f) });  // Multiply by scroll sensitivity

                    }
                }
            }
            else if (currentState == "help")
            {

                // create a view with its center and size
                if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
                {
                    if (mouseWheelScrolled->wheel == sf::Mouse::Wheel::Vertical)
                    {

                        // Adjust view position based on scroll direction
                        // Positive delta = scroll up, negative delta = scroll down
                        float newY = view.getCenter().y - mouseWheelScrolled->delta * 700.f * dt;
                        view.setCenter({ view.getCenter().x, std::clamp(newY,540.f,1700.f) });  // Multiply by scroll sensitivity

                    }
                }
            }
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyReleased->scancode == sf::Keyboard::Scan::Backspace)
                {
                    if (currentState == "lvl1")
                    {
                        setLVL1();
                    }
                    else if (currentState == "lvl2")// game states other than lvl states
                    {
                        setLVL2();
                    }
                    else if (currentState == "lvl3")// game states other than lvl states
                    {
                        setLVL3();
                    }
                    else if (currentState == "lvl4")// game states other than lvl states
                    {
                        setLVL4(walls4);
                    }
                    else if (currentState == "lvl5")// game states other than lvl states
                    {
                        setLVL5();
                    }
                    else if (currentState == "mainmenu")
                    {
                        window.close();
                    }
                    else
                    {
                        interactState();
                    }
                }
                if (currentState == "lvl1")
                {
                    if (keyReleased->scancode == sf::Keyboard::Scan::Enter)
                    {
                        interactlvl1scenesFORWARD();
                    }
                }
                else if (currentState == "lvl2")
                {
                    if (keyReleased->scancode == sf::Keyboard::Scan::Enter)
                    {
                        interactlvl2scenesFORWARD();
                    }
                }
                else if (currentState == "lvl3")
                {
                    if (keyReleased->scancode == sf::Keyboard::Scan::Enter)
                    {
                        interactlvl3scenesFORWARD();
                    }
                }
                else if (currentState == "lvl4")
                {
                    if (keyReleased->scancode == sf::Keyboard::Scan::Enter)
                    {
                        interactlvl4scenesFORWARD();
                    }
                }
                else if (currentState == "lvl5")
                {
                    if (keyReleased->scancode == sf::Keyboard::Scan::Enter)
                    {
                        interactlvl5scenesFORWARD();
                    }
                }
            }

        }

        // Clamp game view to world boundaries
        sf::Vector2f playerPos = player.getPosition();
        float viewWidth = gameView.getSize().x;
        float viewHeight = gameView.getSize().y;
        float minX = viewWidth / 2;
        float maxX = 1920.f - viewWidth / 2;
        float minY = viewHeight / 2;
        float maxY = 1080.f - viewHeight / 2;
        float clampedX = std::max(minX, std::min(playerPos.x, maxX));
        float clampedY = std::max(minY, std::min(playerPos.y, maxY));
        gameView.setCenter({ clampedX, clampedY });


        // clear the window with a specific color
        window.clear(sf::Color(128, 128, 128));

        // draw everything here

        if (currentState == "exitgame")
        {
            window.close();
        }
        else if (currentState == "startgame")
        {
            countdownClock.restart(); // Restart countdown
            bombsPlaced = false;
            intializeplacements(placements);
            initializeBombs(bombs, Tss[0]);  //reinitialize bombs
            currentact5scene = "Act5scene1";
            currentSUBState = "";
            player.setPosition(startPos);
            drawlvls(window, font, Tss[1]);
            // restore the default view
            window.setView(window.getDefaultView());

        }
        else if (currentState == "help")
        {
            drawhelp(window, font, helpicons, helpLines);
            window.setView(view);

        }
        else if (currentState == "credits")
        {
            drawcredits(window, font, creditsLines);
            window.setView(view);
        }
        else if (currentState == "lvl1")
        {

            window.setView(window.getDefaultView());
            drawlvl1(window, act1scenes);
            if (currentSUBState == "gameplay1")
            {

                window.setView(gameView);

                rungmaeplay1(window, player, door1, walls1);
                interactplayer(player, playerSpeed, dt, walls1, { 1920.f,1080.f });

                // Draw all walls
                for (const auto& wall : walls1)
                {
                    window.draw(wall);
                }
                window.draw(door1);
                window.draw(player);

                // Draw minimap border in screen coordinates
                window.setView(window.getDefaultView());
                sf::RectangleShape border(sf::Vector2f(480.f, 270.f)); // 1920*0.25, 1080*0.25
                border.setPosition({ 1920.f * 0.75f, 0.f });
                border.setFillColor(sf::Color(128, 128, 128));
                border.setOutlineColor(sf::Color::Blue);
                border.setOutlineThickness(3.f);
                window.draw(border);

                // Switch to minimap view and draw
                window.setView(minimapView);

                // Draw all walls
                for (const auto& wall : walls1)
                {
                    window.draw(wall);
                }
                window.draw(door1);
                window.draw(player);

            }

        }
        else if (currentState == "lvl2")
        {

            window.setView(window.getDefaultView());
            drawlvl2(window, act2scenes);
            if (currentSUBState == "gameplay2")
            {

                window.setView(gameView);

                rungmaeplay2(window, player, door2, walls2);
                interactplayer(player, playerSpeed, dt, walls2, { 1920.f,1080.f });
                interactplayerBOMBS(player, placements, bombs, Tss[0]);
                bombsplaced(bombs, placements, Tss[0]);

                // Draw all walls
                for (const auto& wall : walls2)
                {
                    window.draw(wall);
                }
                // Draw all placements
                for (const auto& place : placements)
                {
                    window.draw(place);
                }
                // Draw all bombs
                for (auto& bomb : bombs)
                {
                    window.draw(bomb);
                }
                window.draw(door2);
                window.draw(player);

                // Draw minimap border in screen coordinates
                window.setView(window.getDefaultView());
                sf::RectangleShape border(sf::Vector2f(480.f, 270.f)); // 1920*0.25, 1080*0.25
                border.setPosition({ 1920.f * 0.75f, 0.f });
                border.setFillColor(sf::Color(128, 128, 128));
                border.setOutlineColor(sf::Color::Blue);
                border.setOutlineThickness(3.f);
                window.draw(border);

                // Switch to minimap view and draw
                window.setView(minimapView);

                // Draw all walls
                for (const auto& wall : walls2)
                {
                    window.draw(wall);
                }
                // Draw all placements
                for (const auto& place : placements)
                {
                    window.draw(place);
                }
                // Draw all bombs
                for (auto& bomb : bombs)
                {
                    window.draw(bomb);
                }
                window.draw(door2);
                window.draw(player);
            }
        }
        else if (currentState == "lvl3")
        {
            window.setView(window.getDefaultView());
            drawlvl3(window, act3scenes);
            if (currentSUBState == "gameplay3")
            {

                window.setView(gameView);

                rungmaeplay3(window, player, door3, walls3);
                interactplayer(player, playerSpeed, dt, walls3, { 1920.f,1080.f });
                interactplayerCOLORbloc(player, color, color_bloc);

                // Draw all walls
                for (const auto& wall : walls3)
                {
                    window.draw(wall);
                }
                window.draw(door3);
                window.draw(color);
                window.draw(color_bloc);
                window.draw(player);

                // Draw minimap border in screen coordinates
                window.setView(window.getDefaultView());
                sf::RectangleShape border(sf::Vector2f(480.f, 270.f)); // 1920*0.25, 1080*0.25
                border.setPosition({ 1920.f * 0.75f, 0.f });
                border.setFillColor(sf::Color(128, 128, 128));
                border.setOutlineColor(sf::Color::Blue);
                border.setOutlineThickness(3.f);
                window.draw(border);

                // Switch to minimap view and draw
                window.setView(minimapView);

                // Draw all walls
                for (const auto& wall : walls3)
                {
                    window.draw(wall);
                }
                window.draw(door3);
                window.draw(color);
                window.draw(color_bloc);
                window.draw(player);
            }
        }
        else if (currentState == "lvl4")
        {
            window.setView(window.getDefaultView());
            drawlvl4(window, act4scenes);
            if (currentSUBState == "gameplay4")
            {

                window.setView(gameView);

                rungmaeplay4(window, player, door4, walls4, countdownClock, countdownText, countdownDuration);
                interactplayer(player, playerSpeed, dt, walls4, { 1920.f,1080.f });
                interactplayerCOLORbloc(player, color2, color_bloc2);


                // Draw all walls
                for (const auto& wall : walls4)
                {
                    window.draw(wall);
                }
                window.draw(door4);
                window.draw(color2);
                window.draw(color_bloc2);
                window.draw(player);

                // Draw minimap border in screen coordinates
                window.setView(window.getDefaultView());

                window.draw(countdownText); // Draw countdown text

                sf::RectangleShape border(sf::Vector2f(480.f, 270.f)); // 1920*0.25, 1080*0.25
                border.setPosition({ 1920.f * 0.75f, 0.f });
                border.setFillColor(sf::Color(128, 128, 128));
                border.setOutlineColor(sf::Color::Blue);
                border.setOutlineThickness(3.f);
                window.draw(border);

                // Switch to minimap view and draw
                window.setView(minimapView);

                // Draw all walls
                for (const auto& wall : walls4)
                {
                    window.draw(wall);
                }
                window.draw(door4);
                window.draw(color2);
                window.draw(color_bloc2);
                window.draw(player);
            }

        }
        else if (currentState == "lvl5")
        {
            window.setView(window.getDefaultView());
            drawlvl5(window, act4scenes);
            if (currentSUBState == "gamefinished")
            {
                window.setView(gameView);

                rungameplay5(window, player, font);
                interactplayerF(player, playerSpeed, dt, window);

                window.draw(player);
            }
        }
        else // the default gameState mainmenuState
        {
            drawmenu(window, font);
            // restore the default view
            window.setView(window.getDefaultView());
            // RESET VIEW POSITION TO INITIAL POSITION
            // move the view at point (960, 540)
            view.setCenter({ 960.f, 540.f });
        }


        // end the current frame
        window.display();
    }

    return 0;
}