
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

static void	where_to_insert(t_book *run, t_book *previous, t_book *book)
{
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

static char	add_node_to_list(t_book *book, char *title)
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
		if (run && compare(run->title, title) == 0)
		{
			write(1, EXISTS, ft_strlen(EXISTS));
			return (1);
		}
		else
			where_to_insert(run, previous, book);
	}
	return (0);
}

void	add_book(char *title, char *author, int year)
{
	t_book	*book;

	if (title && author)
	{
		book = insert_book_info(title, author, year);
		if (book)
		{
			if (add_node_to_list(book, title))
				free_list_node(book);
		}
		else
		{	
			write(2, ERR, ft_strlen(ERR));
			free_info(title, author);
		}
	}
}
