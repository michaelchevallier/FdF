/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tracer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:23:18 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/23 17:44:10 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		hor_line_tracer(t_param *event, t_coord *coord)
{
	int		i;
	int		len;

	i = 0;
	len = coord->x1 - coord->x0;
	while (i != len)
	{
		mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0 + i, coord->y0, 0x00FF00);
		if (len >= 0)
			i++;
		else
			i--;
	}
}

void		vert_line_tracer(t_param *event, t_coord *coord)
{
	int		i;
	int		len;

	i = 0;
	len = coord->y1 - coord->y0;
	while (i != len)
	{
		mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0, coord->y0 + i, 0x00FF00);
		if (len >= 0)
			i++;
		else
			i--;
	}
}

float	absolute(float nb)
{
	if (nb < 0)
		nb = -nb;
	return(nb);
}
void		diag_line_tracer(t_param *event, t_coord *coord)
{
	float				k;
	float			len_x;
	float			len_y;
	float			coeff;
	float			n;

	len_x = coord->x1 - coord->x0;
	len_y = coord->y1 - coord->y0;
	coeff = 0;
	k = 0;
	n = 0;
	if (len_x == 0)
	{
		vert_line_tracer(event, coord);
		return ;
	}
	else if (len_y == 0)
	{
		hor_line_tracer(event, coord);
		return ;
	}
	coeff = len_y / len_x;
	if (absolute(coeff) >= 1)
	{
		while (absolute(k) != absolute(len_x))
		{
			mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0 + k + 1, coord->y0 - n, 0xFF0000);
			if (len_y < 0 )
				n++;
			else
				n--;
			if (absolute(n / (absolute(k) + 1)) > absolute(coeff))
			{
				if (len_x < 0)
					k--;
				else
					k++;
			}
		}
		k = 0;
	}
	else if (absolute(coeff) < 1 && absolute(coeff) > 0)
	{
		while (len_y != k)
		{
			mlx_pixel_put(event->mlx_ptr, event->mlx_win, coord->x0 + n, coord->y0 + k , 0xFFFFFF);
			if (len_y < 0)
				n++;
			else
				n--;
			if (absolute(n / (absolute(k) + 1)) >= absolute(1 / coeff))
			{
				if (len_x < 0)
					k++;
				else
					k--;
			}
		}
	}
}
