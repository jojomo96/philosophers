/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:52:20 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/04 15:48:27 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sleep(t_philo *philo, t_data *data)
{
	ft_message(data, philo, "is sleeping");
	ft_usleep(data->time_to_sleep);
}
