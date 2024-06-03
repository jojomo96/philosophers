/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:12 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/03 14:01:48 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_dead_checker(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = ft_get_data();
	while (!data->dead && philo->meals != data->meal_count)
	{
		if (ft_should_die(philo, data))
			break ;
	}
	return (NULL);
}

void	ft_wait_until_ready(t_data *data)
{
	pthread_mutex_lock(&data->ready_mutex);
	data->ready++;
	pthread_mutex_unlock(&data->ready_mutex);
	while (1)
	{
		pthread_mutex_lock(&data->ready_mutex);
		if (data->ready >= data->philo_count)
		{
			pthread_mutex_unlock(&data->ready_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->ready_mutex);
		usleep(1);
	}
}

void	*ft_routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = ft_get_data();
	// if (philo->id % 2)
	//     ft_usleep(100);
	pthread_create(&philo->dead_checker, NULL, ft_dead_checker, philo);
	ft_wait_until_ready(data);
	philo->last_meal = data->start_time;
	// TODO:error
	while (!data->dead)
	{
		ft_think(philo, data);
		if ((data->meal_count != -1 && philo->meals >= data->meal_count)
			|| data->dead)
			break ;
		ft_sleep(philo, data);
	}
	pthread_join(philo->dead_checker, NULL); // TODO:error
	return (NULL);
}
