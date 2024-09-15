#include "Info_Book.h"

extern t_book	*g_root;

static t_book	*insert_book_info(char *title, char *author, int year)
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

static void	add_node_to_list(t_book *book, char *title)
{
	t_book	*run;
	t_book	*previous;

	if (!g_root)
		g_root = book;
	else
	{
		previous = g_root;
		run = g_root;
		while (run && compare(run->title, title) < 0)
		{
			previous = run;	
			run = run->next;
		}
		if (run == g_root)
		{
			g_root = book;
			book->next = run;
		}
		else
		{
			if (run)
				book->next = run;
			previous->next = book;
		}
	}
}

void	add_book(char *title, char *author, int year)
{
	t_book	*book;

	if (title && author)
	{
		book = insert_book_info(title, author, year);
		if (book)
			add_node_to_list(book, title);
		else
		{	
			write(2, ERR, ft_strlen(ERR));
			free_info(title, author);
		}
	}
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
}*/
