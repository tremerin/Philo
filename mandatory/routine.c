/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:00:28 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/10/18 19:00:30 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	next_state(t_table *table, int pos)
{
	if (table->philo[pos].state != 3)
	{
		if (table->philo[pos].state == 4)
		{
			finish_eating(table, pos);
			print_state(table, pos, "is sleeping");
			table->philo[pos].state = 1;
			table->philo[pos].next_state = get_time_in_ms() + table->time_sleep;
		}
		else
		{
			table->philo[pos].state++;
			if (table->philo[pos].state == 2)
			{
				print_state(table, pos, "is thinking");
				table->philo[pos].next_state = get_time_in_ms()
					+ table->time_think;
			}
		}
	}
}

static void	check_state(t_table *table, int pos)
{
	time_t		time;

	time = get_time_in_ms();
	if (time >= table->philo[pos].to_die)
	{
		print_state(table, pos, "died");
		table->philo[pos].state = 0;
		table->end = 0;
	}
	else if (table->philo[pos].state == 3)
	{
		if (eat_spaghetti(table, pos))
		{
			table->philo[pos].state = 4;
			table->philo[pos].to_die = get_time_in_ms() + table->time_die;
			table->philo[pos].next_state = get_time_in_ms() + table->time_eat;
			print_state(table, pos, "is eating");
			full_indigestion(table);
		}
	}
	else if (time >= table->philo[pos].next_state && table->end != 0)
		next_state(table, pos);
}

void	print_state(t_table *table, int pos, char *str)
{
	time_t	time;

	time = time_elapsed(table);
	printf("%ld %d %s\n", time, table->philo[pos].name, str);
}

void	*routine(void *data)
{
	t_table		*table;
	int			pos;

	table = (t_table *)data;
	pos = table->pos;
	table->pos++;
	if (pos % 2 == 0)
	{
		table->philo[pos].state = 2;
		print_state(table, pos, "is thinking");
	}
	else
		table->philo[pos].state = 1;
	pthread_mutex_unlock(&table->mutex_philo);
	table->philo[pos].next_state = get_time_in_ms();
	table->philo[pos].to_die = get_time_in_ms() + table->time_die;
	next_state(table, pos);
	while (table->end)
	{
		usleep(500);
		check_state(table, pos);
	}
	return (NULL);
}
