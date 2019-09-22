//=========================================== include =========================
#include "Button.h"
#include <iostream>

//=============================================================================
Button::Button()
	:m_state(NUM_OF_PIC)
{
}
//=============================================================================
Button::~Button()
{
}
//=============================================================================
void Button::setButtonTexture(int i)
{
	m_tx.loadFromFile(pic[i]);

}
//=============================================================================
void Button::setButtonPos(int width, int i)
{
	m_pos = sf::Vector2f(width * PIXELSIZE, i * PIXELSIZE);
}
//=============================================================================
void Button::setButtonSprite()
{
	m_sp.setTexture(m_tx);
	m_sp.setPosition(m_pos);
}
//============================================================================
sf::Vector2f Button::getButtonPos() const
{
	return m_pos;
}
//============================================================================
sf::Sprite Button::getButtonSprite()
{
	return m_sp;
}
//===========================================================================
void Button::drawSprite(sf::RenderWindow &window)
{
	window.draw(m_sp);
}
//=============================================================================
void Button::setButtonState(int i)
{
	m_state = i;
}
//=============================================================================
int Button::getButtonState() const
{
	return m_state;
}
