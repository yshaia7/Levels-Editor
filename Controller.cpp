//this is the source file for the controller class
//=============================include=========================================
#include "Controller.h"

//==============================================================================
Controller::Controller()
	: m_map(),
	m_toolBar(m_map.getBoardSize()),
	m_window(m_map.getMapSize(), "Bomberman Game")
{
	m_map.set_toolbar(&m_toolBar.getAccess());
	robotPlaced = m_map.getReadFromFile();
}

//=============================================================================
void Controller::run()
{
	while (m_window.isOpen()) {

		HandleEvents();
		drawMap();

	}
}

//=============================================================================
void Controller::HandleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		//the user doesnt want to start new game
		if (!restart)   
			switch (event.type)
			{
				//close the window
			case sf::Event::Closed:  
				m_window.close();
				break;

				//the mouse moved
			case sf::Event::MouseMoved: 

				//the mouse entered the window
			case sf::Event::MouseEntered: 

				//it gets the mouse location on the map in the window
				m_mouse_symbol.setPosition(float(event.mouseMove.x /
					                             PIXEL) * PIXEL,
					float(event.mouseMove.y / PIXEL) * PIXEL);


				m_mouse_symbol.setColor(sf::Color(255, 0, 0, 180));
				break;

				//the mouse left the window
			case sf::Event::MouseLeft:  
				m_mouse_symbol.setPosition((float)m_map.getMapSize().width,
					                       (float)m_map.getMapSize().width);
				break;

				//click on the mouse
			case sf::Event::MouseButtonPressed:  
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					click(m_window.mapPixelToCoords({ event.mouseButton.x,
												   event.mouseButton.y }));
				}
				break;
			}
	}
}
//=============================================================================
void Controller::click(const sf::Vector2f & pos)
{
	//if the user clicked on an empty place
	if (pos.x >= m_map.getMapSize().width - PIXELSIZE
		&& pos.y > NUM_OF_PIC * PIXELSIZE)
		return;

	//if mouse is in another place in the toolbar
	if (pos.x >= m_map.getMapSize().width - PIXELSIZE)
	{
		Button b = m_toolBar.getClickedButton(pos);

		//to get the pressed on button
		m_pressedButton = b.getButtonState();
		m_mouse_symbol = b.getButtonSprite();
	}

	//if the user picked restart in the toolbar
	if ((Toolbar_t)m_pressedButton == RESTART_t)
		reset();

	//if user clicked on save file in the toolbar	
	if ((Toolbar_t)m_pressedButton == SAVE_t)
	{
		m_map.save_to_file();
		m_mouse_symbol.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}

	//if the user clickd on a different button
	else if (m_pressedButton < (int)SAVE_t)
	{
		switch ((Toolbar_t)m_pressedButton)
		{
			//if clicked on the robot
		case ROBOT_t:  
			if (!robotPlaced && m_map.cell_Empty(pos))
			{
				m_map.set_picture(m_pressedButton, pos);
				robotPlaced = true;
				robotPos.x = (int)pos.x / (int)PIXELSIZE;
				robotPos.y = (int)pos.y / (int)PIXELSIZE;
			}
			break;

		case GUARD_t:
		case DOOR_t:
		case ROCK_t:
		case WALL_t:
			if (m_map.cell_Empty(pos))
				m_map.set_picture(m_pressedButton, pos);
			break;


		case BLOCKEDGUARD_t:
		{
			sf::Vector2f dircs[DIRCS_SIZE] = { {0, 0}, {PIXELSIZE, 0}, {0, PIXELSIZE},
									           {-PIXELSIZE, 0}, {0, -PIXELSIZE} };

			if (is_ok(pos, dircs) && pos.x > PIXELSIZE && pos.y > PIXELSIZE)
			{
				m_map.set_picture((int)GUARD_t, pos);
				for (int i = 1; i < DIRCS_SIZE; i++)
					m_map.set_picture((int)ROCK_t, { pos.x + dircs[i].x, pos.y + dircs[i].y });
			}
		}

		break;

		//the user chose to erase a pic in the map
		case ERASE_t:  
			if (!m_map.cell_Empty(pos))
			{
				m_map.erase_pic(pos);
				if (m_map.getReadFromFile() ||
					(int)pos.x / (int)PIXELSIZE == robotPos.x
					&& (int)pos.y / (int)PIXELSIZE == robotPos.y)
					robotPlaced = false;
			}
			break;
		}
	}
}
//============================================================================
bool Controller::is_ok(sf::Vector2f pos, sf::Vector2f dircs[DIRCS_SIZE])
{
	for (int i = 0; i < DIRCS_SIZE; i++)
		if (!m_map.cell_Empty({ pos.x + dircs[i].x, pos.y + dircs[i].y }))
			return false;
	return true;
}
void Controller::reset()
{
	restart = true;
	m_map.clean_map();

	//to resize the window according to the user input
	m_window.setSize({ (unsigned)m_map.getMapSize().width,
					  (unsigned)m_map.getMapSize().height });

	//adjusting the window acording to the new size
	sf::FloatRect visibleArea(0, 0, (float)m_map.getMapSize().width,
		(float)m_map.getMapSize().height);
	m_window.setView(sf::View(visibleArea));

	//adjusting the toolbar size
	m_toolBar.setToolBarWidth(m_map.getBoardSize().x);
	m_toolBar.setPos();

	//the window is updated
	restart = false;
	robotPlaced = false;
	m_mouse_symbol.setTextureRect(sf::IntRect(0, 0, 0, 0));
}
//=============================================================================
Controller::~Controller()
{
}
//=============================================================================
void Controller::drawMap()
{
	m_window.clear();
	m_window.draw(m_mouse_symbol);
	m_toolBar.drawToolbar(m_window);
	m_map.draw_Grid(m_window);
	m_map.draw_characters(m_window);
	m_window.display();
}

