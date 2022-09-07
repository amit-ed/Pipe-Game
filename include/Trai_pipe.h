#include "Rotatable.h"
///type of pipe
class Trai_pipe : public Rotatable
{
public:
	Trai_pipe(int angle = 0, Vector2f location = {}, Vector2f size = {}) :
		Rotatable(Textures::instance().get_Textures(5), angle, location, size)
	{
		m_edges[(angle)] = m_edges[(angle+1)%4] =m_edges[(angle+2)%4]= true;
	};

private:


};