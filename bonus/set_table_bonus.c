/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:05:52 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/11/07 14:05:56 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void static	set_philo(t_table *table, int pos)
{
	table->philo.pos = pos;
	table->philo.name = pos + 1;
	table->philo.state = 1;
	table->philo.next_state = get_time_in_ms();
	table->philo.to_die = get_time_in_ms() + table->time_die;
}

void static	init_philo(t_table *table, int pos)
{
	printf("Philo: %d\n", pos);
	set_philo(table, pos);
	next_state(table);
	while (table->end)
	{
		usleep(500);
		check_state(table);
	}
	exit(0);
}

void	set_the_table(t_table *table)
{
	int		i;
	int		pairs;

	i = 0;
	pairs = table->num_philo / 2;
	printf("pairs = %d\n", pairs);
	table->pid = malloc(sizeof(int) * table->num_philo);
	sem_unlink("/forks");
	table->sem_philo = sem_open("/forks", O_CREAT, 0644, pairs);
	table->end = 1;
	table->time_think = time_to_think(table);
	table->time_start = get_time_in_ms();
	while (i < table->num_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] == 0)
			init_philo(table, i);
		i++;
	}
	pthread_create(&table->control, NULL, routine, table);
	//sem_unlink("/forks");
}

void	*routine(void *data)
{
	t_table		*table;
	int			i;

	i = 0;
	table = (t_table *)data;
	while (1)
	{
		while (i < table->num_philo)
		{
			if (table->pid[i] == 0)
			{
				printf("philo: %d", table->philo.name);
				//check philos
			}
		}
	}
	return (NULL);
}
