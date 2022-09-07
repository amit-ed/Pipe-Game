#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include <vector>
using namespace sf;
using namespace std;
//class for all the objects in the game(all types of pipe,sourse and destination)
class Object
{
public:
	Object(vector<Texture*> tex = {}, int angle = 0, Vector2f location = {}, Vector2f size = {});
	~Object();
	void Draw(sf::RenderWindow& window) const { window.draw(m_rec); };
	bool Contain (const sf::Vector2f& location) const;
	void connect() { m_connected = true; m_rec.setTexture(m_textures[Connected]); };
	void disconnect() { m_connected = false; m_rec.setTexture(m_textures[Disconnected]); };
	bool is_connected() const { return m_connected; };
	virtual void Rotate(bool dir) {};
	bool get_left_edge() const { return m_edges[0]; };
	bool get_up_edge()const { return m_edges[1]; };
	bool get_right_edge() const { return m_edges[2]; };
	bool get_down_edge()const { return m_edges[3]; };

protected:
	bool m_connected = false;
	bool m_edges[4] = { false };//to know pipe dir for water
	RectangleShape m_rec;
	vector<Texture*> m_textures;
	int m_angle;
};