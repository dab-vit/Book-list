#include "structs.h"
#include <stdlib.h>

extern t_book	*g_root;

void	free_simple_pointer(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_info(char *title, char *author)
{
	free_simple_pointer(title);
	free_simple_pointer(author);
}

void	free_list_node(t_book *ptr)
{
	free_simple_pointer(ptr->title);
	free_simple_pointer(ptr->author);
	free(ptr);
}

void	free_list(void)
{
	t_book	*run;
	t_book	*previous;

	if (g_root)
	{
		run = g_root;
		previous = g_root;
		while (run)
		{
			previous = run;
			run = run->next;
			free_list_node(previous);
		}
		g_root = (void *) 0;
	}
}
