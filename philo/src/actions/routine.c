/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:12 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 11:36:54 by jojomo96         ###   ########.fr       */
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

void	*ft_routine(void *arg)
{
	t_data *data;
	t_philo *philo;

	philo = (t_philo *)arg;
	data = ft_get_data();
	// if (philo->id % 2)
	//     ft_usleep(100);
	philo->last_meal = data->start_time;
	pthread_create(&philo->dead_checker, NULL, ft_dead_checker, philo);
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