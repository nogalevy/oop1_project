#include "GameObject.h"


GameObject::GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight)
	//: m_icon(sf::Vector2f(40.f, 40.f))
{
	int size = mapWidth < mapHeight ? mapHeight : mapWidth;

	float w =  float(BOARD_H - 30) / size;
	//float h = float(BOARD_H) / mapHeight;

	m_icon.setTexture(*(Resources::instance().getIcon(symbol)));

	//set the correct scale to fill the board according to map size
	//auto xScaleValue = (float)BOARD_W / ((float)ICON_SIZE * (float)mapWidth);
	//auto yScaleValue = (float)BOARD_W / ((float)ICON_SIZE * (float)mapHeight);

	//m_icon.scale(xScaleValue, yScaleValue);
	//m_icon.scale(0.105, 0.105);
	m_icon.scale((w/550), (w/ 550));

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
