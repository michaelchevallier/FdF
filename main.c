/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:50:01 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/17 18:18:42 by mchevall         ###   ########.fr       */
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

static t_param		*event_initializer(t_param *event, char **argv)
{
	event = (t_param *)ft_memalloc(sizeof(t_param));
	event->map = (char ***)ft_memalloc(sizeof(char **) * MAP_SIZE + 1);
	event->intmap = (int **)ft_memalloc(sizeof(int *) * MAP_SIZE + 1);
	event->map[MAP_SIZE] = NULL;
	event->intmap[MAP_SIZE] = NULL;
	event->maplen = (int *)ft_memalloc(sizeof(int) * MAP_SIZE + 1);
	event->argv = argv[1];
	event->px = 1;
	event->maxz = 1;
	event->maxlen = 0;
	event->oh = 200;
	event->ow = 200;
	event->cz = 1;
	return (event);
}

static void			event_maker(t_param *event)
{
	int			i;

	i = 0;
	ft_maptoint(event);
	while (event->maplen[i++] != -1)
		((event->maxlen < event->maplen[i]) ?
		event->maxlen = event->maplen[i] : 0);
	event->px = ((MAP_W) / event->maxlen + (MAP_H) / (i)) / event->maxz;
	if (event->px > 50)
		event->px = 15;
	event->oh = (MAP_H) / 2 - (i / 2) * event->px;
	event->ow = (MAP_W) / 2 - (event->maxz / 2) * event->px;
	event->mlx_ptr = mlx_init();
	event->mlx_win = mlx_new_window(event->mlx_ptr, MAP_W, MAP_H, "F");
	mlx_key_hook(event->mlx_win, keyhook, event);
	mlx_expose_hook(event->mlx_win, expose_hook, event);
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
		event = event_initializer(event, argv);
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
			event_maker(event);
		}
	}
	return (0);
}
