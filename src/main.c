/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:22:40 by jojomo96          #+#    #+#             */
/*   Updated: 2024/06/04 19:01:31 by jmoritz          ###   ########.fr       */
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
	ft_free_data(ft_get_data());
	return (0);
}
