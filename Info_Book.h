
#ifndef INFO_BOOK_H
# define INFO_BOOK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Info_structs.h"
# include "Info_mssg.h"

# define BUFFER 100

// Input data
char    choose_an_option(void);
void    take_book_info(void);
char	*get_data_info(char *data_type);

// Check functions
char    check_year_length(char *year);
char    check_year_digits(char *year);

// Data actions
void    add_book(char *title, char *author, int year);
void    remove_book(char *title);
void    list_books(void);
void    search_book(char *title);

// Utils
int     ft_strlen(char *str);
int     ascii_year_to_integer(const char *str);
char    *ft_strdup(const char *src);
int     compare(const char *s1, const char *s2);

// Free functions
void    free_simple_pointer(void *ptr);
void	free_info(char *title, char *author);
void    free_list_node(t_book *previous);
void    free_list(void);

#endif //INFO_BOOK_H
