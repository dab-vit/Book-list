
NAME = infobook

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = -f

SRCS =	add_book.c\
	check_year.c\
	choose_an_option.c\
	executing_functions.c\
	Info_Book.c\
	Info_Book_utils.c\
	free_functions.c\
	take_book_info.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
