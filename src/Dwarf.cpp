#include "..\include\Dwarf.h"
#include "..\include\Dwarf.h"
#include "Dwarf.h"

Dwarf::Dwarf(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH)
{
}

Dwarf::~Dwarf()
{
}

void Dwarf::sayHello()
{
}



void Dwarf::handleCollision(GameObject& gameobject)
{
	if (&gameobject == this) return;
	//double dispatch
	gameobject.handleCollision(*this);
}

void Dwarf::handleCollision(King& /*gameobject*/)
{
	//ignore ?
}

void Dwarf::handleCollision(Warrior& /*gameobject*/)
{
	//movetoprevpos();
}

void Dwarf::handleCollision(Mage& /*gameobject*/)
{
	//movetoprevpos();
}

void Dwarf::handleCollision(Thief& /*gameobject*/)
{
	//movetoprevpos();
}

void Dwarf::handleCollision(Fire& /*gameObject*/)
{
	//m_colisionSound.playMusic();
	//moveToPrevPos();
}

void Dwarf::handleCollision(Gate& /*gameObject*/)
{
	//m_colisionSound.playMusic();
	//moveToPrevPos();
}

void Dwarf::handleCollision(Key& gameObject)
{
}

void Dwarf::handleCollision(Orc& /*gameObject*/)
{
	//m_colisionSound.playMusic();
	//moveToPrevPos();
}

void Dwarf::handleCollision(Teleport& /*gameObject*/) //more data ? next pos?
{
	//move to other teleport
	//teleportToNewPos(nextPos);
}

void Dwarf::handleCollision(Throne& /*gameObject*/)
{
	//step on it and end level
	//nextLevel(); //howwwwww???
}

void Dwarf::handleCollision(Wall& /*gameObject*/)
{
	//m_colisionSound.playMusic();
	//moveToPrevPos();
}
