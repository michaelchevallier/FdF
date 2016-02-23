/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maptoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:12:23 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/18 13:55:10 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_maptoint(t_param *event)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (event->map[i])
	{
		event->intmap[i] = (int *)ft_memalloc(sizeof(int) * MAP_SIZE);
		while (event->map[i][j])
		{
			event->intmap[i][j] = ft_atoi(event->map[i][j]);
			j++;
		}
		event->maplen[i] = j;
		j = 0;
		i++;
	}
	event->intmap[i] = NULL;
}
