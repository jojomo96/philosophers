/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_and_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:52:13 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/03 16:05:18 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_take_forks(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	ft_message(data, philo, "has taken a fork");
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	ft_message(data, philo, "has taken a fork");
}

void	ft_droppting_forks(t_philo *philo, t_data *data)
{
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
}

void	ft_eat(t_philo *philo, t_data *data)
{
	ft_message(data, philo, "is eating");
	ft_usleep(data->time_to_eat, philo, data);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = ft_get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->lock);
}

void	ft_think(t_philo *philo, t_data *data)
{
	ft_message(data, philo, "is thinking");
	ft_take_forks(philo, data);
	ft_eat(philo, data);
	ft_droppting_forks(philo, data);
}
