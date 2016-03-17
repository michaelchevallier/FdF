/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_esc_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:38:51 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/17 18:08:29 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_param *event)
{
	mlx_clear_window(event->mlx_ptr, event->mlx_win);
	mlx_string_put(event->mlx_ptr, event->mlx_win, MAP_W / 2, 10, 0xFFFFFF,
			event->argv);
	mlx_string_put(event->mlx_ptr, event->mlx_win, 50, MAP_H - 200, 0xFFFFFF,
			"- Altitude : /");
	mlx_string_put(event->mlx_ptr, event->mlx_win, 50, MAP_H - 175, 0xFFFFFF,
			"+ Altitude : *");
	mlx_string_put(event->mlx_ptr, event->mlx_win, 50, MAP_H - 150, 0xFFFFFF,
			"Quit : ESC");
	mlx_string_put(event->mlx_ptr, event->mlx_win, 50, MAP_H - 125, 0xFFFFFF,
			"Move : ARROWS");
	mlx_string_put(event->mlx_ptr, event->mlx_win, 50, MAP_H - 100, 0xFFFFFF,
			"Zoom : + / -");
	vertical_sweep(event);
	horizontal_sweep(event);
	return (0);
}

int		keyhook(int keycode, t_param *event)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 67)
		event->cz += 1;
	if (keycode == 75)
		event->cz -= 1;
	if (keycode == 69)
		event->px += 1;
	if (keycode == 78)
		event->px -= 1;
	if (keycode == 123)
		event->ow -= 1 * event->px;
	if (keycode == 124)
		event->ow += 1 * event->px;
	if (keycode == 125)
		event->oh += 1 * event->px;
	if (keycode == 126)
		event->oh -= 1 * event->px;
	expose_hook(event);
	return (0);
}
