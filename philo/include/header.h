/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:27:26 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/29 10:08:08 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals;
	int				last_meal;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_count;
	int				dead;
	int				full;
	int				start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}					t_data;

int					ft_init_data(t_data *data, int argc, char **argv);
t_data				*ft_get_data(void);
void				ft_free_data(t_data *data);

#endif