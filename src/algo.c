/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:24:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/02 15:24:21 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_all_lig(t_env *e)
{
	t_obj	*tmp;

	e->test = 1;
	tmp = e->m_obj;
	e->lig->lum.dx = e->cam->dx * e->m_t + e->cam_ligx;
	e->lig->lum.dy = e->cam->dy * e->m_t + e->cam_ligy;
	e->lig->lum.dz = e->cam->dz * e->m_t + e->cam_ligz;
	ft_norm(&e->lig->lum.dx, &e->lig->lum.dy, &e->lig->lum.dz);
	ft_all_obj(e, &e->lig->lum);
	if (tmp != e->m_obj)
		e->test = 0.1;
}

void	ft_algo(t_env *e)
{
	int	x;
	int	y;

	ft_matrix(e, e->cam);
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
				ft_all_lig(e);
			ft_put_col(e, x, y);
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
	int red;
	int blue;

	if (e->m_t >= 1)
	{
		red = 255.0 * e->test/*- ((e->m_t * 100 - 100) * 4.2)*/;
		blue = 255.0 * e->test/*- ((e->m_t * 100 - 100) * 0.5)*/;
		if (e->m_obj->n == 's' || e->m_obj->n == 'c' || e->m_obj->n == 'y')
			ft_put_pixel(e, x, y, (red << 16) + (0 << 8) + 0);
		if (e->m_obj->n == 'p')
			ft_put_pixel(e, x, y, (0 << 16) + (0 << 8) + blue);
	}
	else
		ft_put_pixel(e, x, y, (0 << 16) + (0 << 8) + 0);
}
