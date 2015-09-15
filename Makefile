SRCS	=	main.cpp Bullet.class.cpp Enemy.class.cpp Game.class.cpp Graphic.class.cpp Hero.class.cpp IElement.class.cpp IMenu.class.cpp Input.class.cpp
OBJS	=	$(SRCS:.cpp=.o)
LIB	=	-lncurses
NAME	=	shooter

all: $(NAME)

$(NAME): $(OBJS)
	clang++ -o $(NAME) -Wall -Werror -Wextra $(OBJS) $(LIB)

$(OBJS):
	clang++ -c $(SRCS) -Wall -Werror -Wextra $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
