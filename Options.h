#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameParameters.h"
#include "OptionsLayout.h"


class Options
{
private:

	GameParameters* gameParameters;
	OptionsLayout optionsLayout;
	sf::RenderWindow* window;

public:

	Options(GameParameters* parameters, sf::RenderWindow *window);

	bool isOpen();
	void update();
	void pollEvents();

	void render();
};

