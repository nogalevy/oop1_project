#include "Teleport.h"

Teleport::~Teleport()
{
}

//sf::Vector2f Teleport::getPosition() const
//{
//	return m_icon.getPosition();
//}

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
	//std::cout << "yea boiiii\n";
	//if(gameObject.getPosition() != m_partner)
		//gameObject.setPosition(m_partner);

	//gameObject.handleCollision(*this); //send more data? next position or somthing?
}

void Teleport::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(Dwarf& gameObject)
{
}
