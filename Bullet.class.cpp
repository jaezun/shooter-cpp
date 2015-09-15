#include <string>
#include <iostream>
#include "Bullet.class.hpp"
#include "IElement.class.hpp"

Bullet::Bullet(void)
{
	return ;
}
Bullet::Bullet(const Bullet &src): IElement(src)
{
	*this = src;

	return ;
}
Bullet::Bullet(int pv, int posX, int posY, int sizeX, int sizeY, int speed, std::string *skin, int damage)
: IElement(pv, posX, posY, sizeX, sizeY, speed, skin), _damage(damage)
{
	return ;
}
Bullet::~Bullet(void)
{

	return ;
}

Bullet		&Bullet::operator=(const Bullet &rhs)
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
		this->setDamage(rhs.getDamage());
	}
	return (*this);
}

void		Bullet::touch(IElement &target)
{
	this->setHp(0);
	if (this->getHp() > 0)
	{
		if (target.getHp() > this->getDamage())
			target.setHp(target.getHp() - this->getDamage());
		else
			target.setHp(0);
	}
}

//int			Bullet::collide()
//{
//	IElement **elements = game->getElements();
//
//	for(IElement *i : elements)
//	{
//		if (this->getPosX() == i->getPosX() && this->getPosY() == i->getPosY())
//			return (i);
//	}
//	return (0);
//}

void		Bullet::move(void)
{
	while (/*this->collide() == 1 || */this->getPosY() > 0)
	{
		this->setPosY(this->getPosY() - 1);
	}
	//if (this->collide() /*this->getPosY() == 0*/)
	//	this->touch(this->collide());

}

unsigned int	Bullet::getDamage(void) const
{
	return (this->_damage);
}
void			Bullet::setDamage(unsigned int damage)
{
	this->_damage = damage;
}
