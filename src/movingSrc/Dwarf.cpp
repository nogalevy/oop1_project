#include "movingInclude/Dwarf.h"

Dwarf::Dwarf(Icons symbol, const sf::Vector2f& position,  float objSize)
	: MovingObject(symbol, position,  objSize), m_direction({ -1,0 }), m_speedPerSecond(100.f)
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
	//if (&gameobject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Dwarf::handleCollision(Wall& )
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
	if (m_direction.x == -1)
		m_direction.x = 1;
	else
		m_direction.x = -1;
}

//-----------------------------------------------------------------

void Dwarf::increaseSpeed()
{
	m_speedPerSecond += 50.f;

	if (m_speedPerSecond > 400.f)
		m_speedPerSecond = 300.f;
}

//-----------------------------------------------------------------

void Dwarf::decreaseSpeed()
{
	m_speedPerSecond -= 50.f;

	if (m_speedPerSecond < 50.f)
		m_speedPerSecond = 50.f;
}
