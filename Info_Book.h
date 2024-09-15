#ifndef INFO_BOOK_H
# define INFO_BOOK_H

# include <stdio.h>
# include <stdlib.h>
# include "structs.h"
//# include "global_variables.h"

/*
typedef struct s_book
{
	char		title[100];
	char		author[50];
	int		year;
	struct s_book	*next;
}		t_book;
*/

char    choose_an_option(void);
void    take_book_info(void);
char    *get_title(void);
int     compare(const char *s1, const char *s2);
t_book  *insert_book_info(char *title, char *author, int year);
//void    print_book_info(t_book *run);
void    free_list(void);
void	free_simple_pointer(void *ptr);

#endif //INFO_BOOK_H
