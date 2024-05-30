/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:22:40 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 11:44:34 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_data(t_data *data)
{
	printf("philo_count: %d\n", data->philo_count);
	printf("time_to_die: %d\n", data->time_to_die);
	printf("time_to_eat: %d\n", data->time_to_eat);
	printf("time_to_sleep: %d\n", data->time_to_sleep);
	printf("meal_count: %d\n", data->meal_count);
}

int	main(int argc, char **argv)
{
	ft_init_data(ft_get_data(), argc, argv);
	ft_print_data(ft_get_data());
	ft_free_data(ft_get_data());
	return (0);
}
