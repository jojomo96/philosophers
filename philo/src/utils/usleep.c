/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:33:40 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 11:37:36 by jojomo96         ###   ########.fr       */
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
		printf("%lld %d died\n", current_time - data->start_time, philo->id);
		data->dead = 1;
		pthread_mutex_unlock(&data->print);
		return (true);
	}
	return (false);
}

void	ft_usleep(__useconds_t usec, t_philo *philo, t_data *data)
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
