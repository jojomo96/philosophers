/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:52:13 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 08:26:43 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    ft_take_forks(t_philo *philo, t_data *data)
{
    pthread_mutex_lock(&data->forks[philo->left_fork]);
    ft_message(data, philo, "has taken a fork");
    pthread_mutex_lock(&data->forks[philo->right_fork]);
    ft_message(data, philo, "has taken a fork");
}

void    ft_droppting_forks(t_philo *philo, t_data *data)
{
    pthread_mutex_unlock(&data->forks[philo->right_fork]);
    pthread_mutex_unlock(&data->forks[philo->left_fork]);
}

void	ft_eat(t_philo *philo, t_data *data)
{
    ft_message(data, philo, "is eating");
	philo->last_meal = ft_get_time();
    philo->meals++;
	usleep(data->time_to_eat * 1000);
}

void    ft_think(t_philo *philo, t_data *data)
{
    ft_message(data, philo, "is thinking");
    ft_take_forks(philo, data);
    ft_eat(philo, data);
    ft_droppting_forks(philo, data); 
}