//================================include======================================
#include "Map.h"
#include <iostream>
//=============================the map class===================================
Map::Map()
	:line(sf::Lines, 4)
{
	//if successeded in opening the file
	if (open_file(input))
	{
		readFromFile = true;
		input >> m_map_size.width >> m_map_size.height;
		calc_pixel_size();
		allocMapSprite();
		resMapIndex();

		read_file(input);
	}
	//there's no file
	else {
		readFromFile = false;
		setMapSize();
		allocMapSprite();
		resMapIndex();
	}
}
//=============================================================================
void Map::set_picture(int val, sf::Vector2f pos)
{
	m_map_sprite_index[(int)(pos.x /50)][(int)(pos.y /50)] = val;
}
//=============================================================================
void Map::draw_characters(sf::RenderWindow & window)
{

	for (int i = 0; i < m_mapSpriteSize.x; i++)
		for (int j = 0; j < m_mapSpriteSize.y; j++)
			if (m_map_sprite_index[i][j] != -1)
			{
				int image_num = m_map_sprite_index[i][j];

				drawMap = toolbar->get_icon_sprite(image_num);
				drawMap.setPosition({ (float)i * 50,(float)j * 50 });
				window.draw(drawMap);
			}
}
//=============================================================================
void Map::set_toolbar(ToolsBar * tool)
{
	toolbar = tool;
}
//=============================================================================
void Map::erase_pic(sf::Vector2f pos)
{
	m_map_sprite_index[(int)(pos.x / 50)][(int)(pos.y / 50)] = -1;
}
//=============================================================================
void Map::resMapIndex()
{
	for (int i = 0; i < m_mapSpriteSize.x; i++)
		for (int j = 0; j < m_mapSpriteSize.y; j++)
		{
			m_map_sprite_index[i][j] = -1;
		}
}
//=============================================================================
void Map::allocMapSprite()
{
	m_map_sprite_index.clear();
	m_map_sprite_index.resize(m_map_size.height);
	for (int i = 0; i < (int)m_map_size.height; i++)
		m_map_sprite_index[i].resize(m_map_size.width);
}
//=============================================================================
void Map::setMapSize()
{
	std::cout << "Please Enter Number Between 9-15 for Rows\n";
	std::cout << "Please Enter Number Between 9-15 for Cols\n";
	std::cin >> m_map_size.width;
	std::cin >> m_map_size.height;
	std::cout << "go back to the window\n";

	calc_pixel_size();

}
//=============================================================================
void Map::calc_pixel_size() {

	m_mapSpriteSize.x = m_map_size.width;
	m_mapSpriteSize.y = m_map_size.height;

	//add one pixel for tool bar
	m_map_size.width++;

	//set default size of window
	m_map_size.width *= (unsigned int)PIXELSIZE;
	m_map_size.height *= (unsigned int)PIXELSIZE;

}
//=============================================================================
bool Map::getReadFromFile() const
{
	return readFromFile;
}
//=============================================================================
sf::Vector2i Map::getBoardSize()
{
	return m_mapSpriteSize;
}
//=============================================================================
sf::VideoMode Map::getMapSize() const
{
	return m_map_size;
}
//=============================================================================
void Map::draw_Grid(sf::RenderWindow &window)
{
	int size;
	if (m_mapSpriteSize.y > m_mapSpriteSize.x)
		size = m_mapSpriteSize.y;
	else
		size = m_mapSpriteSize.x;
	for (int i = 0; i <= size; i++)
	{
		line[2].position = sf::Vector2f(i * PIXELSIZE, (float)0);
		line[3].position = sf::Vector2f(i * PIXELSIZE, (float)getMapSize().height);
		line[0].position = sf::Vector2f((float)0, i * PIXELSIZE);
		line[1].position = sf::Vector2f(getMapSize().width - PIXELSIZE, i * PIXELSIZE);
		window.draw(line);
	}
}
//=============================================================================
bool Map::cell_Empty(sf::Vector2f pos)
{
	return (m_map_sprite_index[(int)pos.x / (int)PIXELSIZE][(int)pos.y / (int)PIXELSIZE] == -1);
}
//=============================================================================
void Map::clean_map()
{
	setMapSize();
	allocMapSprite();
	resMapIndex();
}
//=============================================================================
bool Map::open_file(std::fstream& input)
{
	input.open("board.bomb");    //to change the name
	if (!input.is_open())
		return false;
	return true;
}
//=============================================================================
Map::~Map()
{
}
//=============================================================================
void Map::save_to_file()
{
	std::ofstream outfile("board.bomb.txt");

	outfile << m_mapSpriteSize.x << ' ' << m_mapSpriteSize.y;
	outfile << std::endl;
	for (int i = 0; i < m_mapSpriteSize.y; i++)
	{
		for (int j = 0; j < m_mapSpriteSize.x; j++)
		{
			switch ((Toolbar_t)m_map_sprite_index[j][i])
			{
			case SPACE:
				outfile << SPC;
				break;

			case ROBOT_t:
				outfile << ROBOT;
				break;
			case GUARD_t:
				outfile << GUARD;
				break;
			case DOOR_t:
				outfile << DOOR;
				break;
			case ROCK_t:
				outfile << ROCK;
				break;
			case WALL_t:
				outfile << WALL;
				break;

			}

		}

		outfile << std::endl;
	}
	outfile.close();
}
//=============================================================================
void Map::read_file(std::fstream &input)
{
	int i = -1, j = -1;
	char c;

	while (!input.eof())
	{
		c = input.get();

		if (c == SPC)
			m_map_sprite_index[i][j] = SPACE;
		if (c == ROBOT)
			m_map_sprite_index[i][j] =(int) ROBOT_t;
		else if (c == GUARD)
			m_map_sprite_index[i][j] =(int) GUARD_t;
		else if (c == WALL)
			m_map_sprite_index[i][j] = (int)WALL_t;
		else if (c == ROCK)
			m_map_sprite_index[i][j] = (int)ROCK_t;
		else if (c == DOOR)
			m_map_sprite_index[i][j] =(int) DOOR_t;

		i++;
		if (c == NEWLINE)
		{
			i = 0;
			j++;
			continue;
		}
	}

}