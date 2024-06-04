/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:33:40 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/04 18:37:08 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	ft_should_die(t_philo *philo, t_data *data)
{
	long long	current_time;
	long long	time_since_last_meal;

	current_time = ft_get_time();
	time_since_last_meal = current_time - philo->last_meal;
	if (time_since_last_meal > data->time_to_die)
	{
		if (!ft_is_dead(data))
		{
			ft_set_dead(data);
			pthread_mutex_lock(&data->print);
			printf("%lld %d died\n", current_time - data->start_time,
				philo->id + 1);
			pthread_mutex_unlock(&data->print);
		}
		return (true);
	}
	return (false);
}

void	ft_usleep(useconds_t usec)
{
	long long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < usec)
	{
		usleep(100);
	}
}
