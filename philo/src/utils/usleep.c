/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:33:40 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/30 08:59:36 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_usleep(__useconds_t usec)
{
	long long start;

	start = ft_get_time();
	while ((ft_get_time() - start) < usec)
		usleep(usec / 10);
}