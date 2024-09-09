CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g -D BUFFER_SIZE=20

NAME 	= get_next_line
SRCS	= main.c get_next_line.c get_next_line_utils.c 


($NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: ($NAME)


clean: 
	rm -f $(NAME)

fclean: clean


re: fclean all


