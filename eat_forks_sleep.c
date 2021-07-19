#include "philo.h"

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->print);
	printf("%llu ms %d is thinking\n", get_time_now(p->start), p->index);
	pthread_mutex_unlock(p->print);

	pthread_mutex_lock(p->forks[0]);
	pthread_mutex_lock(p->print);
	printf("%llu ms %d has taken a fork\n", get_time_now(p->start), p->index);
	pthread_mutex_unlock(p->print);

	pthread_mutex_lock(p->forks[1]);
	pthread_mutex_lock(p->print);
	printf("%llu ms %d has taken a fork\n", get_time_now(p->start), p->index);
	pthread_mutex_unlock(p->print);

	p->t_last_eat = get_time_now(0);
}

void	eat(t_philo *p)
{
	pthread_mutex_lock(p->print);
	printf("%llu ms %d is eating\n", get_time_now(p->start), p->index);
	pthread_mutex_unlock(p->print);

	sleep_time(p->t_eat);
}

void	put_forks_and_sleep(t_philo *p)
{
	pthread_mutex_unlock(p->forks[0]);
	pthread_mutex_unlock(p->forks[1]);

	pthread_mutex_lock(p->print);
	printf("%llums %d is sleeping\n", get_time_now(p->start), p->index);
	pthread_mutex_unlock(p->print);

	sleep_time(p->t_sleep);

	// if (p_s->count_eat != -1)
	// 	p_s->count_eat -= 1;
	// if (p_s->count_eat == 0)
	// {
	// 	p_s->state = -1;
	// 	return ;
	// }
}
