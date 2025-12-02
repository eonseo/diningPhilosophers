/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 03:30:10 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/11 13:04:44 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_argument_error(t_data *table)
{
	if (table->philo_count <= 0 || table->time_to_die <= 0 || \
		table->time_to_eat <= 0 || table->time_to_sleep <= 0 || \
		table->must_eat_count <= 0)
		return (-1);
	return (0);
}

int	check_data_error(t_philo *philo)
{
	if (!(philo->table) || !(philo->mutex) || \
		check_argument_error(philo->table) == -1)
	{
		print_error_msg("error\n");
		free_values(philo);
		return (-1);
	}
	return (0);
}
