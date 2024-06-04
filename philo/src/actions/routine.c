/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:12 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/04 16:56:12 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = ft_get_data();
	pthread_mutex_init(&philo->lock, NULL);
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
