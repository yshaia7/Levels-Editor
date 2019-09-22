#pragma once
//===================================inlcude===================================
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <vector>
#include "Button.h"
//=============================================================================
using std::vector;
//====================================enum======================================

//=========================================the class============================
class ToolsBar
{
	//---------------------------------bublic-----------------------------------
public:
	ToolsBar(sf::Vector2i width);

	//this func draws the tool bar
	void drawToolbar(sf::RenderWindow & window);

	//this func retruns the pressed on icon
	Toolbar_t get_icon_name(sf::Vector2f vec);

	//this func sets the tool bar size
	void setToolBarWidth(int widthSize);

	//this func return the pic we need
	sf::Sprite get_icon_sprite(Toolbar_t icon_name);

	//this func return the toolbar sprite with name icon_name
	sf::Sprite get_icon_sprite(int icon_name);

	//this func checks if the toolbar is pressed on
	bool toolbar_preeset();

	//this func sets the toolbar position
	void setPos();

	//this func retrun the clicked on button
	Button getClickedButton(sf::Vector2f pos);

	//this func checks if a button is clicked on
	bool buttonIsClicked(Button b, sf::Vector2f pos);

	ToolsBar & getAccess();

	~ToolsBar();
	//----------------------------private----------------------------
private:
	int toolbarWidth;
	bool m_buttomPressed;
	Button m_button[NUM_OF_PIC];


};



