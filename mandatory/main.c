/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:33:29 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/10/11 19:33:31 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if (argument_validation(&table, argc, argv))
	{
		set_the_table(&table);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	philo_join(&table);
	free_mutex(&table);
	return (0);
}

void	philo_join(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_join(table->philo[i].philo_thread, NULL);
		i++;
	}
}
