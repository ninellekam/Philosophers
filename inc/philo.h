#ifndef PHILO_H
#define PHILO_H
#pragma once
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

uint64_t	get_time_now(uint64_t start);
int			ft_atoi(const char *str);
int			ft_isdigit(char *av);
void		sleep_time(uint64_t time);
int			base_process(t_table *table);
int			check_if_die(t_philo *phi);
void		*func_for_thread(void *arg);
void		create_thread_func(t_table *table, int i);
void		take_forks(t_philo *p);
void		eat(t_philo *p);
void		put_forks_and_sleep(t_philo *p);
int			base_process(t_table *table);
void		create_thread_func(t_table *table, int i);
void		finish(t_table *table);

#endif