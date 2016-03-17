/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maptoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:12:23 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/17 18:17:52 by mchevall         ###   ########.fr       */
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
			if (event->intmap[i][j] >= event->maxz)
				event->maxz = event->intmap[i][j];
			if (event->maxz == 0)
				event->maxz = 1;
			j++;
		}
		event->maplen[i] = j;
		j = 0;
		i++;
	}
	event->intmap[i] = NULL;
	event->maplen[i] = -1;
}
