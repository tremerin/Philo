/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:56:22 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/11/07 13:56:24 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	number_of_arguments(int argc, char **argv)
{
	int		i;

	if (argc != 5 && argc != 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	argument_validation(t_table *table, int argc, char **argv)
{
	if (number_of_arguments(argc, argv))
	{
		table->num_philo = ft_atoi(argv[1]);
		table->time_die = ft_atoi(argv[2]);
		table->time_eat = ft_atoi(argv[3]);
		table->time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			table->meals = ft_atoi(argv[5]);
		else
			table->meals = -1;
	}
	else
	{
		return (0);
	}
	return (1);
}
