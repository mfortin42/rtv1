/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:20:47 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/10 15:08:28 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int *tmp;

	if (y > WIN_Y || x > WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}
