/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:55 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/10/24 18:36:57 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_fork(t_table *table, int pos_r, int pos_l)
{
	if (table->num_philo > 1)
	{
		if (table->fork[pos_r].free && table->fork[pos_l].free)
		{
			table->fork[pos_r].free = 0;
			table->fork[pos_l].free = 0;
			pthread_mutex_lock(&table->fork[pos_r].mutex_fork);
			pthread_mutex_lock(&table->fork[pos_l].mutex_fork);
			pthread_mutex_lock(&table->mutex_write);
			print_state(table, pos_r, "has taken a fork");
			print_state(table, pos_r, "has taken a fork");
			pthread_mutex_unlock(&table->mutex_write);
			return (1);
		}
		return (0);
	}
	else
	{
		if (table->fork[pos_r].free)
		{
			table->fork[pos_r].free = 0;
			print_state(table, pos_r, "has taken a fork");
		}
		return (0);
	}
}

void	full_indigestion(t_table *table)
{
	int		i;
	int		indigestion;

	indigestion = 1;
	i = 0;
	while (i < table->num_philo)
	{
		if (table->philo[i].meals < table->meals)
		{
			indigestion = 0;
			break ;
		}
		i++;
	}
	if (indigestion && table->meals >= 0)
	{
		table->end = 0;
	}
}

int	eat_spaghetti(t_table *table, int pos)
{
	if (get_fork(table, table->philo[pos].pos_r, table->philo[pos].pos_l))
	{
		table->philo[pos].meals ++;
		return (1);
	}
	return (0);
}

void	finish_eating(t_table *table, int pos)
{
	table->fork[table->philo[pos].pos_r].free = 1;
	table->fork[table->philo[pos].pos_l].free = 1;
	pthread_mutex_unlock(&table->fork[table->philo[pos].pos_r].mutex_fork);
	pthread_mutex_unlock(&table->fork[table->philo[pos].pos_l].mutex_fork);
}
