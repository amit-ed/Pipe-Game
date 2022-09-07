#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
//class for the tap counter
class Tap_counter
{
public:
	Tap_counter();
	void tap() { m_taps++; };
	void Draw (sf::RenderWindow& window);
	void reset() { m_taps = 0; };
	Tap_counter operator++() { this->m_taps++; return *this; };

private:
	sf::Text m_text;
	int m_taps = 0;
};