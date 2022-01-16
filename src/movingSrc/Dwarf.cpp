#include "movingInclude/Dwarf.h"

Dwarf::Dwarf(Icons symbol, const sf::Vector2f& position,  float objSize)
	: MovingObject(symbol, position,  objSize), m_direction({ -1,0 }), m_speedPerSecond(SPEED_PER_SEC)
{
}

//-----------------------------------------------------------------

void Dwarf::move(sf::Time deltaTime)
{
	getPrevPos() = getPosition();

	getIcon().move(m_direction * m_speedPerSecond * deltaTime.asSeconds());
}

//-----------------------------------------------------------------

void Dwarf::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Dwarf::handleCollision(Wall& )
{
	moveToPrevPos();
	if (m_direction.x == LEFTD)
		m_direction.x = RIGHTD;
	else
		m_direction.x = LEFTD;
}

//-----------------------------------------------------------------

void Dwarf::increaseSpeed()
{
	m_speedPerSecond += MIN_SPEED;

	if (m_speedPerSecond > MAX_SPEED)
		m_speedPerSecond = MAX_SPEED;
}

//-----------------------------------------------------------------

void Dwarf::decreaseSpeed()
{
	m_speedPerSecond -= MIN_SPEED;

	if (m_speedPerSecond < MIN_SPEED)
		m_speedPerSecond = MIN_SPEED;
}
