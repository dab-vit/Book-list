#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_book
{
	char		*title;
	char		*author;
	int		year;
	struct s_book	*next;
}		t_book;

#endif //STRUCTS_H
