#include <stdlib.h>
#include <sstream>
#include "Game.class.hpp"
#include "Input.class.hpp"

int                 Game::collideBullet(unsigned int bulletX, unsigned int bulletY, unsigned int enemyX, unsigned int enemyY, unsigned int sizeX, unsigned int sizeY)
{
    if (bulletX > enemyX && bulletX < enemyX + sizeX && bulletY > enemyY && bulletY < enemyY + sizeY)
        return (1);
    else
        return (0);
}


int                 Game::collide(IElement &hero, unsigned int enemyX, unsigned int enemyY, unsigned int sizeX, unsigned int sizeY)
{
    if ((enemyX > hero.getPosX() && enemyX < hero.getPosX() + hero.getSizeX() && enemyY > hero.getPosY() && enemyY < hero.getPosY() + hero.getSizeY()) ||
        (enemyX + sizeX > hero.getPosX() && enemyX + sizeX < hero.getPosX() + hero.getSizeX() && enemyY > hero.getPosY() && enemyY < hero.getPosY() + hero.getSizeY()) ||
        (enemyX > hero.getPosX() && enemyX < hero.getPosX() + hero.getSizeX() && enemyY + sizeY > hero.getPosY() && enemyY + sizeY < hero.getPosY() + hero.getSizeY()) ||
        (enemyX + sizeX > hero.getPosX() && enemyX + sizeX < hero.getPosX() + hero.getSizeX() && enemyY + sizeY > hero.getPosY() && enemyY + sizeY < hero.getPosY() + hero.getSizeY()))
        return (1);
    else
        return (0);
}

void                Game::play(int difficulty, Graphic &graphic, IElement &hero)
{
    unsigned int    i;
    unsigned int    j;
    std::string	hiScore = "HI-SCORE: 155351";
    std::string	score = "SCORE: 0";
    std::string	lives = "LIVES: ";
    std::string	shield = "SHIELD: NONE";
    std::string bulletSkin = "|";
    std::string *enemySkin;
    enemySkin = new std::string [3];
    enemySkin[0] = "[] []";
    enemySkin[1] = "[O O]";
    enemySkin[2] = "'-U-'";
    int             globalSpeed;
    unsigned int    pop = 40 / difficulty;
    Input           input;

    this->setHero(hero);
    globalSpeed = 0;
    while (input.Action(getch(), this->hero, graphic, 1, this->bullet_list, &this->nbBullets))
    {
        if (globalSpeed % 3 == 0)
            graphic.clear();
        graphic.putElement(this->hero);
        if (rand() % pop == 0)
        {
            enemy_list[nbEnemies][0] = 0;
            enemy_list[nbEnemies][1] = rand() % 108;
            enemy_list[nbEnemies][3] = 1;
            nbEnemies += 1;
        }
        i = 0;
        while (i < this->nbEnemies)
        {
            if (globalSpeed % 5 == 0)
            {
                this->enemy_list[i][2] = rand() % 3;
                if (enemy_list[i][2] == 0)
                    this->enemy_list[i][1] -= 1;
                else if (enemy_list[i][2] == 1)
                    this->enemy_list[i][1] += 1;
                this->enemy_list[i][0] += 1;
            }
            std::string          e;
            std::stringstream    eTmp;
            eTmp << this->nbEnemies;
            e = eTmp.str();
            graphic.putImage(10, 0, 1, e.length(), &e);
            if (enemy_list[i][3] == 1)
                graphic.putImage(this->enemy_list[i][0], this->enemy_list[i][1], 3, 5, enemySkin);
            if (this->collide(this->hero, this->enemy_list[i][1], this->enemy_list[i][0], 5, 3))
            {
                this->lives -= 1;
                this->enemy_list[i][0] = 56;
                enemy_list[nbEnemies][3] = 0;
            }
            unsigned int j = 0;
            while (j < this->nbBullets)
            {
                if (this->collideBullet(this->bullet_list[j][1], this->bullet_list[j][0], this->enemy_list[i][1], this->enemy_list[i][0], 5, 3))
                {
                    this->enemy_list[i][0] = 56;
                    enemy_list[nbEnemies][3] = 0;
                    this->bullet_list[j][0] = 0;
                    this->score += 10;
                }
                j++;
            }
            i++;
        }
        i = 0;
        while (i < this->nbBullets)
        {
            this->bullet_list[i][0] -= 1;
            graphic.putImage(bullet_list[i][0], bullet_list[i][1], 1, 1, &bulletSkin);
            i++;
        }
        std::stringstream   l;
        l << this->lives;
        lives += l.str();

        std::stringstream   s;
        s << this->score;
        score += s.str();
        graphic.putImage(0, 0, 1, hiScore.length(), &hiScore);
        graphic.putImage(1, 0, 1, score.length(), &score);
        graphic.putImage(2, 0, 1, lives.length(), &lives);
        graphic.putImage(3, 0, 1, shield.length(), &shield);

        lives = "Lives: ";
        score = "Score: ";
        graphic.draw();
        i = 0;
        while (i < this->nbBullets)
        {
            if (this->bullet_list[i][0] <= 0)
            {
                j = i + 1;
                while (j < this->nbBullets)
                {
                    if (j > 0)
                    {
                        this->bullet_list[j - 1][0] = this->bullet_list[j][0];
                        this->bullet_list[j - 1][1] = this->bullet_list[j][1];
                    }
                    j++;
                }
                this->nbBullets -= 1;
                break;
            }
            i++;
        }
        i = 0;
        while (i < this->nbEnemies)
        {
            if (this->enemy_list[i][0] >= 55)
            {
                j = i + 1;
                while (j < this->nbEnemies)
                {
                    if (j > 0)
                    {
                        this->enemy_list[j - 1][0] = this->enemy_list[j][0];
                        this->enemy_list[j - 1][1] = this->enemy_list[j][1];
                    }
                    j++;
                }
                this->nbEnemies -= 1;
                break;
            }
            i++;
        }
        if (globalSpeed == 5000)
            globalSpeed = 0;
        globalSpeed += 1;
        if (this->lives == 0)
            break;
    }
    graphic.close();
}

IElement            Game::getHero(void) const
{
    return (this->hero);
}

IElement            *Game::getBullets(void) const
{
    return (this->bullets);
}

IElement            *Game::getEnemies(void) const
{
    return (this->enemies);
}

unsigned int        Game::getNbBullets(void) const
{
    return (this->nbBullets);
}

unsigned int        Game::getNbEnemies(void) const
{
    return (this->nbEnemies);
}

void                Game::setHero(IElement const &hero)
{
    this->hero = hero;
}

void                Game::setBullets(IElement *bullets)
{
    this->bullets = bullets;
}

void                Game::setEnemies(IElement *enemies)
{
    this->enemies = enemies;
}

void                Game::setNbBullets(unsigned int nb)
{
    this->nbBullets = nb;
}

void                Game::setNbEnemies(unsigned int nb)
{
    this->nbEnemies = nb;
}

Game                &Game::operator=(Game const &game)
{
    this->setEnemies(game.getEnemies());
    this->setNbEnemies(game.getNbEnemies());
    this->setHero(game.getHero());
    this->setBullets(game.getBullets());
    this->setNbBullets(game.getNbBullets());
    return (*this);
}

Game::Game(Game const &game)
{
    this->setEnemies(game.getEnemies());
    this->setNbEnemies(game.getNbEnemies());
    this->setHero(game.getHero());
    this->setBullets(game.getBullets());
    this->setNbBullets(game.getNbBullets());
}

Game::Game(void)
{
    this->nbEnemies = 0;
    this->nbBullets = 0;
    this->score = 0;
    this->lives = 10;
    return ;
}

Game::~Game(void)
{
    return ;
}
