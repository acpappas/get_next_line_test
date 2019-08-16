name =		gnl

SRCS =		get_next_line.c main.c

OBJS =		$(SRCS:.c=.o)

HEAD =		get_next_line.h

all:		$(NAME)
			

$(NAME):
			clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
			clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
			clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
		

clean:
			/bin/rm -f $(OBJS)

fclean:	clean
			/bin/rm -f $(NAME)

re:			fclean all
