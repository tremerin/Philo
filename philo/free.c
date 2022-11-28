/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:22:05 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/11/02 18:22:08 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_table *table)
{
	int		i;

	i = 0;
	pthread_mutex_destroy(&table->mutex_philo);
	while (i < table->num_philo)
	{
		pthread_mutex_destroy(&table->fork[i].mutex_fork);
		i++;
	}
}
