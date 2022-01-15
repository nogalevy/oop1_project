#include "GameObject.h"


GameObject::GameObject(Icons symbol, const sf::Vector2f& location, float objSize)
{
	m_icon.setTexture(*(Resources::instance().getIcon(symbol)));	
	m_icon.scale((objSize /512), (objSize / 512));
	m_icon.setPosition(location);
}

//-----------------------------------------------------------------

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}

//-----------------------------------------------------------------

sf::Vector2f GameObject::getPosition() const
{
	return m_icon.getPosition();
}

//-----------------------------------------------------------------

bool GameObject::checkColisionWith(const GameObject& obj) const
{
	if (&obj == this)
		return false;

	return m_icon.getGlobalBounds().intersects(obj.m_icon.getGlobalBounds());
}

//-----------------------------------------------------------------

void GameObject::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	
	//double dispatch
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

sf::Sprite& GameObject::getIcon()
{
	return m_icon;
}

//-----------------------------------------------------------------

void GameObject::setIcon(sf::Texture &texture)
{
	m_icon.setTexture(texture);
}
