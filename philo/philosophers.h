/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:28:06 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 06:23:44 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>

# define INT_MAX	2147483647

enum e_state
{
	THINKING = 1,
	SLEEPING,
	EATING,
	TAKING_A_FORK,
	DIED,
	ATE_ENOUGH,
};

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	int		stop_flag;
	long	start_time;
	long	dead_time;
	t_philo	**philos;
}	t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*eat_cnt;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*last_ate;
	pthread_mutex_t	print;
	pthread_mutex_t	stop;
}	t_mutex;

typedef struct s_philo
{
	int			ate_count;
	int			id;
	long		last_eat;
	int			left_fork;
	int			right_fork;
	pthread_t	tid;
	t_data		*table;
	t_mutex		*mutex;
}	t_philo;

// allocate.c
t_philo	*allocate_and_set_philo(int ac, char **av);
t_data	*allocate_and_set_table(int ac, char **av);
t_mutex	*allocate_and_set_mutex(int size);

// init.c
int		init_with_argv(t_data *table, int ac, char **av);
void	init_philo(t_philo *philo, t_data *table, t_mutex *mutex, int size);
void	init_mutex(t_mutex *mutex, int size);

// libft.c
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);

// main.c
void	handle_single_philosopher(t_philo *philo);

// data_error.c
int		check_argument_error(t_data *table);
int		check_data_error(t_philo *philo);

// monitoring_utils.c
void	turn_on_stop_flag(t_philo *philos);

// monitoring.c
int		has_eaten_enough(t_philo *philos);
int		is_dead(t_philo *philos, int *dead_id);
int		monitoring(t_philo *philos);

// free.c
void	free_and_set_null(void *ptr);
void	free_values(t_philo *philo);

// thread.c
void	run_thread(t_philo *philo);
void	create_thread(t_philo *philo);
void	join_thread(t_philo *philo);

// routine_utils.c
void	optimize_sleep(long start_time, int time_to_sleep);

// routine1.c
void	*routine(void *ptr);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	sleeping(t_philo *philo);

// routine2.c
void	pickup(t_philo *philo);
void	putdown(t_philo *philo);

// print.c
void	print_error_msg(char *msg);
void	print_time_and_state(t_philo *philo, int id, int state, long time);

// time.c
long	get_ms_time(void);

#endif