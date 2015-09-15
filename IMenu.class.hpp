#ifndef IMENU_CLASS_HPP
# define IMENU_CLASS_HPP
# include "Graphic.class.hpp"
# include <iostream>
# include <string>

class IMenu
{
private:

	unsigned int	_quit;
	unsigned int	_option;
	unsigned int	_play;

protected:


public:

	IMenu();
	~IMenu();

	IMenu(const IMenu & imenu);

	IMenu(unsigned int quit,
		  unsigned int option,
		  unsigned int play);

	IMenu & operator=(const IMenu & imenu);

	void			setQuit(unsigned int quit);
	void			setOption(unsigned int option);
	void			setPlay(unsigned int play);

	unsigned int	getQuit(void) const;
	unsigned int	getOption(void) const;
	unsigned int	getPlay(void) const;

	void			launch(Graphic &graphic);

    void			menu(Graphic &graphic);

    void			play(Graphic &graphic, int difficulty);

};

std::ostream & operator<<(std::ostream & o, const IMenu & imenu);

#endif
