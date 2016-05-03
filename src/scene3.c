/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:36:30 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 17:21:36 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_inis_3(t_env *e)
{
	if (!(e->cam = malloc(sizeof(t_ray))))
		ft_error("error : malloc failed");
	e->cam->ox = WIN_X / 2;
	e->cam->oy = WIN_Y / 2;
	e->cam->oz = -3780;
	e->cam->dx = -WIN_X / 2;
	e->cam->dy = WIN_Y / 2;
	e->cam->dz = 3780;
	e->agl = 0;
	e->cdx = 0;
	e->cdy = 0;
	e->cdz = 0;
	if (!(e->lig = malloc(sizeof(t_lig))))
		ft_error("error : malloc failed");
	e->lig->lum.ox = WIN_X / 2 - 2000;
	e->lig->lum.oy = WIN_Y / 2 + 2000;
	e->lig->lum.oz = -3780;
	e->cam_ligx = e->cam->ox - e->lig->lum.ox;
	e->cam_ligy = e->cam->oy - e->lig->lum.oy;
	e->cam_ligz = e->cam->oz - e->lig->lum.oz;
	ft_inis_3_1(e);
}

void	ft_inis_3_1(t_env *e)
{
	if (!(e->obj = malloc(sizeof(t_obj))))
		ft_error("error : malloc failed");
	e->obj->n = 'c';
	e->obj->ox = WIN_X / 2;
	e->obj->oy = WIN_Y / 2;
	e->obj->oz = 1500;
	e->obj->dx = 0;
	e->obj->dy = 1;
	e->obj->dz = 0;
	ft_norm(&e->obj->dx, &e->obj->dy, &e->obj->dz);
	e->obj->sz = 0.4;
	e->obj->szcos = cos(e->obj->sz) * cos(e->obj->sz);
	e->obj->szsin = sin(e->obj->sz * e->obj->sz);
	e->obj->r = 255;
	e->obj->g = 165;
	e->obj->b = 0;
	e->obj->next = NULL;
}
