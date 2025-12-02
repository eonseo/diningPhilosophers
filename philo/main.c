/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:53:56 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 03:04:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	handle_single_philosopher(t_philo *philo)
{
	int	dead_id;

	think(philo);
	pthread_mutex_lock(&philo->mutex->fork[0]);
	print_time_and_state(philo, philo->id, TAKING_A_FORK, get_ms_time());
	dead_id = monitoring(philo);
	if (dead_id)
	{
		pthread_mutex_unlock(&philo->mutex->fork[0]);
		print_time_and_state(philo, philo->id, DIED, philo->table->dead_time);
		return ;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = allocate_and_set_philo(ac, av);
	if (!philo)
		return (1);
	philo->table->start_time = get_ms_time();
	if (philo->table->philo_count == 1)
	{
		handle_single_philosopher(philo);
		return (0);
	}
	run_thread(philo);
	free_values(philo);
	return (0);
}
