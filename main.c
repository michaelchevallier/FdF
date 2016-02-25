/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:50:01 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/25 18:28:24 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ischar(char *line)
{
	int			i;

	i = 0;
	while (ft_isdigit(line[i]) != 0 || line[i] == ' ' || line[i] == '\0' ||
			line[i] == '-')
	{
		if (line[i] == '\0')
			return ;
		i++;
	}
	ft_error();
}

static t_param		*event_initializer(t_param *event)
{
	event = (t_param *)ft_memalloc(sizeof(t_param));
	event->map = (char ***)ft_memalloc(sizeof(char **) * MAP_SIZE + 1);
	event->intmap = (int **)ft_memalloc(sizeof(int *) * MAP_SIZE + 1);
	event->map[MAP_SIZE] = NULL;
	event->intmap[MAP_SIZE] = NULL;
	event->maplen = (int *)ft_memalloc(sizeof(int) * MAP_SIZE + 1);
	return (event);
}

static void			event_maker(t_param *event, char **argv)
{
	ft_maptoint(event);
	event->mlx_ptr = mlx_init();
	event->mlx_win = mlx_new_window(event->mlx_ptr, MAP_W, MAP_H, "F");
	horizontal_sweep(event);
	vertical_sweep(event);
	mlx_string_put(event->mlx_ptr, event->mlx_win, MAP_W / 2, 100, 0xFFFFFF,
			argv[1]);
	mlx_key_hook(event->mlx_win, on_esc_exit, 0);
	mlx_loop(event->mlx_ptr);
}

int					main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			i;
	t_param		*event;

	event = NULL;
	i = 0;
	if (argc == 2)
	{
		event = event_initializer(event);
		fd = clean_open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			ischar(line);
			event->map[i] = ft_strsplit(line, ' ');
			i++;
		}
		if (line)
		{
			ft_strdel(&line);
			event_maker(event, argv);
		}
	}
	return (0);
}
