#include "Object.h"
#pragma once
/// <summary>
/// to fill empty spaces in the map
/// </summary>
class Blank : public Object
{
public:

	Blank( Vector2f location = {}, Vector2f size = {}) :
		Object(vector<Texture*>  {new Texture() }, 0, location, size) {
		m_rec.setFillColor(Color::Transparent);
	};

private:
};