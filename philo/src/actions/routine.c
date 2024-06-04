/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:12 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/04 19:01:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_check_philosopher_meals(t_data *data)
{
	pthread_mutex_lock(&data->full_mutex);
	if (data->full >= data->philo_count)
	{
		ft_set_dead(data);
		pthread_mutex_unlock(&data->full_mutex);
		return ;
	}
	pthread_mutex_unlock(&data->full_mutex);
}

void	ft_check_philosopher_status(t_data *data)
{
	int	i;

	while (true)
	{
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_lock(&data->philos[i].lock);
			if (ft_should_die(&data->philos[i], data))
			{
				pthread_mutex_unlock(&data->philos[i].lock);
				return ;
			}
			pthread_mutex_unlock(&data->philos[i].lock);
			i++;
		}
		ft_check_philosopher_meals(data);
		usleep(100);
	}
}

void	*ft_routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = ft_get_data();
	if (philo->id % 2 == 0)
		ft_usleep(data->time_to_eat / 2);
	while (!ft_is_dead(data))
	{
		ft_think(philo, data);
		ft_sleep(philo, data);
		usleep(100);
	}
	return (NULL);
}
