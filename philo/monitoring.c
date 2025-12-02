/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:42:32 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/22 16:21:43 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	has_eaten_enough(t_philo *philos)
{
	int	i;
	int	diff;

	i = 0;
	while (i < philos->table->philo_count)
	{
		pthread_mutex_lock(&philos->mutex->eat_cnt[i]);
		diff = philos[i].ate_count - philos[i].table->must_eat_count;
		pthread_mutex_unlock(&philos->mutex->eat_cnt[i]);
		if (diff < 0)
			return (0);
		i++;
	}
	turn_on_stop_flag(philos);
	optimize_sleep(get_ms_time(), 1);
	return (1);
}

int	is_dead(t_philo *philos, int *dead_id)
{
	int	i;
	int	time_without_eating;

	i = 0;
	while (i < philos->table->philo_count)
	{
		pthread_mutex_lock(&philos->mutex->last_ate[i]);
		time_without_eating = get_ms_time() - philos[i].last_eat;
		pthread_mutex_unlock(&philos->mutex->last_ate[i]);
		if (time_without_eating >= philos->table->time_to_die)
		{
			philos->table->dead_time = get_ms_time();
			turn_on_stop_flag(philos);
			*dead_id = i + 1;
			optimize_sleep(get_ms_time(), 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	monitoring(t_philo *philos)
{
	int	dead_id;

	while (1)
	{
		if (has_eaten_enough(philos))
			return (-1);
		if (is_dead(philos, &dead_id))
			return (dead_id);
		usleep(10);
	}
	return (0);
}
