
#include "Info_Book.h"

static void	select_option_mssg(void)
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
	char	c;
	char	flag;

	option = 0;
	flag = 0;
	while ((option < 1 || option > 5) && flag != 1)
	{
		printf("\n");
		select_option_mssg();
		scanf("%i", &option);
		c = getc(stdin);
		if (c == EOF || c == '\n')
			flag = 1;
	}
	return (option);
}
