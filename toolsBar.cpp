//===============================include=======================================
#include "ToolsBar.h"
#include <iostream>
//=============================the class const'r=======================================
ToolsBar::ToolsBar(sf::Vector2i width)
	:toolbarWidth(width.x)
{
	for (int i = 0; i < NUM_OF_PIC; i++) {
		m_button[i].setButtonState(i);
		m_button[i].setButtonTexture(i);
		m_button[i].setButtonPos(toolbarWidth, i);
		m_button[i].setButtonSprite();
	}
}
//=============================================================================
void ToolsBar::setPos()
{
	for (size_t i = 0; i < NUM_OF_PIC; i++) {
		m_button[i].setButtonPos(toolbarWidth, i);
		m_button[i].setButtonSprite();
	}

}
//===============================================================================
Button ToolsBar::getClickedButton(sf::Vector2f pos)
{
	for (int i = 0; i < NUM_OF_PIC; i++) {
		if (buttonIsClicked(m_button[i], pos))
			return m_button[i];
	}
	return m_button[NUM_OF_PIC];
}
//================================================================================
bool ToolsBar::buttonIsClicked(Button b, sf::Vector2f pos)
{
	sf::Vector2f b_pos = b.getButtonPos();
	int b_x = ((int)(b_pos.x / PIXELSIZE)) *(int)PIXELSIZE;
	int b_y = ((int)(b_pos.y / PIXELSIZE)) *(int)PIXELSIZE;
	int p_x = ((int)(pos.x / PIXELSIZE)) *(int)PIXELSIZE;
	int p_y = ((int)(pos.y / PIXELSIZE)) *(int)PIXELSIZE;

	if (b_x == p_x && b_y == p_y)
		return true;
	else
		return false;

}
//=============================================================================
void ToolsBar::drawToolbar(sf::RenderWindow & window)
{
	for (size_t i = 0; i < NUM_OF_PIC; i++)
		m_button[i].drawSprite(window);
}
//=============================================================================
Toolbar_t ToolsBar::get_icon_name(sf::Vector2f vec)
{
	m_buttomPressed = true;
	sf::Vector2i v;

	v.x = ((int)vec.x / (int)PIXELSIZE) * (int)PIXELSIZE;
	v.y = ((int)(vec.y / 50)) * 50;

	size_t i;
	for (i = 0; i < NUM_OF_PIC; i++)
		if ((m_button[i].getButtonPos()) == (sf::Vector2f)v)
			break;

	return (Toolbar_t)i;
}
//=============================================================================
void ToolsBar::setToolBarWidth(int widthSize)
{
	toolbarWidth = widthSize;
}
//=============================================================================
sf::Sprite ToolsBar::get_icon_sprite(Toolbar_t icon_name) {
	return m_button[(int)icon_name].getButtonSprite();
	//return m_sprite[icon_name];
}
//=============================================================================
sf::Sprite ToolsBar::get_icon_sprite(int icon_name) {
	return m_button[icon_name].getButtonSprite();
	//return m_sprite[icon_name];
}
//=============================================================================
bool ToolsBar::toolbar_preeset()
{
	return m_buttomPressed;
}
//=============================================================================
ToolsBar & ToolsBar::getAccess()
{
	return *this;
}
//=============================================================================
ToolsBar::~ToolsBar()
{

}