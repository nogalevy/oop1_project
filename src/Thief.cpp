#include "Thief.h"

Thief::Thief(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: Player(symbol, position, mapW, mapH), m_hasKey(false)
{
}

Thief::~Thief()
{
}

//void Thief::move(sf::Vector2f direction, sf::Time deltaTime)
//{
//	auto speedPerSecond = 100.f;
//	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
//}

void Thief::handleCollision(GameObject& gameObject)
{
	//if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this));
	//window.
}

void Thief::handleCollision(King& )
{
	moveToPrevPos();
}

void Thief::handleCollision(Warrior& )
{
	moveToPrevPos();
}

void Thief::handleCollision(Mage& )
{
	moveToPrevPos();
}

void Thief::handleCollision(Thief& )
{
	//nothing
}

void Thief::handleCollision(Fire& )
{
	moveToPrevPos();
}

void Thief::handleCollision(Gate& )
{
	if (!m_hasKey)
		moveToPrevPos();
}

void Thief::handleCollision(Key& )
{
	setHasKey(true);
}

void Thief::handleCollision(Orc& )
{
	moveToPrevPos();
}

void Thief::handleCollision(Teleport& )
{
}

void Thief::handleCollision(Throne& )
{
	moveToPrevPos();
}

void Thief::handleCollision(Wall&)
{
	moveToPrevPos();
}

bool Thief::getHasKey() const
{
	return m_hasKey;
}

void Thief::setHasKey(bool hasKey)
{
	m_hasKey = hasKey;
}

//bool Thief::getHasKey() const
//{
//	return m_hasKey;
//}

//void Thief::setKey(bool hasKey)
//{
//	m_hasKey = hasKey;
//}
