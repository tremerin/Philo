/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:44:29 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/10/12 17:44:31 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Tiempo en milisegundos */
time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	time_to_think(t_table *table)
{
	int	time;

	if ((table->time_sleep + table->time_eat) >= table->time_die)
		time = 0;
	else
		time = (table->time_die - (table->time_eat + table->time_sleep)) / 2;
	return (time);
}

time_t	time_elapsed(t_table *table)
{
	time_t	elapsed;

	elapsed = get_time_in_ms() - table->time_start;
	return (elapsed);
}
