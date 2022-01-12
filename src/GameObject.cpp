#include "GameObject.h"


GameObject::GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight)
	//: m_icon(sf::Vector2f(40.f, 40.f))
{
	int size = mapWidth < mapHeight ? mapHeight : mapWidth;

	int divide_by = symbol == WALL ? 5.5 : 6;
	float w =  (float(BOARD_H - 30) / size) / divide_by;
	//float h = float(BOARD_H) / mapHeight;

	m_icon.setTexture(*(Resources::instance().getIcon(symbol)));

	
	m_icon.scale((w/100), (w/ 100));

	m_icon.setPosition(location);
}


void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}

bool GameObject::checkColisionWith(const GameObject& obj) const
{
	if (&obj == this)
		return false;

	return m_icon.getGlobalBounds().intersects(obj.m_icon.getGlobalBounds());
}

sf::Vector2f GameObject::getPosition() const
{
	return m_icon.getPosition();
}

void GameObject::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

sf::Sprite& GameObject::getIcon()
{
	return m_icon;
}

void GameObject::setIcon(sf::Texture &texture)
{
	m_icon.setTexture(texture);
}
