#include "../inc/philo.h"

void	init_philo(t_table *table, t_philo *philo, int i, char **av)
{
	philo->index = i + 1;
	if (philo->index % 2 == 0)
		philo->odd = 1;
	else
		philo->odd = 0;
    philo->t_die = ft_atoi(av[2]);
    philo->t_eat = ft_atoi(av[3]);
    philo->t_sleep = ft_atoi(av[4]);
    philo->t_last_eat = 0;
    philo->forks[0] = &table->forks[i];
    philo->forks[1] = &table->forks[(i + 1) % table->number_of_all];
	if (av[5])
		philo->count_meals = ft_atoi(av[5]);
	else 
        philo->count_meals = -1;
	philo->print = &table->print;
	philo->start = 0;
}

int	init(char **av, t_table *table)
{
	int	i;

    i = 0;
    table->number_of_all = ft_atoi(av[1]);
    table->philos = (t_philo *)malloc(sizeof(t_philo) * table->number_of_all);
    table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->number_of_all);

    while (i < table->number_of_all) {
        pthread_mutex_init(&table->forks[i], NULL);
        ++i;
    }

    pthread_mutex_init(&table->print, NULL);

    i = 0;
    while (i < table->number_of_all) {
       init_philo(table, &table->philos[i], i, av);
        ++i;
    }

	return (0);
}


int	main(int ac, char **av)
{
	t_table     table;
    if (ac == 5 || ac == 6)
    {
        init(av, &table);
	    if (base_process(&table) == 1)
            finish(&table);
    }
	return (0);
}