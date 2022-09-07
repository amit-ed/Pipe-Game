#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include "Object.h"
#include "macros.h"
#include "Pipe.h"
#include "Source.h"
#include "Curved_pipe.h"
#include "Destination.h"
#include "Blank.h"
#include "Trai_pipe.h"
using namespace std;
using namespace sf;
//Board class scan the file and build all the graphic objects
class Board
{

public:
	Board();
	~Board();
	bool set_Map();
	bool rebuild_Map();
	vector<Vector2i> get_dests() const { return m_destinations; };//vector of destanation loction
	vector<vector<shared_ptr<Object>>> get_map();
private:
	ifstream m_file;
	Vector2i m_size;
	vector<Vector2i> m_destinations;
	vector<string> m_Board;
};