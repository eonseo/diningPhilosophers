/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:47:13 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/22 16:40:20 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		pickup(philo);
		eat(philo);
		putdown(philo);
		pthread_mutex_lock(&philo->mutex->stop);
		if (philo->table->stop_flag == 1)
		{
			pthread_mutex_unlock(&philo->mutex->stop);
			break ;
		}
		pthread_mutex_unlock(&philo->mutex->stop);
		sleeping(philo);
		think(philo);
	}
	return (NULL);
}

void	think(t_philo *philo)
{
	print_time_and_state(philo, philo->id, THINKING, get_ms_time());
}

void	eat(t_philo *philo)
{
	long	start_time;
	int		i;

	start_time = get_ms_time();
	i = philo->id - 1;
	pthread_mutex_lock(&philo->mutex->last_ate[i]);
	philo->last_eat = start_time;
	pthread_mutex_unlock(&philo->mutex->last_ate[i]);
	pthread_mutex_lock(&philo->mutex->eat_cnt[i]);
	philo->ate_count++;
	pthread_mutex_unlock(&philo->mutex->eat_cnt[i]);
	print_time_and_state(philo, philo->id, EATING, start_time);
	optimize_sleep(start_time, philo->table->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	long	start_time;

	start_time = get_ms_time();
	print_time_and_state(philo, philo->id, SLEEPING, start_time);
	optimize_sleep(start_time, philo->table->time_to_sleep);
}
