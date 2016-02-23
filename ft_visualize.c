/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:47:26 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/23 17:37:52 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord		*hor_coord_initializer(t_coord *coord, t_param *event)
{
	coord = (t_coord *)ft_memalloc(sizeof(t_param));
	coord->x0 = MAP_W / 3;
	coord->y0 = MAP_H / 3 - event->intmap[0][0] * SCALE * CY *CZ;
	coord->x1 = MAP_W / 3 + SCALE * CX;
	coord->y1 = MAP_H / 3 - event->intmap[0][1] * SCALE * CY * CZ;
	return (coord);
}

static t_coord		*vert_coord_initializer(t_coord *coord, t_param *event)
{
	coord = (t_coord *)ft_memalloc(sizeof(t_param));
	coord->x0 = MAP_W / 3;
	coord->y0 = MAP_H / 3 - event->intmap[0][0] * SCALE * CY * CZ;
	coord->x1 = MAP_W / 3 - CX * SCALE;
	coord->y1 = MAP_H / 3 + CX * SCALE - event->intmap[1][0] * SCALE * CY * CZ;
	return (coord);
}

void				horizontal_sweep(t_param *event)
{
	int		i;
	int		j;
	t_coord	*coord;

	i = 0;
	j = 0;
	coord = NULL;
	coord = hor_coord_initializer(coord, event);
	while (event->intmap[i])
	{
		coord->x1 = MAP_W/3 + SCALE * CX * (j - i);
		coord->y1 = MAP_H/3 + SCALE * CY * (i - event->intmap[i][j] * CZ + i);
		coord->x0 = coord->x1;
		coord->y0 = coord->y1;
		while (j <= event->maplen[i])
		{
			coord->x1 = MAP_W/3 + SCALE * CX * (j - i);
			coord->y1 = MAP_H/3 + SCALE * CY * (i - event->intmap[i][j] * CZ + i);
			//mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0, coord->y0, 0x0000FF);
			/*printf("i : %d coord x0: %f coord y0: %f\nj : %d coord x1: %f coord y1: %f \n\n", i,coord->x0,coord->y0,j,coord->x1,coord->y1);*/
			diag_line_tracer(event, coord);
			coord->x0 = coord->x1;
			coord->y0 = coord->y1;
			j++;
		}
		j = 0;
		i++;
	}
}

void				vertical_sweep(t_param *event)
{
	int		i;
	int		j;
	t_coord	*coord;

	i = 0;
	j = 0;
	coord = NULL;
	coord = vert_coord_initializer(coord, event);
	while (j <= event->maplen[i])
	{
		coord->x1 = MAP_W/3 + SCALE * CX * (j - i);
		coord->y1 = MAP_H/3 + SCALE * CY * (i - event->intmap[i][j] * CZ + i);
		coord->x0 = coord->x1;
		coord->y0 = coord->y1;
		while (event->intmap[i])
		{
			coord->x1 = MAP_W/3 + SCALE * CX * (j - i);
			coord->y1 = MAP_H/3 + SCALE * CY * (i - event->intmap[i][j] * CZ + i);
			mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0, coord->y0, 0x0000FF);
			diag_line_tracer(event, coord);
			coord->x0 = coord->x1;
			coord->y0 = coord->y1;
			i++;
		}
		i = 0;
		j++;
	}
}
