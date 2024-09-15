#include "Info_Book.h"

char	check_year_length(char *year)
{
	int	digits_number;

	digits_number = ft_strlen(year);
	if (digits_number == 4)
		return (0);
	return (1);
}

char	check_year_digits(char *year)
{
	while (*year)
	{
		if (*year < '0' || *year > '9')
			return (1);
		year++;
	}
	return (0);
}	 
