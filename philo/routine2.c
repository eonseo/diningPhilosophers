/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:44 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 02:51:14 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pickup(t_philo *philo)
{
	if (philo->id & 1)
	{
		usleep(100);
		pthread_mutex_lock(&philo->mutex->fork[philo->right_fork]);
		print_time_and_state(philo, philo->id, TAKING_A_FORK, get_ms_time());
		pthread_mutex_lock(&philo->mutex->fork[philo->left_fork]);
		print_time_and_state(philo, philo->id, TAKING_A_FORK, get_ms_time());
	}
	else
	{
		usleep(200);
		pthread_mutex_lock(&philo->mutex->fork[philo->left_fork]);
		print_time_and_state(philo, philo->id, TAKING_A_FORK, get_ms_time());
		pthread_mutex_lock(&philo->mutex->fork[philo->right_fork]);
		print_time_and_state(philo, philo->id, TAKING_A_FORK, get_ms_time());
	}
}

void	putdown(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutex->fork[philo->right_fork]);
}
