NAME        =       server

INCLUDES	=		-I../includes

SRCS        =       src/main.c				\
					src/server.c			

OBJS        =       ${SRCS:.c=.o}

CFLAGS		=       -Wall -Wextra -Werror -g

CC			=		gcc

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(OBJS) ../libft/libft.a -o $(NAME) $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY : all fclean clean re