/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:24:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/26 15:13:36 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_algo(t_env *e, t_ray *r)
{
	int	x;
	int	y;

	ft_matrix(e, r);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			r->dx = -WIN_X / 2 + x;
			r->dy = WIN_Y / 2 - y;
			ft_norm(r);
			ft_rot_vect(e, r);
			e->t = 0;
			e->m_t = 0;
			e->bg = e->obj;
			ft_all_obj(e);
			ft_put_col(e, x, y);
		}
	}
}

void	ft_all_obj(t_env *e)
{
	while (e->bg)
	{
		if (e->bg->n == 's')
			ft_sphere(e);
		if (e->bg->n == 'c')
			ft_cone(e);
		if (e->bg->n == 'y')
			ft_cylindre(e);
		if (e->bg->n == 'p')
			ft_plan(e);
		if ((e->m_t == 0 || e->t < e->m_t) && e->t >= 1)
		{
			e->m_t = e->t;
			e->m_name = e->bg->n;
		}
		e->bg = e->bg->next;
	}
}

void	ft_put_col(t_env *e, int x, int y)
{
	int red;
	int blue;

	if (e->m_t >= 1)
	{
		red = 255.0 - ((e->m_t * 100 - 100) * 4.2);
		blue = 255.0 - ((e->m_t * 100 - 100) * 0.5);
		if (e->m_name == 's' || e->m_name == 'c' || e->m_name == 'y')
			ft_put_pixel(e, x, y, (red << 16) + (0 << 8) + 0);
		if (e->m_name == 'p')
			ft_put_pixel(e, x, y, (0 << 16) + (0 << 8) + blue);
	}
	else
		ft_put_pixel(e, x, y, (0 << 16) + (0 << 8) + 0);
}
