#ifndef INPUT_CLASS_H
# define INPUT_CLASS_H
# include <iostream>
# include <ncurses.h>
# include "IElement.class.hpp"
# include "Graphic.class.hpp"
# include "Bullet.class.hpp"

class Input {

private:

	int _Up;
	int _Down;
	int _Left;
	int _Right;
	int _Shoot;

public:

	Input(void);
	Input(int up, int down, int left, int right, int shoot);
	Input(const Input & input);
	~Input(void);
	Input & operator=(Input const & rhs);

	int getUp(void) const;
	void setUp(int i);

	int getDown(void) const;
	void setDown(int i);

	int getLeft(void) const;
	void setLeft(int i);

	int getRight(void) const;
	void setRight(int i);

	int getShoot(void) const;
	void setShoot(int i);

	int Action(int touch, IElement &hero, Graphic &win, int game,
					unsigned int bullets[143][3], unsigned int *nbBullets);

};

std::ostream & operator<<(std::ostream & o, const Input & rhs);

#endif
