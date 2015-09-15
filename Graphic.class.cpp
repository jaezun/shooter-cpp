#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include "Graphic.class.hpp"
#include "IElement.class.hpp"

void                    Graphic::putElement(IElement element)
{
    if (element.getHp() != 0)
        this->putImage(element.getPosY(), element.getPosX(),
                        element.getSizeX(), element.getSizeY(),
                        element.getSkin());
}

void                    Graphic::putImage(int x, int y, int w, int h,
                                                        std::string *pattern)
{
    int                 i;
    int                 iP;
    int                 j;
    int                 jP;
    int                 wP;
    int                 hP;

    i = x;
    iP = 0;
    wP = x + w;
    hP = y + h;
    while (i < wP)
    {
        j = y;
        jP = 0;
        while (j < hP)
        {
            if (i >= 0 && i < this->_winY && j >= 0 && j < this->_winX)
                if (pattern[iP][jP] != ' ')
                    this->_image[i][j] = pattern[iP][jP];
            j++;
            jP++;
        }
        i++;
        iP++;
    }
    i = x;
    iP = 0;
    wP = x + w;
    hP = y + h;
    while (i < wP)
    {
        j = y;
        jP = 0;
        while (j < hP)
        {
            if (i >= 0 && i < this->_winY && j >= 0 && j < this->_winX)
                if (pattern[iP][jP] == ' ')
                    this->_image[i][j] = this->_back[i][j];
            j++;
            jP++;
        }
        i++;
        iP++;
    }
}

void                    Graphic::clear(void)
{
    int                 i;
    int                 j;
    std::string         tmpLine;

    tmpLine = this->_back[54];
    i = 54;
    while (i > 0)
    {
        this->_back[i] = this->_back[i - 1];
        i--;
    }
    this->_back[0] = tmpLine;
    i = 0;
    while (i < this->_winY)
    {
        j = 0;
        while (j < this->_winX)
        {
            this->_image[i][j] = this->_back[i][j];
            j++;
        }
        i++;
    }
}
void                    Graphic::draw(void)
{
    int                 i;

    i = 0;
    while (i < this->_winY)
    {
        mvwprintw(this->_win, i, 0, "%s", this->_image[i].c_str());
        i++;
    }
    wrefresh(this->_win);
}

void                    Graphic::init(void)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(15);
    keypad(stdscr, TRUE);
    this->_win = newwin(55, 113, 0, 0);
    return ;
}

void                    Graphic::close(void)
{
    endwin();
    return ;
}

WINDOW                  *Graphic::get_win(void) const
{
    return (this->_win);
}

int                     Graphic::get_winY(void) const
{
    return (this->_winY);
}

int                     Graphic::get_winX(void) const
{
    return (this->_winX);
}

void                    Graphic::set_win(WINDOW *win)
{
    this->_win = win;
}

void                    Graphic::set_winY(int y)
{
    this->_winY = y;
}

void                    Graphic::set_winX(int x)
{
    this->_winX = x;
}

Graphic::Graphic(Graphic &graphic)
{
    std::cout << "copy" << std::endl;

    this->set_winX(graphic.get_winX());
    this->set_winY(graphic.get_winY());
    this->set_win(graphic.get_win());
    this->_image = new std::string [graphic.get_winY()];
    this->_back = new std::string [graphic.get_winY()];
}

Graphic::Graphic(void)
{
    int                 i;
    int                 j;

    this->set_winX(113);
    srand(time(NULL));
    this->set_winY(55);
    this->_image = new std::string [this->get_winY()];
    this->_back = new std::string [this->get_winY()];
    i = 0;
    while (i < this->get_winY())
    {
        j = 0;
        while (j < this->get_winX())
        {
            if (rand() % 10)
            {
                this->_back[i] += ' ';
                this->_image[i] += ' ';
            }
            else
            {
                this->_back[i] += '.';
                this->_image[i] += '.';
            }
            j++;
        }
        i++;
    }
    std::cout << "Constructor called" << std::endl;
    return ;
}

Graphic::~Graphic(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Graphic                 &Graphic::operator=(Graphic const &graphic)
{
    std::cout << "assignation" << std::endl;
    this->set_winX(graphic.get_winX());
    this->set_winY(graphic.get_winY());
    this->set_win(graphic.get_win());
    this->_image = new std::string [graphic.get_winY()];
    this->_back = new std::string [graphic.get_winY()];
    return (*this);
}
