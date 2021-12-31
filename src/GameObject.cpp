#include "GameObject.h"


GameObject::GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight)
	: m_icon(sf::Vector2f(40.f, 40.f))
{
	//m_icon.setTexture(&textures[symbol]);
	//sf::Texture texture;
	
	//m_texture.loadFromFile(symbol == KING ?  "king.png" : "brickwall_2.png");
	//m_icon.setTexture(&m_texture);

	m_icon.setTexture(Resources::instance().getIcon(symbol));

	//set the correct scale to fill the board according to map size
	auto xScaleValue = (float)WINDOW_W / ((float)ICON_SIZE * (float)mapWidth);
	auto yScaleValue = (float)WINDOW_H / ((float)ICON_SIZE * (float)mapHeight);

	//m_icon.scale(0.9, 0.9);
	
	//m_icon.setTexture(&m_texture);
	m_icon.setPosition(location);
}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window)
{
	//m_icon.setTexture(&m_texture);
	//m_icon.setFillColor(sf::Color::Color(181, 147, 43));
	//m_icon.setPosition(location);

	//std::cout << "draw icon\n";
	window.draw(m_icon);
}
