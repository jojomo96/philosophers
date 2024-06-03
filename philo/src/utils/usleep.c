/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:33:40 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/03 13:48:56 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	ft_should_die(t_philo *philo, t_data *data)
{
	long long	current_time;
	long long	time_since_last_meal;

	current_time = ft_get_time();
	time_since_last_meal = current_time - philo->last_meal;
	if (time_since_last_meal >= data->time_to_die
		&& philo->meals != data->meal_count)
	{
		pthread_mutex_lock(&data->print);
		if (!data->dead)
			printf("%lld %d died\n", current_time - data->start_time, philo->id);
		data->dead = 1;
		pthread_mutex_unlock(&data->print);
		return (true);
	}
	return (false);
}

void	ft_usleep(useconds_t usec, t_philo *philo, t_data *data)
{
	long long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < usec)
	{
		if (ft_should_die(philo, data))
			break ;
		usleep(usec / 10);
	}
}
