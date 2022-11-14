/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:01:26 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/10/18 19:01:28 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_table *table)
{
	table->pos = 0;
	pthread_mutex_init(&table->mutex_philo, NULL);
	while (table->pos < table->num_philo)
	{
		pthread_mutex_lock(&table->mutex_philo);
		if (table->pos < table->num_philo)
			pthread_create(&table->philo[table->pos].philo_thread,
				NULL, routine, table);
	}
}

void	set_philo(t_table *table)
{
	int		i;

	i = 0;
	table->pos = 0;
	while (i < table->num_philo)
	{
		table->philo[i].pos = i;
		table->philo[i].name = i + 1;
		if (i == 0)
			table->philo[i].pos_l = table->num_philo - 1;
		else
			table->philo[i].pos_l = i - 1;
		table->philo[i].pos_r = i;
		i++;
	}
	init_philo(table);
}

void	set_fork(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_init(&table->fork[i].mutex_fork, NULL);
		table->fork[i].free = 1;
		table->fork[i].pos = i;
		i++;
	}
}

void	set_the_table(t_table *table)
{
	table->philo = ft_calloc(table->num_philo, sizeof(t_philo));
	table->fork = ft_calloc(table->num_philo, sizeof(t_fork));
	table->end = 1;
	table->time_think = time_to_think(table);
	table->time_start = get_time_in_ms();
	set_fork(table);
	set_philo(table);
}
