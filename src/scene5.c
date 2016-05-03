/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:44:31 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 17:22:09 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_inis_5(t_env *e)
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
	e->lig->lum.ox = WIN_X / 2 + 1000;
	e->lig->lum.oy = WIN_Y / 2 + 1000;
	e->lig->lum.oz = -3780;
	e->cam_ligx = e->cam->ox - e->lig->lum.ox;
	e->cam_ligy = e->cam->oy - e->lig->lum.oy;
	e->cam_ligz = e->cam->oz - e->lig->lum.oz;
	ft_inis_5_1(e);
}

void	ft_inis_5_1(t_env *e)
{
	if (!(e->obj = malloc(sizeof(t_obj))))
		ft_error("error : malloc failed");
	e->obj->n = 's';
	e->obj->ox = WIN_X / 2;
	e->obj->oy = WIN_Y / 2 - 200;
	e->obj->oz = 1200;
	e->obj->dx = 0;
	e->obj->dy = 0;
	e->obj->dz = 0;
	ft_norm(&e->obj->dx, &e->obj->dy, &e->obj->dz);
	e->obj->sz = 300;
	e->obj->r = 255;
	e->obj->g = 0;
	e->obj->b = 0;
	e->obj->next = NULL;
	ft_inis_5_2(e);
}

void	ft_inis_5_2(t_env *e)
{
	t_obj *obj2;

	if (!(obj2 = malloc(sizeof(t_obj))))
		ft_error("error : malloc failed");
	e->obj->next = obj2;
	obj2->n = 'y';
	obj2->ox = 1800;
	obj2->oy = 240;
	obj2->oz = 1900;
	obj2->dx = 0;
	obj2->dy = 1;
	obj2->dz = 0;
	ft_norm(&obj2->dx, &obj2->dy, &obj2->dz);
	obj2->sz = 200;
	obj2->r = 0;
	obj2->g = 255;
	obj2->b = 0;
	obj2->next = NULL;
	ft_inis_5_3(obj2);
}

void	ft_inis_5_3(t_obj *obj2)
{
	t_obj *obj3;

	if (!(obj3 = malloc(sizeof(t_obj))))
		ft_error("error : malloc failed");
	obj2->next = obj3;
	obj3->n = 'p';
	obj3->ox = 0;
	obj3->oy = 100;
	obj3->oz = 5000;
	obj3->dx = 0;
	obj3->dy = 0;
	obj3->dz = 1;
	ft_norm(&obj3->dx, &obj3->dy, &obj3->dz);
	obj3->sz = 0;
	obj3->r = 105;
	obj3->g = 105;
	obj3->b = 105;
	obj3->next = NULL;
	ft_inis_5_4(obj3);
}

void	ft_inis_5_4(t_obj *obj3)
{
	t_obj *obj4;

	if (!(obj4 = malloc(sizeof(t_obj))))
		ft_error("error : malloc failed");
	obj3->next = obj4;
	obj4->n = 'c';
	obj4->ox = 200;
	obj4->oy = 340;
	obj4->oz = 2000;
	obj4->dx = 1;
	obj4->dy = 1;
	obj4->dz = 0;
	ft_norm(&obj4->dx, &obj4->dy, &obj4->dz);
	obj4->sz = 0.3;
	obj4->szcos = cos(obj4->sz) * cos(obj4->sz);
	obj4->szsin = sin(obj4->sz * obj4->sz);
	obj4->r = 255;
	obj4->g = 165;
	obj4->b = 0;
	obj4->next = NULL;
	ft_inis_5_5(obj4);
}
