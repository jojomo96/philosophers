/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:52:20 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 08:29:50 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sleep(t_philo *philo, t_data *data)
{
    ft_print_status(philo, "is sleeping");
    usleep(data->time_to_sleep * 1000);
}