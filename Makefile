# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 19:27:53 by fgalan-r          #+#    #+#              #
#    Updated: 2022/11/01 19:27:57 by fgalan-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo
NAME_BONUS  = philo_bonus
SRC_DIR     = ./mandatory/
SRC_FILES   = arg_validation.c \
			eat_spaghetti.c \
			ft_calloc.c \
			main.c \
			parse.c \
			routine.c \
			set_table.c \
			time.c \
			free.c

BONUS_DIR   = ./bonus/
BONUS_FILES = main_bonus.c \
			arg_validation_bonus.c \
			ft_calloc_bonus.c \
			parse_bonus.c \
			set_table_bonus.c \
			time_bonus.c \

SRC	        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS        = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))
BONUS_SRC   = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_OBJS  = $(addprefix $(BONUS_DIR), $(BONUS_FILES:.c=.o))
CC          = gcc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(NAME) $(NAME_BONUS)

re: fclean all
