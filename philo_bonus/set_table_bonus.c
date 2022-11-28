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

static void	set_philo(t_table *table, int pos)
{
	table->philo.pos = pos;
	table->philo.name = pos + 1;
	table->philo.state = 1;
	table->philo.meals = 0;
	table->philo.next_state = get_time_in_ms();
	table->philo.to_die = get_time_in_ms() + table->time_die;
}

static void	init_philo(t_table *table, int pos)
{
	set_philo(table, pos);
	pthread_create(&table->philo.philo_thread, NULL, routine, table);
	next_state(table);
	while (1)
	{
		usleep(500);
		check_state(table);
	}
	exit(0);
}

void	set_the_table(t_table *table)
{
	int		i;

	i = 0;
	table->pairs = table->num_philo / 2;
	table->one_fork = 0;
	table->pid = malloc(sizeof(int) * table->num_philo);
	sem_unlink("/forks");
	sem_unlink("/write");
	table->sem_philo = sem_open("/forks", O_CREAT, 0644, table->pairs);
	table->sem_write = sem_open("/write", O_CREAT, 0644, 1);
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
}

void	close_processes(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_philo)
	{
		kill(table->pid[i], 9);
		i++;
	}
}

void	close_sem(t_table *table)
{
	sem_unlink("/forks");
	sem_close(table->sem_philo);
	sem_unlink("/write");
	sem_close(table->sem_write);
}
