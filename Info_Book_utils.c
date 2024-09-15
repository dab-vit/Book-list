
#include "stdlib.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int	ascii_year_to_integer(const char *str)
{
	int	nbr;

	nbr = 0;
	while (*str)
		nbr = nbr * 10 + *str++ - '0';
	return (nbr);
}

char	*ft_strdup(const char *src)
{
	unsigned int	index;
	char			*dest;

	index = 0;
	while (src[index])
		index++;
	dest = (char *) malloc(sizeof(char) * (index + 1));
	if (dest == 0)
		return (0);
	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	compare(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
