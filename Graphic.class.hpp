#ifndef GRAPHIC_CLASS_HPP
# define GRAPHIC_CLASS_HPP

# include <ncurses.h>
# include <string>
# include "IElement.class.hpp"

class                   Graphic {

private:
    WINDOW              *_win;
    std::string         *_image;
    std::string         *_back;
    int                 _winX;
    int                 _winY;

    void                set_winX(int x);
    void                set_winY(int y);
    void                set_win(WINDOW *win);

    Graphic(Graphic &graphic);
    Graphic             &operator=(Graphic const &graphic);

public:
    Graphic(void);
    ~Graphic(void);

    int                 get_winX(void) const;
    int                 get_winY(void) const;
    WINDOW              *get_win(void) const;

    void                init(void);
    void                close(void);
    void                clear(void);
    void                draw(void);

    void                putImage(int x, int y, int w, int h, std::string *pattern);
    void                putElement(IElement element);

};

#endif
