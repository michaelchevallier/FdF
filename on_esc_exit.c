/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_esc_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:38:51 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/23 15:49:53 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		on_esc_exit(int keycode)//, void *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
