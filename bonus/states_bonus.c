/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:58:24 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/11/16 18:58:47 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_state(t_table *table, char *str)
{
	time_t	time;

	time = time_elapsed(table);
	printf("%ld %d %s\n", time, table->philo.name, str);
}

void	next_state(t_table *table)
{
	if (table->philo.state != 3)
	{
		if (table->philo.state == 4)
		{
			finish_eating(table);
			print_state(table, "is sleeping");
			table->philo.state = 1;
			table->philo.next_state = get_time_in_ms() + table->time_sleep;
		}
		else
		{
			table->philo.state++;
			if (table->philo.state == 2)
			{
				print_state(table, "is thinking");
				table->philo.next_state = get_time_in_ms() + table->time_think;
			}
		}
	}
}

void	check_state(t_table *table)
{
	time_t	time;

	time = get_time_in_ms();
	if (time >= table->philo.to_die)
	{
		print_state(table, "died");
		exit(DIED);
	}
	else if (table->philo.state == 3)
	{
		if (table->num_philo > 1)
		{
			sem_wait(table->sem_philo);
			eat_spaghetti(table);
		}
		else if (table->num_philo == 1 && !table->one_fork)
		{
			print_state(table, "has taken a fork");
			table->one_fork = 1;
		}	
	}
	else if (time >= table->philo.next_state)
		next_state(table);
}
