#ifndef HERO_CLASS_HPP
# define HERO_CLASS_HPP
# include <iostream>
# include <string>
# include "IElement.class.hpp"
# include "Bullet.class.hpp"

class Hero:IElement {

private:
	char			_upgrade;
	unsigned int	_life;
	unsigned int	_rateOfFire;

public:
	Hero(void);
	Hero(const Hero & src);
	Hero(
			unsigned int hp,
			unsigned int posX,
			unsigned int posY,
			unsigned int sizeX,
			unsigned int sizeY,
			int speed,
			std::string *skin,
			char upgrade,
			unsigned int life,
			unsigned int rateOfFires
	);
	~Hero(void);

	char			getUpgrade(void) const;
	void			setUpgrade(char upgrade);

	unsigned int	getLife(void) const;
	void			setLife(unsigned int life);

	unsigned int	getRateOfFire(void) const;
	void			setRateOfFire(unsigned int rateOfFire);

	const Hero & operator=(const Hero & rhs);

};

std::ostream & operator<<(std::ostream & o, const Hero & rhs);

#endif //HERO_CLASS_HPP//
