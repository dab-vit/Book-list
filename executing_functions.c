#include "Info_Book.h"

extern t_book	*g_root;
/*
void	add_node_to_list(t_book *book, char *title)
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
	}
}
*/	
void	remove_book(char *title)
{
	t_book  *run;
	t_book	*previous;

	if (g_root && title)
	{
		run = g_root;
		previous = g_root;
		while (run && compare(run->title, title))
		{
			previous = run;
			run = run->next;
		}
		if (run)
		{
			if (run == g_root && !run->next)
				g_root = (void *) 0;
			else if (run == g_root)
				g_root = run->next;
			else if (!run->next)
				previous->next = (void *) 0;
			else
				previous->next = run->next;	
			free_list_node(run);
		}
	}
}

void	list_books(void)
{
	t_book	*run;

	if (g_root)
	{
		run = g_root;
		while (run)
		{
			printf("Book: %s\t %s\t %i\n", run->title, run->author, run->year);
			run = run->next;
		}
	}
	else
		printf("Empty list\n");
}

void	search_book(char *title)
{
	t_book	*run;

	if (g_root && title)
	{
		run = g_root;
		while (run && compare(run->title, title))
			run = run->next;
		if (run)
			printf("Book: %s\t %s\t %i\n", run->title, run->author, run->year);
		else
			printf("Book not found in catalogue\n");
	}
}
