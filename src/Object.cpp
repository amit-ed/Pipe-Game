#include "Object.h"

Object::Object(vector<Texture*> tex, int angle, Vector2f location, Vector2f size) : m_angle(angle), m_textures(tex)
{
	m_rec = RectangleShape(size);
	m_rec.setTexture(m_textures[0]);
	m_rec.setOrigin(m_rec.getSize().x / 2, m_rec.getSize().y / 2);
	m_rec.rotate(float(90 * angle));
	m_rec.setPosition(location);
}

//======================================================
/*function to check if mouse is on object */
bool Object::Contain(const sf::Vector2f& location) const
{
	
	if (m_rec.getGlobalBounds().contains(location))
		return true;
	return false;
}

//======================================================
Object::~Object()
{
	m_textures.clear();
}

//======================================================
