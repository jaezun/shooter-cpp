#include "IMenu.class.hpp"

int		main(void)
{
	Graphic		graphic;
	IMenu		menu;

	graphic.init();
	menu.launch(graphic);
	return (0);
}
