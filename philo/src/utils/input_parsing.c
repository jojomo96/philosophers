/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:01:04 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/03 15:48:28 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int	ft_parse_args(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal_count = ft_atoi(argv[5]);
	else
		data->meal_count = -1;
	// if (data->philo_count < 2 || data->time_to_die < 60
	//     || data->time_to_eat < 60 || data->time_to_sleep < 60
	//     || (argc == 6 && data->meal_count < 1))
	//     return (1);
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->philo_count;
		data->philos[i].meals = 0;
		data->philos[i].last_meal = 0;
		pthread_mutex_init(&data->forks[i], NULL);
		if (pthread_create(&data->philos[i].thread, NULL, (void *)ft_routine,
				&data->philos[i]))
			return (1); // TODO: error
		i++;
	}
	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(data->philos[i].thread, NULL); // TODO: error
		i++;
	}
	return (0);
}

int	ft_init_data(t_data *data, int argc, char **argv)
{
	if (ft_parse_args(data, argc, argv))
		return (1);
	data->dead = 0;
	data->full = 0;
	data->start = 0;
	data->ready = 0;
	data->start_time = ft_get_time();
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (free(data->philos), 1);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->ready_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	return (ft_init_philo(data));
}
