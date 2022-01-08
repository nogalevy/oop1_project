#include "King.h"

King::King(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: Player(symbol, position, mapW, mapH), m_colisionSound(Resources::instance().getColisionSound())
{
}

King::~King()
{
}

//void King::move(sf::Vector2f direction, sf::Time deltaTime)
//{
//	m_prevPos = m_icon.getPosition();
//	auto speedPerSecond = 100.f;
//	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
//}

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

void King::handleCollision(Teleport& ) //more data ? next pos?
{
	std::cout << "naw\n";

	//move to other teleport
	//teleportToNewPos(nextPos);
}

void King::handleCollision(Throne& )
{
	//step on it and end level
	//nextLevel(); //howwwwww???
}

void King::handleCollision(Wall& )
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Dwarf& gameObject)
{
}

