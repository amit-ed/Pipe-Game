#include "Object.h"
#pragma once
//class for all the rotatable object in the game(pipes and sourses)
class Rotatable : public Object
{
public:
	using Object::Object;
	void Rotate(bool dir);

private:

};