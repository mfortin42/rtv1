/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:01:04 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 13:27:55 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_all_lig(t_env *e)
{
	t_obj	*o;
	double	m_t;

	e->shw = 1;
	o = e->m_obj;
	m_t = e->m_t;
	e->lig->lum.dx = e->cam->dx * e->m_t + e->cam_ligx;
	e->lig->lum.dy = e->cam->dy * e->m_t + e->cam_ligy;
	e->lig->lum.dz = e->cam->dz * e->m_t + e->cam_ligz;
	ft_norm(&e->lig->lum.dx, &e->lig->lum.dy, &e->lig->lum.dz);
	ft_all_obj(e, &e->lig->lum);
	if (o != e->m_obj)
		e->shw = 0.1;
	ft_normal(e, o, m_t);
	ft_angle(e, o);
}

void	ft_normal(t_env *e, t_obj *o, double m_t)
{
	if (o->n == 's' || o->n == 'p')
	{
		e->nx = o->n == 's' ? (e->cam->dx * m_t + e->cam->ox - o->ox) : o->dx;
		e->ny = o->n == 's' ? (e->cam->dy * m_t + e->cam->oy - o->oy) : o->dy;
		e->nz = o->n == 's' ? (e->cam->dz * m_t + e->cam->oz - o->oz) : o->dz;
	}
	else if (o->n == 'c' || o->n == 'y')
		ft_normal_c_y(e, o, m_t);
}

void	ft_normal_c_y(t_env *e, t_obj *o, double m_t)
{
	double	tmp;
	double	s;

	e->nx = e->cam->dx * m_t + e->cam->ox - o->ox;
	e->ny = e->cam->dy * m_t + e->cam->oy - o->oy;
	e->nx = e->cam->dz * m_t + e->cam->oz - o->oz;
	if (o->n == 'y')
	{
		tmp = e->nx * o->dx + e->ny * o->dy + e->nz * o->dz;
		e->nx = e->cam->dx * m_t + e->cam->ox - (o->ox + tmp * o->dx);
		e->ny = e->cam->dy * m_t + e->cam->oy - (o->oy + tmp * o->dy);
		e->nz = e->cam->dz * m_t + e->cam->oz - (o->oz + tmp * o->dz);
	}
	else if (o->n == 'c')
	{
		s = (e->cam->dx * m_t + e->cam->ox - o->ox) * o->dx
		+ (e->cam->dy * m_t + e->cam->oy - o->oy) * o->dy
		+ (e->cam->dz * m_t + e->cam->oz - o->oz) * o->dz;
		s = s > 0 ? 1 : -1;
		tmp = sqrt(e->nx * e->nx + e->ny * e->ny + e->nz * e->nz) / cos(o->sz);
		e->nx = e->cam->dx * m_t + e->cam->ox - (o->ox + tmp * o->dx * s);
		e->ny = e->cam->dy * m_t + e->cam->oy - (o->oy + tmp * o->dy * s);
		e->nz = e->cam->dz * m_t + e->cam->oz - (o->oz + tmp * o->dz * s);
	}
}

void	ft_angle(t_env *e, t_obj *o)
{
	double tmp;

	tmp = e->nx * e->lig->lum.dx + e->ny * e->lig->lum.dy
		+ e->nz * e->lig->lum.dz;
	tmp = tmp / sqrt(e->lig->lum.dx * e->lig->lum.dx + e->lig->lum.dy
		* e->lig->lum.dy + e->lig->lum.dz * e->lig->lum.dz);
	tmp = (tmp >= 0 && o->n != 'p') ? 0 : tmp;
	tmp = fabs(tmp / sqrt(e->nx * e->nx + e->ny * e->ny + e->nz * e->nz));
	tmp = (tmp < 0.000001) ? 0.000001 : tmp;
	e->r = tmp * o->r;
	e->g = tmp * o->g;
	e->bl = tmp * o->b;
}
