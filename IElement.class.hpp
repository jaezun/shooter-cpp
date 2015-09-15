#ifndef IELEMENT_CLASS_HPP
# define IELEMENT_CLASS_HPP
# include <iostream>
# include <string>

class	IElement{
protected:

	unsigned int	_hp;
	unsigned int	_posX;
	unsigned int	_posY;
	unsigned int	_sizeX;
	unsigned int	_sizeY;
	int				_speed;
	std::string*	_skin;

public:

	IElement();
	~IElement();
	IElement(unsigned int hp, unsigned int posX ,unsigned int posY, unsigned int sizeX, unsigned int sizeY, int speed, std::string* skin);
	IElement(IElement const & src);
	virtual	IElement & operator=(const IElement & rhs);
	virtual void	shoot(unsigned int bullets[143][3], unsigned int *nbBullets);

	void			setHp(unsigned int);
	void			setPosX(unsigned int);
	void			setPosY(unsigned int);
	void			setSizeX(unsigned int);
	void			setSizeY(unsigned int);
	void			setSpeed(int);
	void			setSkin(std::string*);

	unsigned int	getHp(void) const;
	unsigned int	getPosX(void) const;
	unsigned int	getPosY(void) const;
	unsigned int	getSizeX(void) const;
	unsigned int	getSizeY(void) const;
	int				getSpeed(void) const;
	std::string*	getSkin(void) const;

};

std::ostream & operator<<(std::ostream & o, IElement const & rhs);

#endif
