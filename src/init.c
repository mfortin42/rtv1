/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:16:08 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/02 15:22:42 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_ini_ray(t_env *e)
{
	e->cam = malloc(sizeof(t_ray));
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

	e->lig = malloc(sizeof(t_lig));
	e->lig->lum.ox = WIN_X / 3;
	e->lig->lum.oy = 740;
	e->lig->lum.oz = -3780;

	e->cam_ligx = e->cam->ox - e->lig->lum.ox;
	e->cam_ligy = e->cam->oy - e->lig->lum.oy;
	e->cam_ligz = e->cam->oz - e->lig->lum.oz;
}

void	ft_ini_objs(t_env *e)
{
	e->obj = malloc(sizeof(t_obj));

	e->obj->n = 's';
	e->obj->ox = 1000;
	e->obj->oy = 540;
	e->obj->oz = 2500;//1890;
	e->obj->dx = 0;
	e->obj->dy = 0;
	e->obj->dz = 0;
	ft_norm(&e->obj->dx, &e->obj->dy, &e->obj->dz);
	e->obj->sz = 540;
	e->obj->szcos = cos(e->obj->sz) * cos(e->obj->sz);
	e->obj->szsin = sin(e->obj->sz) * sin(e->obj->sz);

	e->obj->next = NULL;

	t_obj	*tmp;
	tmp = malloc(sizeof(t_obj));
	e->obj->next = tmp;
	tmp->n = 'y';
	tmp->ox = 2000;
	tmp->oy = 540;
	tmp->oz = 1890;
	tmp->dx = 1;
	tmp->dy = 1;
	tmp->dz = 0;
	ft_norm(&tmp->dx, &tmp->dy, &tmp->dz);
	tmp->sz = 200;
	tmp->szcos = cos(tmp->sz) * cos(tmp->sz);
	tmp->szsin = sin(tmp->sz) * sin(tmp->sz);

	tmp->next = NULL;

	t_obj	*tmp2;
	tmp2 = malloc(sizeof(t_obj));
	tmp->next = tmp2;
	tmp2->n = 'p';
	tmp2->ox = 0;
	tmp2->oy = 100;
	tmp2->oz = 0;
	tmp2->dx = 0;
	tmp2->dy = 1;
	tmp2->dz = 0;
	ft_norm(&tmp2->dx, &tmp2->dy, &tmp2->dz);
	tmp2->sz = 200;
	tmp2->szcos = cos(tmp2->sz) * cos(tmp2->sz);
	tmp2->szsin = sin(tmp2->sz) * sin(tmp2->sz);

	tmp2->next = NULL;
/*
	t_obj	*tmp3;
	tmp3 = malloc(sizeof(t_obj));
	tmp2->next = tmp3;
	tmp3->n = 'p';
	tmp3->ox = 200;
	tmp3->oy = 540;
	tmp3->oz = 2000;
	tmp3->dx = 0;
	tmp3->dy = 0;
	tmp3->dz = 0;
	ft_norm(&tmp3->dx, &tmp3->dy, &tmp3->dz);
	tmp3->sz = 100;
	tmp3->next = NULL;
*/
	t_obj	*tmp4;
	tmp4 = malloc(sizeof(t_obj));
	tmp2->next = tmp4;
	tmp4->n = 'c';
	tmp4->ox = 200;
	tmp4->oy = 540;
	tmp4->oz = 2000;
	tmp4->dx = -0.4;
	tmp4->dy = 1;
	tmp4->dz = 0;
	ft_norm(&tmp4->dx, &tmp4->dy, &tmp4->dz);
	tmp4->sz = 0.3;
	tmp4->szcos = cos(tmp4->sz) * cos(tmp4->sz);
	tmp4->szsin = sin(tmp4->sz * tmp4->sz);

	tmp4->next = NULL;

	t_obj	*tmp5;
	tmp5 = malloc(sizeof(t_obj));
	tmp4->next = tmp5;
	tmp5->n = 'p';
	tmp5->ox = 200;
	tmp5->oy = 540;
	tmp5->oz = 15000;
	tmp5->dx = 0;
	tmp5->dy = 0;
	tmp5->dz = 1;
	ft_norm(&tmp5->dx, &tmp5->dy, &tmp5->dz);
	tmp5->sz = 0;
	tmp5->szcos = cos(tmp5->sz) * cos(tmp5->sz);
	tmp5->szsin = sin(tmp5->sz) * sin(tmp5->sz);

	tmp5->next = NULL;
}
