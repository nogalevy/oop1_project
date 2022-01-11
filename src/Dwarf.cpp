#include "Dwarf.h"

Dwarf::Dwarf(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH), m_direction({ -1,0 })
{
}

Dwarf::~Dwarf()
{
}

void Dwarf::move(sf::Time deltaTime)
{
	m_prevPos = getIcon().getPosition();
	auto speedPerSecond = 100.f;
	getIcon().move(m_direction * speedPerSecond * deltaTime.asSeconds());
}



void Dwarf::handleCollision(GameObject& gameObject)
{
	//if (&gameobject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

void Dwarf::handleCollision(King& /*gameObject*/)
{
	//doesnt get here and doesnt need to 
}

void Dwarf::handleCollision(Warrior& /*gameObject*/)
{
	//movetoprevpos();
}

void Dwarf::handleCollision(Mage& /*gameObject*/)
{
	//movetoprevpos();
}

void Dwarf::handleCollision(Thief& /*gameObject*/)
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

void Dwarf::handleCollision(Key& /*gameObject*/)
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
	moveToPrevPos();
	if (m_direction.x == -1)
		m_direction.x = 1;
	else
		m_direction.x = -1;
}

void Dwarf::handleCollision(Dwarf& gameObject)
{
}
