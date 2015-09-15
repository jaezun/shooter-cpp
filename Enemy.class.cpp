#include <iostream>
#include <string>
#include "IElement.class.hpp"
#include "Enemy.class.hpp"
#include "Bullet.class.hpp"

Enemy::Enemy(void)
{
	std::cout << "Enemy : Default constructor called." << std::endl;
	return ;
}
Enemy::Enemy(const Enemy &src): IElement(src)
{
	*this = src;

	std::cout << "Enemy : Copy constructor called." << std::endl;
	return ;
}
Enemy::Enemy(int pv, int posX, int posY, int sizeX, int sizeY, int speed, std::string *skin, std::string type, int rateOfFire): IElement(pv, posX, posY, sizeX, sizeY, speed, skin), _type(type), _rateOfFire(rateOfFire)
{
	std::cout << "Enemy : Param constructor called" << std::endl;
	return ;
}
Enemy::~Enemy(void)
{
	std::cout << "Enemy : Destructor called." << std::endl;

	return ;
}

Enemy		&Enemy::operator=(const Enemy &rhs)
{
	if (this != &rhs)
	{
		this->setHp(rhs.getHp());
		this->setPosX(rhs.getPosX());
		this->setPosY(rhs.getPosY());
		this->setSizeX(rhs.getSizeX());
		this->setSizeY(rhs.getSizeY());
		this->setSpeed(rhs.getSpeed());
		this->setSkin(rhs.getSkin());
		this->setType(rhs.getType());
		this->setRateOfFire(rhs.getRateOfFire());
	}
	return (*this);
}

void			Enemy::die(void)
{
	// blabla
}

std::string		Enemy::getType(void) const
{
	return (this->_type);
}
void			Enemy::setType(std::string type)
{
	this->_type = type;
}

unsigned int	Enemy::getRateOfFire(void) const
{
	return (this->_rateOfFire);
}
void			Enemy::setRateOfFire(unsigned int rateOfFire)
{
	this->_rateOfFire = rateOfFire;
}
