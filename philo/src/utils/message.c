/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:22:54 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 08:55:08 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_message(t_data *data, t_philo *philo, char *message)
{
	pthread_mutex_lock(&data->print);
	printf("%lld %d %s\n", ft_get_time() - data->start_time, philo->id,
		message);
	pthread_mutex_unlock(&data->print);
}