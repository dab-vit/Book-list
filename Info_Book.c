
#include "Info_Book.h"

t_book	*g_root = 0;

static void	option_2(void)
{
	char    *title;

	title = get_data_info(TITLE_1);
	if (title)
	{
		remove_book(title);
		free_simple_pointer(title);
	}
	else
		write(2, ERR, ft_strlen(ERR));
}

static void    option_4(void)
{
	char    *title;

	title = get_data_info(TITLE_1);
	if (title)
	{
		search_book(title);
		free_simple_pointer(title);
	}
	else
		write(2, ERR, ft_strlen(ERR));
}

static void	proceed(int option)
{
	if (option == 1)
		take_book_info();
	else if (option == 2)
		option_2();
	else if (option == 3)
		list_books();
	else if (option == 4)
		option_4();
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
