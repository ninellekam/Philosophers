#include "philo.h"


int	ft_atoi(const char *str)
{
	long int	c;
	long int	sign;
	long int	number;

	c = 0;
	sign = 1;
	number = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n' || \
	str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
		c++;
	if (str[c] == '-')
		sign = -1;
	if (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
		number = number * 10 + str[c++] - '0';

	return ((int)number * sign);
}

int	ft_isdigit(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (av[i] < 48 || av[i] > 57)
			return (0);
	}
	return (1);
}