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
/*
void static	init_philo(t_table *table)
{

}
*/
void static	set_philo(t_table *table, int pos)
{
	table->end++;

	sem_wait(table->sem_philo);
	printf("philo: %d\n", pos);
	sem_post(table->sem_philo);
	exit(0);
}

void	set_the_table(t_table *table)
{
	int		i;
	int		pairs;

	i = 0;
	pairs = table->num_philo / 2;
	printf("pairs = %d\n", pairs);
	table->philo = ft_calloc(table->num_philo, sizeof(t_philo));
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
			set_philo(table, i);
		i++;
	}
	//sem_unlink("/forks");
}
