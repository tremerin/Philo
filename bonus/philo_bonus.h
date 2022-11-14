/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:31:43 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/11/07 13:31:45 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define NC		"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[36m"

typedef struct s_philo
{
	int			pos;
	int			name;
	time_t		next_state;
	time_t		to_die;
	int			state;
	int			meals;
}	t_philo;

typedef struct s_table
{
	t_philo		*philo;
	time_t		time_start;
	pid_t		*pid;
	int			num_philo;
	int			meals;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			time_think;
	int			end;
	sem_t		sem_philo;
}	t_table;

void	set_the_table(t_table *table);
int		argument_validation(t_table *table, int argc, char **argv);
int		ft_atoi(const char *str);
int		is_number(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
time_t	get_time_in_ms(void);
int		time_to_think(t_table *table);
time_t	time_elapsed(t_table *table);

#endif
