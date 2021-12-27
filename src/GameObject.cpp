#include "GameObject.h"


GameObject::GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight)
{
	//m_icon.setTexture(&textures[symbol]);
	sf::Texture texture;
	texture.loadFromFile("king.png");
	m_icon.setTexture(texture);

	//set the correct scale to fill the board according to map size
	auto xScaleValue = (float)WINDOW_W / ((float)ICON_SIZE * (float)mapWidth);
	auto yScaleValue = (float)WINDOW_H / ((float)ICON_SIZE * (float)mapHeight);

	m_icon.scale(0.9, 0.9);
	m_icon.setPosition(location);
}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window)
{
	std::cout << "draw icon\n";
	window.draw(m_icon);
}
