/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:00:00 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 03:05:01 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	run_thread(t_philo *philo)
{
	int	dead_id;

	create_thread(philo);
	dead_id = monitoring(philo);
	if (dead_id != 0)
	{
		if (dead_id > 0)
			print_time_and_state(philo, dead_id, DIED, philo->table->dead_time);
		join_thread(philo);
	}
}

void	create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->philo_count)
	{
		pthread_create(&philo[i].tid, NULL, routine, (void *)&philo[i]);
		i++;
	}
}

void	join_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->philo_count)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
}
