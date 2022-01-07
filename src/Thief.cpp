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

void Thief::handleCollision(King& gameObject)
{
	moveToPrevPos();
}

void Thief::handleCollision(Warrior& gameObject)
{
	moveToPrevPos();
}

void Thief::handleCollision(Mage& gameObject)
{
	moveToPrevPos();
}

void Thief::handleCollision(Thief& gameObject)
{
	//nothing
}

void Thief::handleCollision(Fire& gameObject)
{
	moveToPrevPos();
}

void Thief::handleCollision(Gate& gameObject)
{

}

void Thief::handleCollision(Key& gameObject)
{
	setHasKey(true);
}

void Thief::handleCollision(Orc& gameObject)
{
	moveToPrevPos();
}

void Thief::handleCollision(Teleport& gameObject)
{
}

void Thief::handleCollision(Throne& gameObject)
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
