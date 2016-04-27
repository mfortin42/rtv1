/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:16:08 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/27 13:51:35 by mfortin          ###   ########.fr       */
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
	e->obj->oz = 1890;
	e->obj->dx = 0;
	e->obj->dy = 0;
	e->obj->dz = 0;
	e->obj->sz = 540;
	e->obj->next = NULL;
/*
	t_obj	*tmp;
	tmp = malloc(sizeof(t_obj));
	e->obj->next = tmp;
	tmp->n = 'c';
	tmp->ox = WIN_X / 2;
	tmp->oy = 540;
	tmp->oz = 1890;
	tmp->dx = 0;
	tmp->dy = 0;
	tmp->dz = 0;
	tmp->sz = 0;
	tmp->next = NULL;

	t_obj	*tmp2;
	tmp2 = malloc(sizeof(t_obj));
	tmp->next = tmp2;
	tmp2->n = 'y';
	tmp2->ox = 2000;
	tmp2->oy = 540;
	tmp2->oz = 1890;
	tmp2->dx = 0;
	tmp2->dy = 0;
	tmp2->dz = 0;
	tmp2->sz = 200;
	tmp2->next = NULL;

	t_obj	*tmp3;
	tmp3 = malloc(sizeof(t_obj));
	tmp2->next = tmp3;
	tmp3->n = 'p';
	tmp3->ox = 960;
	tmp3->oy = 0;
	tmp3->oz = 0;
	tmp3->dx = 0;
	tmp3->dy = 0;
	tmp3->dz = 1;
	tmp3->sz = 0;
	tmp3->next = NULL;

	t_obj	*tmp4;
	tmp4 = malloc(sizeof(t_obj));
	tmp3->next = tmp4;
	tmp4->n = 'p';
	tmp4->ox = 960;
	tmp4->oy = 0;
	tmp4->oz = 0;
	tmp4->dx = 0;
	tmp4->dy = 1;
	tmp4->dz = 0;
	tmp4->sz = 0;
	tmp4->next = NULL;
*/
}
