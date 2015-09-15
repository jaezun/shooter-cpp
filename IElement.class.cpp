#include "IElement.class.hpp"
#include "Bullet.class.hpp"

IElement::IElement(){
	return ;
}

IElement::~IElement(){
	return ;
}

IElement::IElement(unsigned int hp, unsigned int posX ,unsigned int posY, unsigned int sizeX, unsigned int sizeY, int speed, std::string* skin){
	setHp(hp);
	setPosX(posX);
	setPosY(posY);
	setSizeX(sizeX);
	setSizeY(sizeY);
	setSpeed(speed);
	setSkin(skin);
	return ;
}

IElement::IElement(const IElement & ielement){
	this->setHp(ielement.getHp());
	this->setPosX(ielement.getPosX());
	this->setPosY(ielement.getPosY());
	this->setSizeX(ielement.getSizeX());
	this->setSizeY(ielement.getSizeY());
	this->setSpeed(ielement.getSpeed());
	this->setSkin(ielement.getSkin());
	return ;
}

IElement & IElement::operator=(const IElement & ielement){

	this->setHp(ielement.getHp());
	this->setPosX(ielement.getPosX());
	this->setPosY(ielement.getPosY());
	this->setSizeX(ielement.getSizeX());
	this->setSizeY(ielement.getSizeY());
	this->setSpeed(ielement.getSpeed());
	this->setSkin(ielement.getSkin());
	return (*this);
}

std::ostream & operator<<(std::ostream & o, IElement const & rhs){
	o << "IElement ostream<< ";
	o << rhs.getHp();
	o << std::endl;
	return o;
}

void			IElement::shoot(unsigned int bullets[143][3], unsigned int *nbBullets)
{
	bullets[*nbBullets][0] = this->getPosY() - 1;
	bullets[*nbBullets][1] = this->getPosX() + 2;
	return;
}

void			IElement::setHp(unsigned int hp){
	this->_hp = hp;
}

void			IElement::setPosX(unsigned int posX){
	this->_posX = posX;
}

void			IElement::setPosY(unsigned int posY){
	this->_posY = posY;
}

void			IElement::setSizeX(unsigned int sizeX){
	this->_sizeX = sizeX;
}

void			IElement::setSizeY(unsigned int sizeY){
	this->_sizeY = sizeY;
}

void			IElement::setSpeed(int speed){
	this->_speed = speed;
}

void			IElement::setSkin(std::string* skin){
	this->_skin = skin;
}

unsigned int	IElement::getHp(void) const{
	return(this->_hp);
}

unsigned int	IElement::getPosX(void) const{
	return(this->_posX);
}

unsigned int	IElement::getPosY(void) const{
	return(this->_posY);
}

unsigned int	IElement::getSizeX(void) const{
	return(this->_sizeX);
}

unsigned int	IElement::getSizeY(void) const{
	return(this->_sizeY);
}

int				IElement::getSpeed(void) const{
	return(this->_speed);
}

std::string*	IElement::getSkin(void) const{
	return(this->_skin);
}
