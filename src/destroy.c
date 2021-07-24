#include "../inc/philo.h"

void	destroy(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->print);
	while (i < table->number_of_all)
	{
		pthread_mutex_destroy(&table->forks[i]);
		++i;
	}
	free(table->philos);
	free(table->forks);
}
