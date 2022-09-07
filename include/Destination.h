#include "Object.h"
#pragma once
//destination class for the destination for the water
class Destination : public Object
{
public:
	
	Destination(int angle = 0, Vector2f location = {}, Vector2f size = {}) :
		Object(Textures::instance().get_Textures(3), angle, location, size)
	{
		m_edges[(angle + 1) % 4] = true;
	};

private:

};