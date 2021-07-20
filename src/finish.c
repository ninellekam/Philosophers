#include "../inc/philo.h"

void	finish(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_all) {
        pthread_detach((void*)(&(table->philos[i].thread)));
        ++i;
    }
    i = 0;
    while (i < table->number_of_all)
    {
        pthread_mutex_destroy(&table->forks[i]);
        ++i;
    }
    free(table->philos);
    free(table->forks);
}