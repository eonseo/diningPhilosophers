/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:01:42 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/15 19:52:13 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_and_set_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_values(t_philo *philo)
{
	if (philo->mutex)
	{
		pthread_mutex_destroy(philo->mutex->fork);
		pthread_mutex_destroy(philo->mutex->eat_cnt);
		pthread_mutex_destroy(philo->mutex->last_ate);
		pthread_mutex_destroy(&philo->mutex->print);
		pthread_mutex_destroy(&philo->mutex->stop);
		free_and_set_null((void *)(philo->mutex->eat_cnt));
		free_and_set_null((void *)(philo->mutex->fork));
		free_and_set_null((void *)(philo->mutex->last_ate));
		free_and_set_null((void *)philo->mutex);
	}
	if (philo->table)
		free_and_set_null((void *)(philo->table));
	if (philo)
		free_and_set_null((void *)philo);
}
