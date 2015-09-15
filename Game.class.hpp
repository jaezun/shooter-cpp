#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include "IElement.class.hpp"
#include "Graphic.class.hpp"
#include "Hero.class.hpp"

class               Game {
private:
    IElement        *enemies;
    unsigned int    nbEnemies;
    IElement        hero;
    IElement        *bullets;
    unsigned int    nbBullets;
    unsigned int    score;
    int             lives;
    unsigned int    bullet_list[143][3];
    unsigned int    enemy_list[100][4];

public:
    Game(void);
    Game(Game const &game);
    ~Game(void);

    Game &operator=(Game const &game);

    void            addEnemy(void);
    void            delEnnemy(unsigned int index);
    void            addBullet(void);
    void            delBullet(unsigned int index);
    void            addHero(void);
    void            delHero(void);
    void            play(int difficulty, Graphic &graphic, IElement &hero);

    void            setNbEnemies(unsigned int nb);
    void            setNbBullets(unsigned int nb);
    void            setEnemies(IElement *enemies);
    void            setBullets(IElement *bullets);
    void            setHero(IElement const &hero);

    unsigned int    getNbEnemies(void) const;
    unsigned int    getNbBullets(void) const;
    IElement        *getEnemies(void) const;
    IElement        getHero(void) const;
    IElement        *getBullets(void) const;
    int             collide(IElement &hero, unsigned int enemyX, unsigned int enemyY, unsigned int sizeX, unsigned int sizeY);
    int             collideBullet(unsigned int bulletX, unsigned int bulletY, unsigned int enemyX, unsigned int enemyY, unsigned int sizeX, unsigned int sizeY);
};

#endif
