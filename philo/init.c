/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:03:21 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 03:02:39 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_with_argv(t_data *table, int ac, char **av)
{
	table->philo_count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->dead_time = 0;
	if (ac == 6)
		table->must_eat_count = ft_atoi(av[5]);
	else
		table->must_eat_count = INT_MAX;
	if (check_argument_error(table) == -1)
	{
		print_error_msg("argument error");
		return (-1);
	}
	return (0);
}

void	init_philo(t_philo *philo, t_data *table, t_mutex *mutex, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		philo[i].ate_count = 0;
		philo[i].id = i + 1;
		philo[i].last_eat = get_ms_time();
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % size;
		philo[i].table = table;
		philo[i].mutex = mutex;
		i++;
	}
}

void	init_mutex(t_mutex *mutex, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_init(&mutex->eat_cnt[i], NULL);
		pthread_mutex_init(&mutex->fork[i], NULL);
		pthread_mutex_init(&mutex->last_ate[i], NULL);
		i++;
	}
	pthread_mutex_init(&mutex->print, NULL);
	pthread_mutex_init(&mutex->stop, NULL);
}
