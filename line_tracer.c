/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tracer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:23:18 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/25 18:00:22 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		hor_line_tracer(t_param *event, t_coord *coord, int color)
{
	int		i;
	int		len;

	i = 0;
	len = coord->x1 - coord->x0;
	while (i != len)
	{
		mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0 + i, coord->y0,
				color);
		if (len >= 0)
			i++;
		else
			i--;
	}
}

void		vert_line_tracer(t_param *event, t_coord *coord, int color)
{
	int		i;
	int		len;

	i = 0;
	len = coord->y1 - coord->y0;
	while (i != len)
	{
		mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0, coord->y0 + i,
				color);
		if (len >= 0)
			i++;
		else
			i--;
	}
}

void		superior_diag_tracer(t_param *event, t_coord *coord, int color)
{
	while (absolute(coord->i) != absolute(coord->len_x))
	{
		mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0 + coord->i,
				coord->y0 - coord->j, color);
		if (coord->len_y < 0)
			coord->j++;
		else
			coord->j--;
		if (absolute(coord->j / (absolute(coord->i) + 1)) >
				absolute(coord->coeff))
		{
			if (coord->len_x < 0)
				coord->i--;
			else
				coord->i++;
		}
	}
	coord->i = 0;
}

void		minor_diag_tracer(t_param *event, t_coord *coord, int color)
{
	while (coord->len_y != coord->i)
	{
		mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0 + coord->j,
				coord->y0 + coord->i, color);
		if (coord->len_y < 0)
			coord->j++;
		else
			coord->j--;
		if (absolute(coord->j / (absolute(coord->i) + 1)) >=
				absolute(1 / coord->coeff))
		{
			if (coord->len_x < 0)
				coord->i++;
			else
				coord->i--;
		}
	}
}

void		diag_line_tracer(t_param *event, t_coord *coord, int color)
{
	coord->len_x = coord->x1 - coord->x0;
	coord->len_y = coord->y1 - coord->y0;
	coord->coeff = 0;
	coord->i = 0;
	coord->j = 0;
	if (coord->len_x == 0)
	{
		vert_line_tracer(event, coord, color);
		return ;
	}
	else if (coord->len_y == 0)
	{
		hor_line_tracer(event, coord, color);
		return ;
	}
	coord->coeff = coord->len_y / coord->len_x;
	if (absolute(coord->coeff) >= 1)
		superior_diag_tracer(event, coord, color);
	else if (absolute(coord->coeff) < 1 && absolute(coord->coeff) > 0)
		minor_diag_tracer(event, coord, color);
}
