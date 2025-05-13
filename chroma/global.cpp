#include <string>
//------------------------------ DEFINE GAME STATES ---------------------------------

std::string currentState = "mainmenu";
std::string selectedlvl = "";

bool lvl1locked = false;

bool lvl2locked = true;

bool lvl3locked = true;

bool lvl4locked = true;

//------------------------------ DEFINE LVL SCENES --------------------------------------------------

	//		ACT1		//

std::string currentact1scene = "Act1scene1";

//		ACT2		//

std::string currentact2scene = "Act2scene1";

//		ACT3		//

std::string currentact3scene = "Act3scene1";

//		ACT4		//

std::string currentact4scene = "Act4scene1";

//		ACT5		//

std::string currentact5scene = "Act5scene1";

//------------------------------ DEFINE SUBSTATES ---------------------------------------------------

std::string currentSUBState = "";

//---------------------------------------------------------------------------------------------------

bool havingBOMB = false;

bool bombsPlaced = false;

bool timeSup = false;

int pickedPlacementIndex = -1;









