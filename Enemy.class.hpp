#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP
# include "IElement.class.hpp"

class Enemy : IElement
{
protected:
	std::string		_type;
	unsigned int	_rateOfFire;
public:
	Enemy(void);
	Enemy(const Enemy &src);
	Enemy(int pv, int posX, int posY, int sizeX, int sizeY, int speed, std::string *skin, std::string type, int rateOfFire);
	~Enemy(void);

	Enemy	&operator=(const Enemy &rhs);

	void			die(void);

	std::string		getType(void) const;
	void			setType(std::string type);

	unsigned int	getRateOfFire(void) const;
	void			setRateOfFire(unsigned int rateOfFire);
};

#endif // ENEMY_CLASS_HPP //
