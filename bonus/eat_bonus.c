/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:32:08 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/11/16 19:32:11 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_spaghetti(t_table *table)
{
	table->philo.state = 4;
	table->philo.to_die = get_time_in_ms() + table->time_die;
	table->philo.next_state = get_time_in_ms() + table->time_eat;
	table->philo.meals++;
	print_state(table, "is eating");
}

void	finish_eating(t_table *table)
{
	sem_post(table->sem_philo);
}
