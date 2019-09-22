//======================================include================================
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "toolsbar.h"
#include <fstream>
#include <vector>
//=======================================the map class=========================
class Map
{

public:
	//--------------------------public -------------------------------
	Map();

	void setMapSize();

	//it return the window size
	sf::VideoMode getMapSize() const;
	//to open file
	bool open_file(std::fstream& input);

	//this func draws the map
	void draw_Grid(sf::RenderWindow &window);

	//this func return true if the pos we're in is empty on the map
	bool cell_Empty(sf::Vector2f pos);

	//this func sets a pic in a specific spot
	void set_picture(int val, sf::Vector2f pos);

	//this func draws a character
	void draw_characters(sf::RenderWindow &window);

	//this func sets the tool bar 
	void set_toolbar(ToolsBar * tool);

	//this func erase a pic in the pos
	void erase_pic(sf::Vector2f pos);

	//this func cleans the map
	void clean_map();

	//this func save the current map to a file
	void save_to_file();

	//this func reads from a file
	void read_file(std::fstream &input);

	void calc_pixel_size();

	//this func checks if it is possible to read from file
	//if yes it reads from it
	bool getReadFromFile() const;

	//this func return the window size
	sf::Vector2i getBoardSize();

	~Map();

private:
	//--------------------------------- private --------------------------
	//for the empty places in the map
	sf::VertexArray line;

	//the input file
	std::fstream input; 

	//the map size
	sf::VideoMode m_map_size; 

	//the input
	std::vector <std::vector < int > > m_map_sprite_index;
	ToolsBar *toolbar;

	
	void allocMapSprite();


	void resMapIndex();

	sf::Vector2i m_mapSpriteSize;

	sf::Sprite drawMap;

	bool readFromFile;


};