#pragma once
#include "Rotatable.h"
//regular pipe
class Pipe : public Rotatable
{
public:
	Pipe(int angle = 0, Vector2f location = {}, Vector2f size = {}) :
		Rotatable(Textures::instance().get_Textures(0), angle, location, size ) 
	{
		if (angle)
		{
			m_edges[1] = m_edges[3]=true;
		}
		else
			m_edges[0] = m_edges[2] = true;
	};

private:
};