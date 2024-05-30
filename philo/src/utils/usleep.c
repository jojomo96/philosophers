/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:33:40 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 09:40:38 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_usleep(__useconds_t usec, __useconds_t time_to_die, t_philo *philo, t_data *data)
{
    long long start;

    start = ft_get_time();
    while ((ft_get_time() - start) < usec)
    {
        if ( time_to_die - ft_get_time() >= 0)
            {
                pthread_mutex_lock(&data->print);
                printf("%lld %d died\n", ft_get_time() - data->start_time, philo->id);
                data->dead = 1;
                pthread_mutex_unlock(&data->print);
                break ;
            }
        usleep(usec / 10);
    }
}
