#include "movingInclude/Thief.h"

Thief::Thief(Icons symbol, const sf::Vector2f& position,  float objSize)
	: Player(symbol, position,  objSize), m_hasKey(false)
{
}

//-----------------------------------------------------------------

void Thief::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*(this));
}

//-----------------------------------------------------------------

void Thief::handleCollision(King& gameObject)
{
	gameObject.moveToPrevPos();
}

//-----------------------------------------------------------------

void Thief::handleCollision(Warrior& gameObject)
{
	gameObject.moveToPrevPos();
}

//-----------------------------------------------------------------

void Thief::handleCollision(Mage& gameObject)
{
	gameObject.moveToPrevPos();
}

//-----------------------------------------------------------------

void Thief::handleCollision(Dwarf& )
{
	playSound(DWARF_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Thief::handleCollision(Fire& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Thief::handleCollision(Gate& )
{
	playSound(THIEF_GATE_COLISION);
	setIcon(*(Resources::instance().getIcon(THIEF)));
	if (!m_hasKey)
	{
		moveToPrevPos();
	}
}

//-----------------------------------------------------------------

void Thief::handleCollision(Key& )
{
	setIcon(*(Resources::instance().getIcon(THIEF_WITH_KEY)));
	playSound(MAGE_FIRE_COLISION);
	setHasKey(true);
}

//-----------------------------------------------------------------

void Thief::handleCollision(Orc& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

void Thief::handleCollision(Teleport& )
{
	playSound(TELEPORT_COLISION);
}

void Thief::handleCollision(Throne& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Thief::handleCollision(Wall&)
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Thief::handleCollision(Bonus& )
{
	playSound(BONUS_COLISION);
}

//-----------------------------------------------------------------

bool Thief::getHasKey() const
{
	return m_hasKey;
}

//-----------------------------------------------------------------

void Thief::setHasKey(const bool hasKey)
{
	m_hasKey = hasKey;
}
