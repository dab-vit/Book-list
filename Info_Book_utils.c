
#include "Info_Book.h"

//extern t_book	*g_root;

//void    add_book(char *title, char *author, int year);

void	select_option_mssg(void)
{
	printf("Please, select an option between 1 and 5\n");
	printf("1 - Add_book\n");
	printf("2 - Remove book\n");
	printf("3 - List books\n");
	printf("4 - Search book\n");
	printf("5 - Exit program\n");
}

char	choose_an_option(void)
{
	int	option;

	option = 0;
	while (option < 1 || option > 5)
	{
		printf("\n");
		select_option_mssg();
		scanf("%i", &option);
		fflush(stdin);
	}
	return (option);
}
/*
void	take_book_info(void)
{
	char	*title;
	char	*author;
	int	year;
	int	chars_read;

	title = malloc(sizeof(char) * 101);
	author = malloc(sizeof(char) * 51);
	if (title && author)
	{
		printf("\nType book title\n");
		chars_read = read(0, title, 100);
		title[chars_read] = '\0';
		printf("\nType author\n");
		chars_read = read(0, author, 50);
		title[chars_read] = '\0';
		printf("\nType publication year\n");
		scanf("%d", &year);
		printf("title: %s\t author: %s\t year %i\n", title, author, year);
		add_book(title, author, year);
	}
	else
	{
		printf("Error. Try again\n");
		free_simple_pointer(title);
		free_simple_pointer(title);
	}
}
*/
char	*get_title(void)
{
	char    *title;
	int     chars_read;
	
	title = malloc(sizeof(char) * 101);
	if (title)
	{
		printf("Introduce book title\n");
		chars_read = read(0, title, 100);
		title[chars_read] = '\0';
	}
	return (title);
}
/*
t_book	*insert_book_info(char *title, char *author, int year)
{
	t_book	*book;

	book = malloc(sizeof(t_book));
	if (book)
	{
		book->title = title;
		book->author = author;
		book->year = year;
		book->next = (void *) 0;
	}
	return (book);
}
*/
int	compare(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
