/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:22:54 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/04 18:36:51 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_message(t_data *data, t_philo *philo, char *message)
{
	pthread_mutex_lock(&data->print);
	if (ft_is_dead(data))
	{
		pthread_mutex_unlock(&data->print);
		return ;
	}
	printf("%lld %d %s\n", ft_get_time() - data->start_time, philo->id + 1,
		message);
	pthread_mutex_unlock(&data->print);
}
