/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:12 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/29 16:47:12 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void *ft_routine(void *arg)
{
    t_data *data;
    t_philo *philo;

    philo = (t_philo *)arg;
    data = ft_get_data();
    while (1)
    {
        ft_think(philo, data);
        if (data->meal_count != -1 && philo->meals >= data->meal_count)
            break ;
        ft_sleep(philo, data);
    }
    return (NULL);
}