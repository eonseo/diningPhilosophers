/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:04:34 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 02:44:27 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	print_time_and_state(t_philo *philo, int id, int state, long time)
{
	pthread_mutex_lock(&philo->mutex->stop);
	if (philo->table->stop_flag == 1 && state != DIED)
	{
		pthread_mutex_unlock(&philo->mutex->stop);
		return ;
	}
	pthread_mutex_unlock(&philo->mutex->stop);
	pthread_mutex_lock(&philo->mutex->print);
	printf("%ld %d ", (time - philo->table->start_time), id);
	if (state == THINKING)
		printf("is thinking\n");
	else if (state == SLEEPING)
		printf("is sleeping\n");
	else if (state == EATING)
		printf("is eating\n");
	else if (state == TAKING_A_FORK)
		printf("has taken a fork\n");
	else if (state == DIED)
		printf("died\n");
	pthread_mutex_unlock(&philo->mutex->print);
}
