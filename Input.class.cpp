#include "Input.class.hpp"

Input::Input(void) : _Up(KEY_UP), _Down(KEY_DOWN), _Left(KEY_LEFT), _Right(KEY_RIGHT), _Shoot(' '){

	return;

}

Input::Input(int up, int down, int left, int right, int shoot) : _Up(up), _Down(down), _Left(left), _Right(right), _Shoot(shoot){

	return;

}

Input::Input(const Input & input){

	*this = input;

	return;

}

Input::~Input(void){
	return;
}

Input & Input::operator=(Input const & input){

	if(this == &input)
	{
		this->_Up = input.getUp();
		this->_Down = input.getDown();
		this->_Left = input.getLeft();
		this->_Right = input.getRight();
		this->_Shoot = input.getShoot();
	}
	return (*this);
}

int Input::getUp(void) const {
	return(this->_Up);
}
void Input::setUp(int i){
	this->_Up = i;
}

int Input::getDown(void) const {
	return(this->_Down);
}
void Input::setDown(int i){
	this->_Down = i;
}

int Input::getLeft(void) const {
	return(this->_Left);
}
void Input::setLeft(int i){
	this->_Left = i;
}

int Input::getRight(void) const {
	return(this->_Right);
}
void Input::setRight(int i){
	this->_Right = i;
}

int Input::getShoot(void) const {
	return(this->_Shoot);
}
void Input::setShoot(int i){
	this->_Shoot = i;
}

int Input::Action(int touch, IElement &hero, Graphic &win, int game,
 					unsigned int bullets[143][3], unsigned int *nbBullets){
	if(game == 1)
	{
		if(touch == this->_Up)
		{
			if(hero.getPosY() > 0)
				hero.setPosY(hero.getPosY() - 1);
		}
		else if(touch == this->_Down)
		{
			if((hero.getPosY() + hero.getSizeY()) - 2 < (unsigned int)win.get_winY())
				hero.setPosY(hero.getPosY() + 1);
		}
		else if(touch == this->_Left)
		{
			if(hero.getPosX() > 0)
				hero.setPosX(hero.getPosX() - 1);
		}
		else if(touch == this->_Right)
		{
			if((hero.getPosX() + hero.getSizeX()) + 2 < (unsigned int)win.get_winX())
				hero.setPosX(hero.getPosX() + 1);
		}
		else if(touch == 27)
		{
			return (0);
		}
		else if(touch == this->_Shoot)
		{
			if(*nbBullets < 140)
			{
				*nbBullets += 1;
				hero.shoot(bullets, nbBullets);
				if (*nbBullets == 139)
					*nbBullets = 0;
			}
		}
	}
	return (1);
}

std::ostream & operator<<(std::ostream & o, const Input & rhs)
{
	o << rhs.getUp();
	return (o);
}
