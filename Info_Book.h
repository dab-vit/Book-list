#ifndef INFO_BOOK_H
# define INFO_BOOK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "structs.h"

# define BUFFER 100

# define TITLE "Type title.\n"
# define TITLE_1 "Type the exact title. It is case sensitive.\n"
# define AUTHOR "Type author.\n"
# define YEAR "Type publication year (yyyy).\n"
# define ERR "An error ocurred. Please, try again.\n"
# define ERR_YEAR "Incorrect year format. Please, try again.\n"

char    choose_an_option(void);
void    take_book_info(void);
//char    *get_title(void);
int     ft_strlen(char *str);
int     ascii_year_to_integer(const char *str);
int     compare(const char *s1, const char *s2);
//t_book  *insert_book_info(char *title, char *author, int year);
char	*ft_strdup(const char *src);
char	*get_data_info(char *data_type);
void	add_book(char *title, char *author, int year);

char    check_year_length(char *year);
char    check_year_digits(char *year);

void    remove_book(char *title);
void    list_books(void);
void    search_book(char *title);

void    free_simple_pointer(void *ptr);
void	free_info(char *title, char *author);
void    free_list_node(t_book *previous);
void    free_list(void);

#endif //INFO_BOOK_H
