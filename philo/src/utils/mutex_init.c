/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:08:10 by jmoritz           #+#    #+#             */
/*   Updated: 2024/06/04 19:18:15 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_mutex_init(void)
{
	t_data	*data;
	int		i;

	data = ft_get_data();
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->dead_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->full_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->ready_mutex, NULL) != 0)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (free(data->philos), 1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->philos[i].lock, NULL))
			return (1);
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
