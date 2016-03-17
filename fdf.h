/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:34:10 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/17 18:17:31 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define COLOR 0x00FFFF
# define MAP_SIZE 100000
# define MAP_W 1200
# define MAP_H 1200

typedef struct		s_param
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	***map;
	int		**intmap;
	int		*maplen;
	float	px;
	int		maxz;
	int		maxlen;
	char	*argv;
	int		ow;
	int		oh;
	int		cz;
}					t_param;

typedef struct		s_coord
{
	float		x0;
	float		y0;
	float		x1;
	float		y1;
	float		i;
	float		j;
	float		len_x;
	float		len_y;
	float		coeff;
}					t_coord;

int					keyhook(int keycode, t_param *event);
int					expose_hook(t_param *event);
int					mapsize(t_param *event);
float				absolute(float nb);
void				ft_maptoint(t_param *event);
void				horizontal_sweep(t_param *e);
void				vertical_sweep(t_param *e);
void				hor_line_tracer(t_param *event, t_coord *coord);
void				vert_line_tracer(t_param *event, t_coord *coord);
void				diag_line_tracer(t_param *event, t_coord *coord);
#endif
