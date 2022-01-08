#include "GameObject.h"


GameObject::GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight)
	//: m_icon(sf::Vector2f(40.f, 40.f))
{
	m_icon.setTexture(*(Resources::instance().getIcon(symbol)));

	//set the correct scale to fill the board according to map size
	//auto xScaleValue = (float)BOARD_W / ((float)ICON_SIZE * (float)mapWidth);
	//auto yScaleValue = (float)BOARD_W / ((float)ICON_SIZE * (float)mapHeight);

	//m_icon.scale(xScaleValue, yScaleValue);
	m_icon.scale(0.1, 0.1);

	m_icon.setPosition(location);
}


//GameObject::~GameObject()
//{
//}

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

