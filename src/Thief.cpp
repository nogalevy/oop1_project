#include "Thief.h"

Thief::Thief(Icons symbol, const sf::Vector2f& position,  float objSize)
	: Player(symbol, position,  objSize), m_hasKey(false)
{
}

Thief::~Thief()
{
}


void Thief::handleCollision(GameObject& gameObject)
{
	//if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this));
	//window.
}

void Thief::handleCollision(King& gameObject)
{
	gameObject.moveToPrevPos();

}

void Thief::handleCollision(Warrior& gameObject)
{
	gameObject.moveToPrevPos();

}

void Thief::handleCollision(Mage& gameObject)
{
	gameObject.moveToPrevPos();

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
	setIcon(*(Resources::instance().getIcon(THIEF)));
	if (!m_hasKey)
		moveToPrevPos();
}

void Thief::handleCollision(Key& )
{
	setIcon(*(Resources::instance().getIcon(THIEF_WITH_KEY)));
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

void Thief::handleCollision(Dwarf& gameObject)
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
