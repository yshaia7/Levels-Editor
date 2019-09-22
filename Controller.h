#pragma once
//=================================include=====================================
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Toolsbar.h"
#include "Button.h"
#include "Settings.h"
//=================================the controller class========================
class Controller
{
	//----------------------------bublic-------------------------
public:
	Controller();
	void run();

	~Controller();
	//------------------------private-----------------------------
private:
	//the game map
	Map m_map; 
	
	//the game toolbar
	ToolsBar m_toolBar; 

	//if the robot is already on the map it gives true
	bool robotPlaced = false;	

	//this func handles the event the user does
	void HandleEvents();	

	//this func draws the map
	void drawMap();  


	 //this func handles the game when the mouse is pressed
	void click(const sf::Vector2f & pos);

	sf::Sprite spirit;

	//the game window
	sf::RenderWindow m_window;  

	sf::Sprite m_mouse_symbol;
	int m_pressedButton;
	
	//position of robot 
	sf::Vector2i robotPos;

	//if user wants to restart the game
	bool restart = false;

	//this funcs checks if is it ok add a blocked guard
	bool is_ok(sf::Vector2f pos, sf::Vector2f dircs[DIRCS_SIZE]);

	//this func restart the game when the user chooses to
	void reset();


};