/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:24:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/10 16:23:17 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_algo(t_env *e)
{
	e->y = 0;
	while (e->y < WIN_Y)
	{
		e->x = 0;
		while (e->x < WIN_X)
		{
			e->t = 0;
			e->m_t = 0;
			e->begin = e->obj;
			ft_all_obj(e);
			ft_put_col(e);
			e->x++;
		}
		e->y++;
	}
}

void	ft_all_obj(t_env *e)
{
	while (e->begin)
	{
		if (e->begin->name == 's')
			ft_sphere(e);
		if (e->begin->name == 'p')
			ft_plan(e);
		if ((e->m_t == 0 || e->t < e->m_t) && e->t >= 1)
		{
			e->m_t = e->t;
			e->m_name = e->begin->name;
		}
		e->begin = e->begin->next;
	}
}

void	ft_put_col(t_env *e)
{
	int red;
	int blue;

	if (e->m_t >= 1)
	{
		red = 255.0 - ((e->m_t * 100 - 100) * 4);
		blue = 255.0 - ((e->m_t * 100 - 100) * 0.5);
		if (e->m_name == 's')
			ft_put_pixel(e, e->x, e->y, (red << 16) + (0 << 8) + 0);
		if (e->m_name == 'p')
			ft_put_pixel(e, e->x, e->y, (0 << 16) + (0 << 8) + blue);
	}
	else
		ft_put_pixel(e, e->x, e->y, (0 << 16) + (0 << 8) + 0);
}
