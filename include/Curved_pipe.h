#include "Rotatable.h"
//type of pipe
class Curved_pipe : public Rotatable
{
public:
	Curved_pipe(int angle = 0, Vector2f location = {}, Vector2f size = {}) :
		Rotatable(Textures::instance().get_Textures(2), angle, location, size) 
	{
			m_edges[(angle+3)%4] = m_edges[(angle)] = true;
		
	
		
	};

private:


};