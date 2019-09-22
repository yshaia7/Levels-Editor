#pragma once
//=========================== include =========================================
#include <SFML/Graphics.hpp>
#include "Settings.h"
//============================ Button =========================================
class Button
{
	//---------------------bublic---------------------------
public:
	Button();
	~Button();

	//this func sets a texture to the button
	void setButtonTexture(int i);

	//this fun set the button position
	void setButtonPos(int width, int i);

	//this func sets a sprite to the button
	void setButtonSprite();

	//this func return the button position
	sf::Vector2f getButtonPos() const;

	//this func returns the button sprite
	sf::Sprite getButtonSprite();

	//this func draws the sprite on the map
	void drawSprite(sf::RenderWindow &window);

	//this func sets the button state
	void setButtonState(int i);

	//this func returns the buttom state
	int getButtonState()const;
	//---------------------------private----------------------
private:

	sf::Texture m_tx;
	sf::Sprite m_sp;
	sf::Vector2f m_pos;
	int m_state;

};


