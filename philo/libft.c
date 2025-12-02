/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:27:31 by eonoh             #+#    #+#             */
/*   Updated: 2024/12/11 01:26:21 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	num;
	int		len;

	sign = 1;
	num = 0;
	len = 10;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (len -- > 0 && (*nptr >= '0' && *nptr <= '9'))
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0' || num > INT_MAX)
		return (-1);
	return (sign * num);
}
