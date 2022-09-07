#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Graph.h"
#include<chrono>
#include<thread>
#include "Tap_counter.h"
//main class ,run the all game
class Controller
{
public:
	Controller();
	~Controller();
	void run();

private:
	void handle_event();
	void handleClick(const sf::Vector2f& location, bool dir);
	void get_vertex(int i, int j);
	void check_lvl();
	void Quit_Game(int pic_num);
	void print_objects();
	Board m_board;
	Graph m_graph;
	Tap_counter m_tap;
	
	Sprite m_Bg; // the background
	Sprite m_lvlup;
	RenderWindow m_window;
	vector<vector<shared_ptr<Object>>> m_Objects;//for printing after drawing for displaying
	vector<Vector2i> m_destinations;
};