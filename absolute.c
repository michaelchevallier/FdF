/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:37:11 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/24 15:37:58 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		absolute(float nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}
