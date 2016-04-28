/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:16:08 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/28 16:33:22 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_ini_ray(t_env *e, t_ray *r)
{
	r->ox = WIN_X / 2;
	r->oy = WIN_Y / 2;
	r->oz = -3780;
	r->dx = -WIN_X / 2;
	r->dy = WIN_Y / 2;
	r->dz = 3780;

	e->agl = 0;
	e->cdx = 0;
	e->cdy = 0;
	e->cdz = 0;
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
	e->obj->sz = 540;
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
	tmp->next = NULL;

	t_obj	*tmp2;
	tmp2 = malloc(sizeof(t_obj));
	tmp->next = tmp2;
	tmp2->n = 'p';
	tmp2->ox = 0;
	tmp2->oy = 400;
	tmp2->oz = 0;
	tmp2->dx = 0.2;
	tmp2->dy = 1;
	tmp2->dz = 0;
	ft_norm(&tmp2->dx, &tmp2->dy, &tmp2->dz);
	tmp2->sz = 200;
	tmp2->next = NULL;

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

	t_obj	*tmp4;
	tmp4 = malloc(sizeof(t_obj));
	tmp3->next = tmp4;
	tmp4->n = 'c';
	tmp4->ox = 200;
	tmp4->oy = 540;
	tmp4->oz = 2000;
	tmp4->dx = -0.4;
	tmp4->dy = 1;
	tmp4->dz = 0;
	ft_norm(&tmp4->dx, &tmp4->dy, &tmp4->dz);
	tmp4->sz = 0.3;
	tmp4->next = NULL;

}
