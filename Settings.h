#pragma once
//================================ include ====================================
#include <string>

//============================================================================
const float PIXELSIZE = 50;
const int PIXEL = 50;
const char NUM_OF_PIC = 9;

//=============================================================================
enum Toolbar_t {
	ROBOT_t,
	GUARD_t,
	BLOCKEDGUARD_t,
	ROCK_t,
	WALL_t,
	DOOR_t,
	ERASE_t,
	SAVE_t,
	RESTART_t,
	SPACE_t
};

const int SPACE = -1;
const int DIRCS_SIZE = 5;

const char ROBOT = '/',
GUARD = '!',
ROCK = '@',
WALL = '#',
DOOR = 'D',
SPC = ' ',
NEWLINE = '\n';
//=============================================================================
const std::string pic[NUM_OF_PIC] =
{
	"Images\\robot.jpg",
	"Images\\guard.jpg",
	"Images\\guardblockt.jpg",
	"Images\\rock.jpg",
	"Images\\wall.jpg",
	"Images\\door.jpg",
	"Images\\erase.jpg",
	"Images\\save.png",
	"Images\\restart.png"
};


