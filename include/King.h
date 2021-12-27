#pragma once

#include "DynamicObject.h"

class King : public DynamicObject
{
public:
	King();
	~King();

	virtual void move(/*sf::Time&*/) override;

private:

};
