#pragma once

#include "StaticObject.h"

class Bonus : public StaticObject
{
public:
	Bonus();
	~Bonus();

	void addTime();
	void subTime();
	void destroyDwarfs();
private:

};