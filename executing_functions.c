
#include "Info_Book.h"

extern t_book	*g_root;

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
	int	index;

	index = 1;
	if (g_root)
	{
		run = g_root;
		while (run)
		{
			printf("\nBook %i:\n", index++);
			printf("Title: %s\t Author: %s\t Year: %i\n", run->title, \
			run->author, run->year);
			run = run->next;
		}
	}
	else
		write(1, EMPTY, ft_strlen(EMPTY));
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
			printf("\nTitle: %s\t Author: %s\t Year: %i\n", run->title, \
			run->author, run->year);
		else
			write(1, NOT_FOUND, ft_strlen(NOT_FOUND));
	}
}
