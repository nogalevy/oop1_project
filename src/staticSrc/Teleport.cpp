#include "staticInclude/Teleport.h"

void Teleport::setPartner(sf::Vector2f partner)
{
	m_partner = partner;
}

//-----------------------------------------------------------------

void Teleport::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Teleport::handleCollision(King& gameObject)
{
	gameObject.setPosition(m_partner);
}

//-----------------------------------------------------------------

void Teleport::handleCollision(Warrior& gameObject)
{
	gameObject.setPosition(m_partner);
}

//-----------------------------------------------------------------

void Teleport::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Teleport::handleCollision(Thief& gameObject)
{
	gameObject.setPosition(m_partner);
}
