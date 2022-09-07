#include "Rotatable.h"
//rotate object left or right
void Rotatable::Rotate(bool dir)
{
	if (dir)
	{
		m_rec.rotate(float(90));
		bool temp = m_edges[3];
		for (int i = 3; i > 0; i--)
		{
			 m_edges[i] = m_edges[i - 1] ;
		}
		m_edges[0] = temp;
	}
	else
	{
		m_rec.rotate(float(-90));
		bool temp = m_edges[0];
		for (int i = 0; i < 3; i++)
		{
			m_edges[i] = m_edges[i + 1];
		}
		m_edges[3] = temp;
	}
}