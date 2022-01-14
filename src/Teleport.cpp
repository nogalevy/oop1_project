#include "Teleport.h"

Teleport::~Teleport()
{
}

void Teleport::setPartner(sf::Vector2f partner)
{
	m_partner = partner;
}

void Teleport::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
	gameObject.setPosition(m_partner);
}

void Teleport::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	gameObject.setPosition(m_partner);
}

void Teleport::handleCollision(Mage& gameObject)
{
	//gameObject.handleCollision(*this);
}

void Teleport::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	gameObject.setPosition(m_partner);
}

void Teleport::handleCollision(Dwarf& gameObject)
{
}
