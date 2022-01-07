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

void King::handleCollision(King& gameObject)
{
	//ignore ?
}

void King::handleCollision(Warrior& gameObject)
{
	moveToPrevPos();
}

void King::handleCollision(Mage& gameObject)
{
	moveToPrevPos();
}

void King::handleCollision(Thief& gameObject)
{
	moveToPrevPos();
}

void King::handleCollision(Fire& gameObject)
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Gate& gameObject)
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Orc& gameObject)
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Teleport& gameObject) //more data ? next pos?
{
	//move to other teleport
	//teleportToNewPos(nextPos);
}

void King::handleCollision(Throne& gameObject)
{
	//step on it and end level
	//nextLevel(); //howwwwww???
}

void King::handleCollision(Wall& gameObject)
{
	//m_colisionSound.playMusic();
	moveToPrevPos();
}

