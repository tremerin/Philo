/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:34:23 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/10/11 19:34:26 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483647

# define NC		"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[36m"

typedef struct s_fork
{
	pthread_mutex_t	mutex_fork;
	int				pos;
	int				free;
}	t_fork;

/* Varialbles de t_philo:
> state: el estado del filosofo:
	0 = muerto;
	1 = dormido;
	2 = pensando;
	3 = hambriento;
	4 = comiendo;
> pos: posición del filosofo en la mesa de 0 a N
> pos_left_fork: posición de su tenedor izquierdo
> pos_right_fork: posición de su tenedor derecho
*/
typedef struct s_philo
{
	pthread_t	philo_thread;
	time_t		next_state;
	time_t		to_die;
	int			pos;
	int			name;
	int			pos_l;
	int			pos_r;
	int			state;
	int			meals;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	mutex_philo;
	pthread_mutex_t	mutex_write;
	t_philo			*philo;
	t_fork			*fork;
	time_t			time_start;
	int				num_philo;
	int				meals;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				pos;
	int				end;
}	t_table;

int		argument_validation(t_table *table, int argc, char **argv);
int		ft_atoi(const char *str);
int		is_number(char *str);
void	set_the_table(t_table *table);
void	set_philo(t_table *table);
void	set_fork(t_table *table);
void	philo_join(t_table *table);
void	*routine(void *data);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
int		eat_spaghetti(t_table *table, int pos);
void	finish_eating(t_table *table, int pos);
int		time_to_think(t_table *table);
time_t	get_time_in_ms(void);
time_t	time_elapsed(t_table *table);
void	print_state(t_table *table, int pos, char *str);
void	full_indigestion(t_table *table);
void	free_mutex(t_table *table);
long	ft_atoli(const char *str);

#endif
