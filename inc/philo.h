#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>


typedef struct					s_philo
{
	uint64_t			t_die;
	uint64_t			t_eat;
	uint64_t			t_last_eat;
	uint64_t			t_sleep;
	uint64_t			start;
	int					count_meals;
	int					index;
	int					odd;
	pthread_mutex_t		*forks[2];
	pthread_mutex_t		thread;
	pthread_mutex_t		*print;
}						t_philo;


typedef struct			s_table
{
	int					number_of_all;
	t_philo				*philos;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
}						t_table;

void	sleep_time(uint64_t time)
{
	uint64_t	start;

	start = get_time_now(0);
	while (get_time_now(0) - start < time)
		usleep(100);
}

uint64_t	get_time_now(uint64_t start)
{
	struct timeval	t;
	uint64_t		time;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - start;
	return (time);
}

int		baze_process(t_table *table);
int		check_if_die(t_philo *phi, t_table *table);
void	*func_for_thread(void *arg);
void	create_thread_func(t_table *table, int i);

#endif