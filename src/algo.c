/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:24:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 13:24:27 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_algo(t_env *e)
{
	int	x;
	int	y;

	ft_matrix(e);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			e->cam->dx = -WIN_X / 2 + x;
			e->cam->dy = WIN_Y / 2 - y;
			e->cam->dz = 3780;
			ft_norm(&e->cam->dx, &e->cam->dy, &e->cam->dz);
			ft_rot_vect(e, e->cam);
			ft_all_obj(e, e->cam);
			if (e->m_t != 0)
			{
				ft_all_lig(e);
				ft_put_col(e, x, y);
			}
		}
	}
}

void	ft_all_obj(t_env *e, t_ray *r)
{
	e->t = 0;
	e->m_t = 0;
	e->bg = e->obj;
	while (e->bg)
	{
		e->ex = r->ox - e->bg->ox;
		e->ey = r->oy - e->bg->oy;
		e->ez = r->oz - e->bg->oz;
		e->ea = r->dx * e->bg->dx + r->dy * e->bg->dy + r->dz * e->bg->dz;
		if (e->bg->n == 's')
			ft_sphere(e, r);
		else if (e->bg->n == 'c')
			ft_cone(e, r);
		else if (e->bg->n == 'y')
			ft_cylindre(e, r);
		else if (e->bg->n == 'p')
			ft_plan(e);
		if ((e->m_t == 0 || e->t < e->m_t) && e->t >= 1)
		{
			e->m_t = e->t;
			e->m_obj = e->bg;
		}
		e->bg = e->bg->next;
	}
}

void	ft_put_col(t_env *e, int x, int y)
{
	ft_put_pixel(e, x, y, ((int)(e->r * e->shw) << 16)
				+ ((int)(e->g * e->shw) << 8) + (int)(e->bl * e->shw));
}
