/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:47:26 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/25 18:33:43 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				horizontal_sweep(t_param *event)
{
	int		i;
	int		j;
	t_coord	*coord;

	i = -1;
	j = 0;
	coord = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (event->intmap[++i])
	{
		coord->x1 = OW + PX * (j - i);
		coord->y1 = OH + PX * (i - event->intmap[i][j] * (CZ) + j);
		coord->x0 = coord->x1;
		coord->y0 = coord->y1;
		while (j <= event->maplen[i])
		{
			coord->x1 = OW + PX * (j - i);
			coord->y1 = OH + PX * (i - event->intmap[i][j] * (CZ) + j);
			diag_line_tracer(event, coord, 0xFFFFFF - COLOR);
			coord->x0 = coord->x1;
			coord->y0 = coord->y1;
			j++;
		}
		j = 0;
	}
}

void				vertical_sweep(t_param *event)
{
	int		i;
	int		j;
	t_coord	*coord;

	i = 0;
	j = -1;
	coord = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (++j <= event->maplen[i])
	{
		coord->x1 = OW + PX * (j - i);
		coord->y1 = OH + PX * (i - event->intmap[i][j] * (CZ) + j);
		coord->x0 = coord->x1;
		coord->y0 = coord->y1;
		while (event->intmap[i])
		{
			coord->x1 = OW + PX * (j - i);
			coord->y1 = OH + PX * (i - event->intmap[i][j] * (CZ) + j);
			diag_line_tracer(event, coord, 0xFFFFFF - COLOR);
			coord->x0 = coord->x1;
			coord->y0 = coord->y1;
			i++;
		}
		i = 0;
	}
}
