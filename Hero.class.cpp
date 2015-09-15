#include "Hero.class.hpp"

Hero::Hero(void)
{
	std::cout << "[Constructor] Default constructor called" << std::endl;
	return;
}

Hero::~Hero(void)
{
	std::cout << "[Destructor] Destructor called" << std::endl;
	return;
}

Hero::Hero(const Hero & src) : IElement (src)
{
	std::cout << "[Constructor] Copy constructor called" << std::endl;
	*this = src;
	return;
}

Hero::Hero(
			unsigned int hp,
			unsigned int posX,
			unsigned int posY,
			unsigned int sizeX,
			unsigned int sizeY,
			int speed,
			std::string *skin,
			char upgrade,
			unsigned int life,
			unsigned int rateOfFire
) : IElement(hp, posX, posY, sizeX, sizeY, speed, skin), _upgrade(upgrade), _life(life), _rateOfFire(rateOfFire)
{
	return;
}

char				Hero::getUpgrade(void) const
{
	return (this->_upgrade);
}

void		Hero::setUpgrade(char upgrade)
{
	this->_upgrade = upgrade;
	return;
}

unsigned int		Hero::getLife(void) const
{
	return (this->_life);
}

void				Hero::setLife(unsigned int life)
{
	this->_life = life;
	return;
}

unsigned int		Hero::getRateOfFire(void) const
{
	return(this->_rateOfFire);
}

void				Hero::setRateOfFire(unsigned int rateOfFire)
{
	this->_rateOfFire = rateOfFire;
	return;
}

const Hero & Hero::operator=(const Hero & rhs)
{
	this->setUpgrade(rhs.getUpgrade());
	this->setLife(rhs.getLife());
	return (*this);
}

std::ostream & operator<<(std::ostream & o, const Hero & rhs)
{
	o << "UPGRADE: " << rhs.getUpgrade() << "LIFE: " << rhs.getLife();
	return (o);
}
