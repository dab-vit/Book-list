#ifndef INFO_BOOK_H
# define INFO_BOOK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "structs.h"

char    choose_an_option(void);
void    take_book_info(void);
char    *get_title(void);
int     compare(const char *s1, const char *s2);
t_book  *insert_book_info(char *title, char *author, int year);

void    remove_book(char *title);
void    list_books(void);
void    search_book(char *title);

void    free_simple_pointer(void *ptr);
void    free_list_node(t_book *previous);
void    free_list(void);

#endif //INFO_BOOK_H
