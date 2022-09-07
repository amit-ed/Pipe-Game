#pragma once
#include "Rotatable.h"
//sourse of water
class Source : public Rotatable
{
public:
	Source(int angle = 0, Vector2f location = {}, Vector2f size = {}) :
		Rotatable(Textures::instance().get_Textures(1), angle, location, size)
	
	{
		m_edges[(angle+3)%4] = true;
	};

private:


};