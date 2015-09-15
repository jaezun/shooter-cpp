#include "IMenu.class.hpp"
#include "Game.class.hpp"
#include "Hero.class.hpp"


IMenu::IMenu(){
	std::cout
	<< "Default Constructor called"
	<<	std::endl;
	return ;
}

IMenu::~IMenu(){
	std::cout
	<< "Default Destructor called"
	<<	std::endl;
	return ;
}

IMenu::IMenu(const IMenu & imenu){
	this->setQuit(imenu.getQuit());
	this->setOption(imenu.getOption());
	this->setPlay(imenu.getPlay());
	std::cout
	<< "Copy Constructor called"
	<<	std::endl;
	return ;
}

IMenu::IMenu(unsigned int quit,
		  	 unsigned int option,
			 unsigned int play){
	setQuit(quit);
	setOption(option);
	setPlay(play);
	std::cout
	<< "Constructor with params called"
	<<	std::endl;
	return ;
}

IMenu & IMenu::operator=(const IMenu & imenu){
	this->setQuit(imenu.getQuit());
	this->setOption(imenu.getOption());
	this->setPlay(imenu.getPlay());
	std::cout
	<< "Constructor with Assignations called"
	<<	std::endl;
	return (*this);
}

void			IMenu::setQuit(unsigned int quit){
	this->_quit = quit;
}

void			IMenu::setOption(unsigned int option){
	this->_option = option;
}

void			IMenu::setPlay(unsigned int play){
	this->_play = play;
}

unsigned int	IMenu::getQuit(void) const{
	return (this->_quit);
}

unsigned int	IMenu::getOption(void) const{
	return (this->_option);
}

unsigned int	IMenu::getPlay(void) const{
	return (this->_play);
}

std::ostream & operator<<(std::ostream & o, const IMenu & imenu){
	o << imenu.getQuit();
	o << imenu.getOption();
	o << imenu.getPlay();
	return (o);
}

void			IMenu::launch(Graphic &graphic){
	Game		game;

    while (1) {
    	graphic.clear();
    	this->menu(graphic);
    	graphic.draw();
        if (getch() == '1') {
        	this->play(graphic, 1);
        }
        else if (getch() == '2') {
        	this->play(graphic, 2);
        }
        else if (getch() == '3') {
        	this->play(graphic, 3);
        }
        else if (getch() == '4') {
            break ;
        }
    }
	graphic.close();
}

void			IMenu::menu(Graphic &graphic){
	std::string		mainMenu("Main Menu");
	std::string		easy("[1] Easy");
	std::string		medium("[2] Medium");
	std::string		hard("[3] Hard");
	std::string		quit("[4] Quit");

	graphic.putImage(0, 0, 1, mainMenu.length(), &mainMenu);
    graphic.putImage(1, 0, 1, easy.length(), &easy);
    graphic.putImage(2, 0, 1, medium.length(), &medium);
    graphic.putImage(3, 0, 1, hard.length(), &hard);
    graphic.putImage(4, 0, 1, quit.length(), &quit);
}

void			IMenu::play(Graphic &graphic, int difficulty){
	Game		game;
	std::string	*image;
	int			x;
	int			y;

	image = new std::string [3];
	image[0] = "  #  ";
	image[1] = " ### ";
	image[2] = "#####";

	x = graphic.get_winX() / 2;
	y = graphic.get_winY() - 3;

	IElement	hero(1, x, y, 3, 5, 3, image);

	game.play(difficulty, graphic, hero);
}
