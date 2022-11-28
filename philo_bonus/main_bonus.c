/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:30:53 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/11/07 13:30:57 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	wait_processes(t_table *table)
{
	int	state;
	int	exit;

	waitpid(0, &state, 0);
	exit = WEXITSTATUS(state);
	if (exit == 1)
		close_processes(table);
	close_sem(table);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argument_validation(&table, argc, argv))
	{
		set_the_table(&table);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	wait_processes(&table);
	free(table.pid);
	return (0);
}
