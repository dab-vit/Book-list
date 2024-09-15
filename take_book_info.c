
#include "Info_Book.h"

char	*get_data_info(char *data_type)
{
	char	buff[BUFFER + 1];
	char	*data;
	int	chars_read;
	
	write(1, data_type, ft_strlen(data_type));
	chars_read = read(0, buff, BUFFER);
	if (chars_read == -1)
		return ((void *) 0);
	else
	{
		buff[chars_read - 1] = '\0';
		data = ft_strdup(buff);
	}
	return (data);
}

static char	check_year(char *year)
{
	if (check_year_length(year))
		return (1);
	if (check_year_digits(year))
		return (1);
	return (0);
}

void	take_book_info(void)
{
	char	*title;
	char	*author;
	char	*year;
	int	year_int;

	title = get_data_info(TITLE);
	author = get_data_info(AUTHOR);	
	year = get_data_info(YEAR);
	while (year && check_year(year))
	{
		write(2, ERR_YEAR, ft_strlen(ERR_YEAR));
		free_simple_pointer(year);
		year = get_data_info(YEAR);
	}
	if (title && author && year)
	{
		year_int = ascii_year_to_integer(year);
		add_book(title, author, year_int);
	}
	else
	{	
		write(2, ERR, ft_strlen(ERR));
		free_info(title, author);	
	}
	free_simple_pointer(year);
}
