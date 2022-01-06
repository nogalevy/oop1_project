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

void King::handleCollision(GameObject& gameObject, Window& window)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this, window);
}

void King::handleCollision(King& gameObject, Window& window)
{
	//ignore ?
}

void King::handleCollision(Warrior& gameObject, Window& window)
{
	moveToPrevPos();
}

void King::handleCollision(Mage& gameObject, Window& window)
{
	moveToPrevPos();
}

void King::handleCollision(Thief& gameObject, Window& window)
{
	moveToPrevPos();
}

void King::handleCollision(Fire& gameObject, Window& window)
{
	m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Gate& gameObject, Window& window)
{
	m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Orc& gameObject, Window& window)
{
	m_colisionSound.playMusic();
	moveToPrevPos();
}

void King::handleCollision(Teleport& gameObject, Window& window) //more data ? next pos?
{
	//move to other teleport
	//teleportToNewPos(nextPos);
}

void King::handleCollision(Throne& gameObject, Window& window)
{
	//step on it and end level
	//nextLevel(); //howwwwww???
}

void King::handleCollision(Wall& gameObject, Window& window)
{
	m_colisionSound.playMusic();
	moveToPrevPos();
}

