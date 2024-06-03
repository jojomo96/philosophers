/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:29:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/06/03 14:34:42 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	ft_is_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead_mutex);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(&data->dead_mutex);
	return (false);
}

void	ft_set_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead_mutex);
	data->dead = 1;
	pthread_mutex_unlock(&data->dead_mutex);
}
