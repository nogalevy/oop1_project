#include "King.h"

King::King(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: Player(symbol, position, mapW, mapH), m_colisionSound(Resources::instance().getColisionSound()),
	m_reachThrone(false)
{
}

King::~King()
{
}


void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

void King::handleCollision(King& )
{
	//ignore ?
}

void King::handleCollision(Warrior& )
{
}

void King::handleCollision(Mage& )
{
}

void King::handleCollision(Thief& )
{
}

void King::handleCollision(Fire& )
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Gate& )
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Orc& )
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Teleport& )
{
	std::cout << "naw\n";

	//move to other teleport
	//teleportToNewPos(nextPos);
}

void King::handleCollision(Throne& )
{
	m_reachThrone = true;
	//audio  ? :)
	//step on it and end level
	//nextLevel(); 
}

void King::handleCollision(Wall& )
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Dwarf& gameObject)
{
}

bool King::isReachToThrone() const
{
	return m_reachThrone;
}

