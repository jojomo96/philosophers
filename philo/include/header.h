/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:27:26 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/03 15:48:08 by jmoritz          ###   ########.fr       */
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
	pthread_mutex_t	lock;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	int				meal_count;
	int				dead;
	int				full;
	int				start;
	long			start_time;
	int				ready;
	pthread_mutex_t	ready_mutex;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
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
void				ft_usleep(useconds_t usec, t_philo *philo, t_data *data);
bool				ft_should_die(t_philo *philo, t_data *data);
bool				ft_is_dead(t_data *data);
void				ft_set_dead(t_data *data);

#endif
