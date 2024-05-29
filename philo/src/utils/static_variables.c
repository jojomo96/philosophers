/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojomo96 <jojomo96@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:03:04 by jojomo96          #+#    #+#             */
/*   Updated: 2024/05/29 10:00:02 by jojomo96         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data	*ft_get_data(void)
{
	static t_data	*data;

	if (!data)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (NULL);
	}
	return (data);
}
