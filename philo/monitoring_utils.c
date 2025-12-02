/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:39:42 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 06:23:15 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	turn_on_stop_flag(t_philo *philos)
{
	pthread_mutex_lock(&philos->mutex->stop);
	philos->table->stop_flag = 1;
	pthread_mutex_unlock(&philos->mutex->stop);
}
