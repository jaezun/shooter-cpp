#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP
# include "IElement.class.hpp"

class Bullet : IElement
{
protected:
	unsigned int	_damage;
	Bullet			*next;

public:
	Bullet(void);
	Bullet(const Bullet &src);
	Bullet(int pv, int posX, int posY, int sizeX, int sizeY, int speed, std::string *skin, int damage);
	~Bullet(void);

	Bullet			&operator=(const Bullet &rhs);
	void			move(void);
	void			touch(IElement &target);
	//void			collide(void);

	unsigned int	getDamage() const;
	void			setDamage(unsigned int damage);
};

#endif // BULLET_CLASS_HPP //
