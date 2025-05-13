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



#include "interact.h"
#include "global.h"




void setLVL1()
{
    if (currentSUBState == "gameplay1")
    {
        interactSUBSTATEBACKWARD();

    }
    else
    {
        interactlvl1scenesBACKWARD();
    }
}

void setLVL2()
{
    if (currentSUBState == "gameplay2")
    {
        interactSUBSTATEBACKWARD();

    }
    else
    {
        interactlvl2scenesBACKWARD();
    }
}

void setLVL3()
{
    if (currentSUBState == "gameplay3")
    {
        interactSUBSTATEBACKWARD();

    }
    else
    {
        interactlvl3scenesBACKWARD();
    }
}

void setLVL4(std::vector<sf::RectangleShape>& walls4)
{
    if (currentSUBState == "gameplay4")
    {
        interactSUBSTATEBACKWARD();
        walls4.clear(); // Clear walls to reset countdown on re-entry

    }
    else
    {
        interactlvl4scenesBACKWARD();
    }
}

void setLVL5()
{
    if (currentSUBState == "gamefinished")
    {
        interactSUBSTATEBACKWARD();

    }
    else
    {
        interactlvl5scenesBACKWARD();
    }
}


