#include "../inc/philo.h"

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

uint64_t	get_time_now(uint64_t start)
{
	struct timeval	t;
	uint64_t		time;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - start;
	return (time);
}

void	sleep_time(uint64_t time)
{
	uint64_t	start;

	start = get_time_now(0);
	while (get_time_now(0) - start < time)
		usleep(200);
}