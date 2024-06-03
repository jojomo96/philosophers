/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:12 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/03 16:06:04 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_dead_checker(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = ft_get_data();
	while (!ft_is_dead(data))
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->meals == data->meal_count)
		{
			pthread_mutex_unlock(&philo->lock);
			continue ;
		}
		if (ft_should_die(philo, data))
		{
			pthread_mutex_unlock(&philo->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->lock);
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
	pthread_mutex_init(&philo->lock, NULL);
	ft_wait_until_ready(data);
	if (philo->id % 2 == 0)
		usleep(100);
	philo->last_meal = data->start_time;
	pthread_create(&philo->dead_checker, NULL, ft_dead_checker, philo);
	while (!ft_is_dead(data))
	{
		ft_think(philo, data);
		pthread_mutex_lock(&philo->lock);
		if ((data->meal_count != -1 && philo->meals >= data->meal_count)
			|| ft_is_dead(data))
		{
			pthread_mutex_unlock(&philo->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->lock);
		ft_sleep(philo, data);
	}
	pthread_join(philo->dead_checker, NULL); // TODO:error
	return (NULL);
}
