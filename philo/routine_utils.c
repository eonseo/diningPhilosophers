/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 06:22:44 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/21 06:24:40 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	optimize_sleep(long start_time, int time_to_sleep)
{
	long	now_ms;

	usleep(time_to_sleep * 500);
	while (1)
	{
		usleep(100);
		now_ms = get_ms_time();
		if (now_ms >= start_time + time_to_sleep)
			break ;
	}
}
