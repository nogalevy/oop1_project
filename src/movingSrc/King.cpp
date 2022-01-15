#include "movingInclude/King.h"

King::King(Icons symbol, const sf::Vector2f& position,  float objSize)
	: Player(symbol, position,  objSize),
	m_reachThrone(false)
{
}

//-----------------------------------------------------------------

void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void King::handleCollision(Warrior& gameObject)
{
	gameObject.moveToPrevPos();

}

//-----------------------------------------------------------------

void King::handleCollision(Mage& gameObject)
{
	gameObject.moveToPrevPos();

}

//-----------------------------------------------------------------

void King::handleCollision(Thief& gameObject)
{
	gameObject.moveToPrevPos();
}

//-----------------------------------------------------------------

void King::handleCollision(Dwarf& )
{
	playSound(NO);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void King::handleCollision(Fire& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void King::handleCollision(Gate& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void King::handleCollision(Orc& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

void King::handleCollision(Teleport& )
{
	playSound(TELEPORT_COLISION);
}

void King::handleCollision(Throne& )
{
	m_reachThrone = true;
}

//-----------------------------------------------------------------

void King::handleCollision(Wall& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void King::handleCollision(Bonus& )
{
	playSound(BONUS_COLISION);
}

//-----------------------------------------------------------------

bool King::isReachToThrone() const
{
	return m_reachThrone;
}

