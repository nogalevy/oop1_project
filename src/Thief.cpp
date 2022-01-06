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

void Thief::handleCollision(GameObject& gameObject, Window& window)
{
	//if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this), window);
	//window.
}

void Thief::handleCollision(King& gameObject, Window& window)
{
	moveToPrevPos();
}

void Thief::handleCollision(Warrior& gameObject, Window& window)
{
	moveToPrevPos();
}

void Thief::handleCollision(Mage& gameObject, Window& window)
{
	moveToPrevPos();
}

void Thief::handleCollision(Thief& gameObject, Window& window)
{
	//nothing
}

void Thief::handleCollision(Fire& gameObject, Window& window)
{
	moveToPrevPos();
}

void Thief::handleCollision(Gate& gameObject, Window& window)
{

}

void Thief::handleCollision(Key& gameObject, Window& window)
{
	setHasKey(true);
}

void Thief::handleCollision(Orc& gameObject, Window& window)
{
	moveToPrevPos();
}

void Thief::handleCollision(Teleport& gameObject, Window& window)
{
}

void Thief::handleCollision(Throne& gameObject, Window& window)
{
	moveToPrevPos();
}

void Thief::handleCollision(Wall&, Window& window)
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
