SRCS = Fixed.cpp main.cpp
OBJS = ${SRCS:.c=.o}
CC    = g++
CFLAGS	= -Wextra -Wall -Werror -std=c++98
NAME	= a.out
.c.o:		&{CC} &{CFLAGS} -c -o $@ $<

${NAME} : ${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:  ${NAME}

clean:
	 rm -f ${OBJS}
	
fclean :	clean
	rm -f ${NAME}

re : fclean all clean

.PHONY: all bonus clean fclean re