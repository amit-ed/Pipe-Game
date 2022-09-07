#include <vector>
#include "Board.h"
#include <iostream>
using namespace std;
using namespace sf;
//----------------------------------------------------------------------------
/*
constractor defult for game board
m_cf:file pointer.
*/
Board::Board()
{
    m_file.open("map.txt");
	if (!m_file) throw std::runtime_error("Exception opening file\n");
   // set_Size();
    set_Map();
}
//=============================================
Board::~Board()
{
	m_Board.clear();
	m_destinations.clear();
	
}
//--------------------------------------------------
//--------------------------------------------------
/*
set the map
* m_board : the vector for the map.
* cur:local var for each string .
*/
bool Board::set_Map()
{
	std::string temp="";
	while ((temp==""||temp=='\n'))
	{
		std::getline(m_file, temp);
		if (temp == "//")
			return false;
	}
	m_size.y = temp.length();
	int counter = 0;
	while (temp != "" && temp != '\n')
	{
		if (temp.length() != m_size.y) throw exception("error reading the map, need to fill blank with empty space\n");
		m_Board.push_back(temp);
		counter++;
		getline(m_file, temp);
		
		
	}
	m_size.x = counter;
	return (!m_file.fail());
}
//----------------------------------------------------------------------------
/*
* set the game map and
* return in
*/
vector<vector<shared_ptr<Object>>> Board::get_map()
{
	vector<vector<shared_ptr<Object>>> map;
	float length = (Board_Width / float(m_size.y) + Board_Height / float(m_size.x)) / 2;
	sf::Vector2f block_Size(length, length);
	std::string name;
	Object* object;
	for (int i = 0; i < m_size.x; i++) {
		vector<shared_ptr<Object>>temp(m_size.y);
		for (int j = 0; j < m_size.y; j++) {
			//----------------------creating block and setting their size--------------------------------------------------
			
			Vector2f location(STARTING_X + (j * length),
				STARTING_Y + (i * length));

			switch (m_Board[i][j]) {
			case pipeL:
				object = new Pipe(1, location, block_Size);
				temp[j].reset(object);
				break;
			case pipeR:
				object = new Pipe(0, location, block_Size);
				temp[j].reset(object);
				break;
			case sourceD:
				object = new Source(0, location, block_Size);
				temp[j].reset(object);
				break;
			case sourceR:
				object = new Source(3, location, block_Size);
				temp[j].reset(object);
				break;
			case sourceU:
				object = new Source(2, location, block_Size);
				temp[j].reset(object);
				break;
			case sourceL:
				object = new Source(1, location, block_Size);
				temp[j].reset(object);
				break;
			case CurvedL:
				object = new Curved_pipe(2, location, block_Size);
				temp[j].reset(object);
				break;
			case CurvedR:
				object = new Curved_pipe(3, location, block_Size);
				temp[j].reset(object);
				break;
			case CurvedU:
				object = new Curved_pipe(1, location, block_Size);
				temp[j].reset(object);
				break;
			case CurvedD:
				object = new Curved_pipe(0, location, block_Size);
				temp[j].reset(object);
				break;
			case destD:
				object = new Destination(2, location, block_Size);
				m_destinations.push_back(Vector2i(i, j));
				temp[j].reset(object);
				break;
			case destU:
				object = new Destination(0, location, block_Size);
				m_destinations.push_back(Vector2i(i, j));
				temp[j].reset(object);
				break;
			case destR:
				object = new Destination(1, location, block_Size);
				m_destinations.push_back(Vector2i(i, j));
				temp[j].reset(object);
				break;
			case destL:
				object = new Destination(3, location, block_Size);
				m_destinations.push_back(Vector2i(i, j));
				temp[j].reset(object);
				break;
			case threeU:
				object = new Trai_pipe(3, location, block_Size);
				temp[j].reset(object);
				break;
			case threeR:
				object = new Trai_pipe(1, location, block_Size);
				temp[j].reset(object);
				break;
			case threeL:
				object = new Trai_pipe(2, location, block_Size);
				temp[j].reset(object);
				break;
			case threeD:
				object = new Trai_pipe(0, location, block_Size);
				temp[j].reset(object);
				break;
			case ' ':
				object = new Blank(location, block_Size);
				temp[j].reset(object);
				break;
			default:
				throw exception("Exception reading file, invalid char ,see macros\n");
				break;
			};
		}
		map.push_back(temp);
	}
	return map;//return the map of objects to the controller
}
//=====================================================================
/*
* loading new map for each lvl
*/
bool Board::rebuild_Map() {
	m_Board.clear();
	m_destinations.clear();
	if (set_Map()) {
		
		return true;
	}
	else
		return false;
}