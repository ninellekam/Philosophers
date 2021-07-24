#include "../inc/philo.h"

int	check_if_die(t_philo *phi)
{
	if (get_time_now(0) - phi->t_last_eat >= phi->t_die
		&& phi->count_meals != 0)
	{
		pthread_mutex_lock(phi->print);
		printf("%llu ms %d died\n", get_time_now(phi->start), phi->index);
		return (0);
	}
	return (1);
}

void	*func_for_thread(void *arg)
{
	t_philo	*p_s;

	p_s = (t_philo *)arg;
	if (p_s->odd)
		sleep_time(p_s->t_eat * 0.9);
	while (1)
	{
		take_forks(p_s);
		eat(p_s);
		put_forks_and_sleep(p_s);
		if (!p_s->count_meals)
			break ;
		pthread_mutex_lock(p_s->print);
		printf("%llu ms %d is thinking\n", get_time_now(p_s->start), p_s->index);
		pthread_mutex_unlock(p_s->print);
	}
	return (NULL);
}

void	create_thread_func(t_table *table, int i)
{
	table->philos[i].start = get_time_now(0);
	table->philos[i].t_last_eat = get_time_now(0);
	pthread_create((void *)(&(table->philos[i].thread)), NULL,
		func_for_thread, (void *)(&table->philos[i]));
	pthread_detach((void *)(&(table->philos[i].thread)));
}

int	cnt_of_all_check(t_table *table, int cnt_of_all)
{
	if (cnt_of_all == table->number_of_all)
	{
		pthread_mutex_lock(&table->print);
		printf("%llu Finished eating\n", get_time_now(table->philos->start));
		return (0);
	}
	return (1);
}

int	base_process(t_table *table)
{
	int	i;
	int	cnt_of_all;

	i = -1;
	while (++i < table->number_of_all)
		create_thread_func(table, i);
	while (1)
	{
		i = -1;
		cnt_of_all = 0;
		while (++i < table->number_of_all)
		{
			if (check_if_die(&table->philos[i]) == 0)
			{
				destroy(table);
				return (0);
			}
			if (table->philos[i].count_meals == 0)
				++cnt_of_all;
		}
		if (!cnt_of_all_check(table, cnt_of_all))
			break ;
	}
	return (1);
}
