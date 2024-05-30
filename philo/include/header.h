/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:27:26 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 11:22:57 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals;
	long long		last_meal;
	pthread_t		dead_checker;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	__useconds_t	time_to_die;
	__useconds_t	time_to_eat;
	__useconds_t	time_to_sleep;
	int				meal_count;
	int				dead;
	int				full;
	int				start;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}					t_data;

int					ft_init_data(t_data *data, int argc, char **argv);
t_data				*ft_get_data(void);
void				ft_free_data(t_data *data);
void				ft_sleep(t_philo *philo, t_data *data);
void				ft_think(t_philo *philo, t_data *data);
long long			ft_get_time(void);
long				ft_get_elapesed_time(long start_time);
void				*ft_routine(void *id);
void				ft_message(t_data *data, t_philo *philo, char *message);
void				ft_usleep(__useconds_t usec, t_philo *philo, t_data *data);
bool				ft_should_die(t_philo *philo, t_data *data);
#endif