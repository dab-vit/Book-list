#include "Info_Book.h"

t_book	*g_root = 0;

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
			free(run);
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
		{
			printf("run->title %s\t title %s\n", run->title, title);
			printf("compare %i\n", compare(run->title, title));
			run = run->next;
		}
		if (run)
			printf("Book: %s\t %s\t %i\n", run->title, run->author, run->year);
		else
			printf("Book not found in catalogue\n");
	}
}

void	proceed(int option)
{
	char	*title;

	if (option == 1)
		take_book_info();
	else if (option == 2)
	{
		title = get_title();
		if (title)
		{
			remove_book(title);
			free(title);
		}
		else
			printf("Error. Try again.\n");
	}
	else if (option == 3)
		list_books();
	else if (option == 4)
	{
		title = get_title();
		if (title)
		{
			search_book(title);
			free(title);
		}
		else
			printf("Error. Try again.\n");
	}
}		

int	main(void)
{
	int	option;

	option = 0;
	while (option != 5)
	{
		option = choose_an_option();
		proceed(option);
	}
	free_list();
	return (0);
}
