/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 03:29:05 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/15 19:30:00 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*allocate_and_set_philo(int ac, char **av)
{
	t_philo	*philo;
	t_data	*table;
	t_mutex	*mutex;

	table = allocate_and_set_table(ac, av);
	if (!table)
		return (NULL);
	mutex = allocate_and_set_mutex(table->philo_count);
	if (!mutex)
		return (NULL);
	philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_count);
	if (!philo)
	{
		print_error_msg("allocate error");
		return (NULL);
	}
	table->philos = &philo;
	init_philo(philo, table, mutex, table->philo_count);
	return (philo);
}

t_data	*allocate_and_set_table(int ac, char **av)
{
	t_data	*table;

	if (!(ac == 5 || ac == 6))
	{
		print_error_msg("argument error");
		return (NULL);
	}
	table = (t_data *)malloc(sizeof(t_data));
	if (!table)
	{
		print_error_msg("allocate error");
		return (NULL);
	}
	if (init_with_argv(table, ac, av) == -1)
		return (NULL);
	table->stop_flag = 0;
	return (table);
}

t_mutex	*allocate_and_set_mutex(int size)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!mutex)
	{
		print_error_msg("allocate error");
		return (NULL);
	}
	mutex->eat_cnt = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	mutex->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	mutex->last_ate = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	if (!(mutex->eat_cnt) || !(mutex->fork) || !(mutex->last_ate))
	{
		print_error_msg("allocate error");
		return (NULL);
	}
	init_mutex(mutex, size);
	return (mutex);
}
