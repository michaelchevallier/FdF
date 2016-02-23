/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:34:10 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/23 17:54:05 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define MAP_SIZE 100000
# define MAP_W 1200
# define MAP_H 800
# define SCALE 10
# define CX 3
# define CY 3
# define CZ 0.1

typedef struct		s_param
{
	void	*mlx_ptr;
	void	*mlx_win;

	char	***map;
	int		**intmap;
	int		*maplen;
}					t_param;

typedef struct		s_coord
{
	float		x0;
	float		y0;
	float		x1;
	float		y1;
}					t_coord;

int					on_esc_exit(int keycode);
void				ft_maptoint(t_param *event);
void				horizontal_sweep(t_param *event);
void				vertical_sweep(t_param *event);
void				hor_line_tracer(t_param *event, t_coord *coord);
void				vert_line_tracer(t_param *event, t_coord *coord);
void				diag_line_tracer(t_param *event, t_coord *coord);
#endif
