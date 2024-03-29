#include "Button.h"

Button::Button(sf::Vector2f size, sf::Color color, std::string txt, sf::Vector2f pos)
{
	initFont();
	setText(txt);
	rect.setFillColor(color);
	rect.setSize(size);
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color::Black);
	setPosition(pos);
}

void Button::initFont()
{
	if (font.loadFromMemory(&Roboto_Regular_ttf, Roboto_Regular_ttf_len)) {
		text.setFont(font);
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
	}
	//else std::cout << "ERROR: Game::initText() - font not loaded\n";
}


void Button::setSize(sf::Vector2f newSize)
{
	rect.setSize(newSize);
}

void Button::setColor(sf::Color color)
{
	rect.setFillColor(color);
}

void Button::setText(std::string txt)
{
	std::stringstream ss;
	ss << txt;
	text.setString(ss.str());
}

void Button::setTextColor(sf::Color color, sf::Color outline=sf::Color::Black)
{
	text.setFillColor(color);
	text.setOutlineColor(outline);
}

void Button::setFontSize(int size)
{
	text.setCharacterSize(size);
}


void Button::setPosition(sf::Vector2f newPos)
{
	rect.setPosition(newPos);
	text.setPosition(newPos.x + (rect.getGlobalBounds().width / 2.f) - (text.getGlobalBounds().width / 2.f),
		newPos.y + (rect.getGlobalBounds().height / 2.f) - (text.getGlobalBounds().height));
}

sf::RectangleShape Button::getButton()
{
	return rect;
}

bool Button::isMouseOver(sf::Vector2f mousePos)
{
	if (mousePos.x > rect.getGlobalBounds().left &&
		mousePos.x < rect.getGlobalBounds().left + rect.getSize().x &&
		mousePos.y > rect.getGlobalBounds().top &&
		mousePos.y < rect.getGlobalBounds().top + rect.getSize().y) {

		return true;
	}

	else return false;
}



void Button::renderButton(sf::RenderWindow* window)
{
	window->draw(rect);
	window->draw(text);
}
