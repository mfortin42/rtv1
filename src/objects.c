/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:17:46 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 13:18:43 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_sphere(t_env *e, t_ray *r)
{
	e->a = r->dx * r->dx + r->dy * r->dy + r->dz * r->dz;
	e->b = 2 * (r->dx * e->ex + r->dy * e->ey + r->dz * e->ez);
	e->c = (e->ex * e->ex + e->ey * e->ey + e->ez * e->ez)
			- e->bg->sz * e->bg->sz;
	e->dis = e->b * e->b - 4 * e->a * e->c;
	if (e->dis > 0)
	{
		e->t = ((-e->b + sqrt(e->dis)) / (2 * e->a) <=
				(-e->b - sqrt(e->dis)) / (2 * e->a) ?
				(-e->b + sqrt(e->dis)) / (2 * e->a) :
				(-e->b - sqrt(e->dis)) / (2 * e->a));
	}
}

void	ft_cone(t_env *e, t_ray *r)
{
	e->a = e->bg->szcos * ((r->dx * r->dx + r->dy * r->dy + r->dz * r->dz)
		- e->ea * e->ea) - e->bg->szsin * e->ea * e->ea;
	e->b = 2 * (e->bg->szcos * ((r->dx * e->ex + r->dy * e->ey + r->dz * e->ez)
		- (e->bg->dx * e->ex + e->bg->dy * e->ey + e->bg->dz * e->ez) * e->ea))
		- 2 * (e->bg->szsin * e->ea
		* (e->ex * e->bg->dx + e->ey * e->bg->dy + e->ez * e->bg->dz));
	e->c = e->bg->szcos * (e->ex * e->ex + e->ey * e->ey + e->ez * e->ez
		- (e->ex * e->bg->dx + e->ey * e->bg->dy + e->ez * e->bg->dz)
		* (e->ex * e->bg->dx + e->ey * e->bg->dy + e->ez * e->bg->dz))
		- e->bg->szsin
		* ((e->ex * e->bg->dx + e->ey * e->bg->dy + e->ez * e->bg->dz)
		* (e->ex * e->bg->dx + e->ey * e->bg->dy + e->ez * e->bg->dz));
	e->dis = e->b * e->b - 4 * e->a * e->c;
	if (e->dis > 0)
	{
		e->t = ((-e->b + sqrt(e->dis)) / (2 * e->a) <=
				(-e->b - sqrt(e->dis)) / (2 * e->a) ?
				(-e->b + sqrt(e->dis)) / (2 * e->a) :
				(-e->b - sqrt(e->dis)) / (2 * e->a));
	}
}

void	ft_plan(t_env *e)
{
	e->a = -(e->bg->dx * e->bg->ox + e->bg->dy
		* e->bg->oy + e->bg->dz * e->bg->oz);
	e->c = -(e->bg->dx * e->ex + e->bg->dy * e->ey + e->bg->dz * e->ez) / e->ea;
	if (e->ea != 0)
		e->t = e->c;
}

void	ft_cylindre(t_env *e, t_ray *r)
{
	e->a = (r->dx * r->dx + r->dy * r->dy + r->dz * r->dz)
		- ((r->dx * e->bg->dx + r->dy * e->bg->dy + r->dz * e->bg->dz)
		* (r->dx * e->bg->dx + r->dy * e->bg->dy + r->dz * e->bg->dz));
	e->b = 2 * ((r->dx * e->ex + r->dy * e->ey + r->dz * e->ez)
		- (e->bg->dx * e->ex + e->bg->dy * e->ey + e->bg->dz * e->ez)
		* (e->bg->dx * r->dx + e->bg->dy * r->dy + e->bg->dz * r->dz));
	e->c = (e->ex * e->ex + e->ey * e->ey + e->ez * e->ez)
		- ((e->ex * e->bg->dx + e->ey * e->bg->dy + e->ez * e->bg->dz)
		* (e->ex * e->bg->dx + e->ey * e->bg->dy + e->ez * e->bg->dz))
		- e->bg->sz * e->bg->sz;
	e->dis = e->b * e->b - 4 * e->a * e->c;
	if (e->dis > 0)
	{
		e->t = ((-e->b + sqrt(e->dis)) / (2 * e->a) <=
				(-e->b - sqrt(e->dis)) / (2 * e->a) ?
				(-e->b + sqrt(e->dis)) / (2 * e->a) :
				(-e->b - sqrt(e->dis)) / (2 * e->a));
	}
}
