/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:17:46 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/28 16:17:30 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_sphere(t_env *e, t_ray *r)
{
	double	a;
	double	b;
	double	c;

	a = pow(r->dx, 2)
		+ pow(r->dy, 2)
		+ pow(r->dz, 2);
	b = 2 * (r->dx * (r->ox - e->bg->ox)
		+ r->dy * (r->oy - e->bg->oy)
		+ r->dz * (r->oz - e->bg->oz));
	c = (pow((r->ox - e->bg->ox), 2)
		+ pow((r->oy - e->bg->oy), 2)
		+ pow((r->oz - e->bg->oz), 2)) - pow(e->bg->sz, 2);
	e->dis = pow(b, 2) - 4 * a * c;
	if (e->dis > 0)
	{
		e->t = ((-b + sqrt(e->dis)) / (2 * a) <= (-b - sqrt(e->dis)) / (2 * a) ?
				(-b + sqrt(e->dis)) / (2 * a) : (-b - sqrt(e->dis)) / (2 * a));
	}
}

void	ft_cone(t_env *e, t_ray *r)
{
	double	a;
	double	b;
	double	c;

	double ex = r->ox - e->bg->ox;
	double ey = r->oy - e->bg->oy;
	double ez = r->oz - e->bg->oz;

	a = pow(cos(e->bg->sz), 2) * ((r->dx * r->dx + r->dy * r->dy + r->dz * r->dz)
		- pow(r->dx * e->bg->dx + r->dy * e->bg->dy + r->dz * e->bg->dz, 2)) -
		pow(sin(e->bg->sz), 2) * pow(e->bg->dx * r->dx + e->bg->dy * r->dy + e->bg->dz * r->dz, 2);
	b = 2 * (pow(cos(e->bg->sz), 2) * ((r->dx * ex + r->dy * ey + r->dz * ez)
		- (e->bg->dx * ex + e->bg->dy * ey + e->bg->dz * ez) * (e->bg->dx * r->dx +
		e->bg->dy * r->dy + e->bg->dz * r->dz))) - 2 * (pow(sin(e->bg->sz), 2) *
		(r->dx * e->bg->dx + r->dy * e->bg->dy + r->dz * e->bg->dz) * (ex * e->bg->dx
		+ ey * e->bg->dy + ez * e->bg->dz));
	c = pow(cos(e->bg->sz), 2) * (ex * ex + ey * ey + ez * ez - pow(ex * e->bg->dx
		+ ey * e->bg->dy + ez * e->bg->dz, 2)) - pow(sin(e->bg->sz), 2) *
		pow(ex * e->bg->dx + ey * e->bg->dy + ez * e->bg->dz, 2);
	e->dis = pow(b, 2) - 4 * a * c;
	if (e->dis > 0)
	{
		e->t = ((-b + sqrt(e->dis)) / (2 * a) <= (-b - sqrt(e->dis)) / (2 * a) ?
				(-b + sqrt(e->dis)) / (2 * a) : (-b - sqrt(e->dis)) / (2 * a));
	}
}

void	ft_plan(t_env *e, t_ray *r)
{
	double a;
	double b;
	double c;

	a = -((e->bg->dx * e->bg->ox) + (e->bg->dy * e->bg->oy) + (e->bg->dz * e->bg->oz));
	b = (e->bg->dx * r->dx) + (e->bg->dy * r->dy) + (e->bg->dz * r->dz);
	c = -(e->bg->dx * (r->ox - e->bg->ox) + e->bg->dy * (r->oy - e->bg->oy) +
			e->bg->dz * (r->oz - e->bg->oz)) / b;
	if (b != 0)
		e->t = c;
}

void	ft_cylindre(t_env *e, t_ray *r)
{
	double	a;
	double	b;
	double	c;

	double ex = r->ox - e->bg->ox;
	double ey = r->oy - e->bg->oy;
	double ez = r->oz - e->bg->oz;

	a = (r->dx * r->dx + r->dy * r->dy + r->dz * r->dz) - pow((r->dx * e->bg->dx)
		+ (r->dy * e->bg->dy) + (r->dz * e->bg->dz), 2);
	b = 2 * ((r->dx * ex + r->dy * ey + r->dz * ez) - (e->bg->dx * ex +
		e->bg->dy * ey + e->bg->dz * ez) * (e->bg->dx * r->dx + e->bg->dy
		* r->dy + e->bg->dz * r->dz));
	c = (pow(ex, 2) + pow(ey, 2) + pow(ez, 2)) - pow(ex * e->bg->dx + ey *
		e->bg->dy + ez * e->bg->dz, 2) - pow(e->bg->sz, 2);
	e->dis = pow(b, 2) - 4 * a * c;
	if (e->dis > 0)
	{
		e->t = ((-b + sqrt(e->dis)) / (2 * a) <= (-b - sqrt(e->dis)) / (2 * a) ?
				(-b + sqrt(e->dis)) / (2 * a) : (-b - sqrt(e->dis)) / (2 * a));
	}
}

