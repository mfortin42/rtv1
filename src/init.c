/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:16:08 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/18 15:43:31 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_ini_cam(t_env *e)
{
	e->cam.pos_x = WIN_X / 2;
	e->cam.pos_y = WIN_Y / 2;
	e->cam.pos_z = -3780;
	e->cam.r_dir_x = -e->cam.pos_x;
	e->cam.r_dir_y = e->cam.pos_y;
	e->cam.r_dir_z = -e->cam.pos_z;
}

void	ft_ini_objs(t_env *e)
{
	e->obj = malloc(sizeof(t_obj));

	e->obj->name = 's';
	e->obj->pos_x = WIN_X / 2;
	e->obj->pos_y = 300;
	e->obj->pos_z = 1890;
	e->obj->dir_x = 0;
	e->obj->dir_y = 0;
	e->obj->dir_z = 0;
	e->obj->size = 567;
	e->obj->depth = 0;
	e->obj->next = NULL;

	t_obj	*tmp2;
	tmp2 = malloc(sizeof(t_obj));
	e->obj->next = tmp2;
	tmp2->name = 'p';
	tmp2->pos_x = 960;
	tmp2->pos_y = 0;
	tmp2->pos_z = 0;
	tmp2->dir_x = 0;
	tmp2->dir_y = 0;
	tmp2->dir_z = 1;
	tmp2->size = 0;
	tmp2->depth = 17000;
	tmp2->next = NULL;

	t_obj	*tmp;
	tmp = malloc(sizeof(t_obj));
	tmp2->next = tmp;
	tmp->name = 'p';
	tmp->pos_x = 960;
	tmp->pos_y = 0;
	tmp->pos_z = 0;
	tmp->dir_x = 0;
	tmp->dir_y = 1;
	tmp->dir_z = 0;
	tmp->size = 0;
	tmp->depth = 0;
	tmp->next = NULL;
}
