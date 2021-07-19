#include "philo.h"

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

    // errors
    //  Перед использованием необходимо инициализировать мьютекс функцией pthread_mutex_init

    while (i < table->number_of_all) {
        pthread_mutex_init(&table->forks[i], NULL);
        ++i;
    }

    pthread_mutex_init(&table->print, NULL);

    i = 0;
    while (i < table->number_of_all) {
       init_philo(&table, &table->philos[i], i, NULL);
        ++i;
    }

	return (0);
}

void	*simulation(void *arg)
{
	t_philo	*p_s;

	p_s = (t_philo *)arg;
	while (1)
	{
		take_forks(p_s);
		eat(p_s);
		put_forks_and_sleep(p_s);
	}
}

void	create_simulation(t_table *table, int i)
{
	table->philos[i].start = get_time_now(0);
	table->philos[i].t_last_eat = get_time_now(0);
	pthread_create(&table->philos[i].thread, NULL, simulation, &table->philos[i]);
}


int	check_if_die(t_philo *phi, t_table *table) {
	if (get_time_now(0) - phi->t_last_eat >= phi->t_die && phi->count_meals != 0)
	{
		pthread_mutex_lock(phi->print);
		printf("%llu ms %d died\n", get_time_now(phi->start), phi->index);
		return (0);
	}
}

int	start_simulation(t_table *table)
{
	int	i;

	i = -1;

	while (++i < table->number_of_all)
		create_simulation(table, i);

	while (1)
	{
		i = -1;
		int cnt_of_all = 0;
		t_philo *phi = &table->philos[i];
		while (++i < table->number_of_all) {
			check_if_die(phi, table);
			cnt_of_all += phi->count_meals == 0;
		}

		if (cnt_of_all == table->number_of_all) {
			break;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table     table;

    init(av, &table);
	// start_simulation(&table);
	finish(&table);
	// free 
	return (0);
}