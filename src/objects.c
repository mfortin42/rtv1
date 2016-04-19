/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:17:46 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/19 15:36:44 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_sphere(t_env *e)
{
	double	a;
	double	b;
	double	c;

	a = pow(e->cam.r_dir_x + e->x, 2)
		+ pow(e->cam.r_dir_y - e->y, 2)
		+ pow(e->cam.r_dir_z, 2);
	b = 2 * ((e->cam.r_dir_x + e->x) * (e->cam.pos_x - e->begin->pos_x)
		+ (e->cam.r_dir_y - e->y) * (e->cam.pos_y - e->begin->pos_y)
		+ e->cam.r_dir_z * (e->cam.pos_z - e->begin->pos_z));
	c = (pow(e->cam.pos_x - e->begin->pos_x, 2)
		+ pow(e->cam.pos_y - e->begin->pos_y, 2)
		+ pow(e->cam.pos_z - e->begin->pos_z, 2)) - pow(e->begin->size, 2);
	e->dis = pow(b, 2) - 4 * a * c;
	if (e->dis > 0)
	{
		e->t = ((-b + sqrt(e->dis)) / (2 * a) <= (-b - sqrt(e->dis)) / (2 * a) ?
				(-b + sqrt(e->dis)) / (2 * a) : (-b - sqrt(e->dis)) / (2 * a));
	}
}

void	ft_cone(t_env *e)
{
	double	a;
	double	b;
	double	c;

	a = pow(e->cam.r_dir_x + e->x, 2)
		- pow(e->cam.r_dir_y - e->y, 2)
		+ pow(e->cam.r_dir_z, 2);
	b = 2 * ((e->cam.r_dir_x + e->x) * (e->cam.pos_x - e->begin->pos_x)
		- (e->cam.r_dir_y - e->y) * (e->cam.pos_y - e->begin->pos_y)
		+ e->cam.r_dir_z * (e->cam.pos_z - e->begin->pos_z));
	c = (pow(e->cam.pos_x - e->begin->pos_x, 2)
		- pow(e->cam.pos_y - e->begin->pos_y, 2)
		+ pow(e->cam.pos_z - e->begin->pos_z, 2));
	e->dis = pow(b, 2) - 4 * a * c;
	if (e->dis > 0)
	{
		e->t = ((-b + sqrt(e->dis)) / (2 * a) <= (-b - sqrt(e->dis)) / (2 * a) ?
				(-b + sqrt(e->dis)) / (2 * a) : (-b - sqrt(e->dis)) / (2 * a));
	}
}

void	ft_plan(t_env *e)
{
	e->t = -((e->begin->dir_x * (e->cam.pos_x - e->begin->pos_x)
			+ e->begin->dir_y * (e->cam.pos_y - e->begin->pos_y)
			+ e->begin->dir_z * (e->cam.pos_z - e->begin->pos_z)
			- e->begin->depth)
			/ (e->begin->dir_x * (e->cam.r_dir_x + e->x)
			+ e->begin->dir_y * (e->cam.r_dir_y - e->y)
			+ e->begin->dir_z * e->cam.r_dir_z));
}

void	ft_cylindre(t_env *e)
{
	double	a;
	double	b;
	double	c;

	a = pow(e->cam.r_dir_x + e->x, 2)
		+ pow(e->cam.r_dir_z, 2);
	b = 2 * (e->cam.r_dir_x + e->x) * (e->cam.pos_x - e->begin->pos_x)
		+ 2 * e->cam.r_dir_z * (e->cam.pos_z - e->begin->pos_z);
	c = (pow(e->cam.pos_x - e->begin->pos_x, 2)
		+ pow(e->cam.pos_z - e->begin->pos_z, 2)) - pow(e->begin->size, 2);
	e->dis = pow(b, 2) - 4 * a * c;
	if (e->dis > 0)
	{
		e->t = ((-b + sqrt(e->dis)) / (2 * a) <= (-b - sqrt(e->dis)) / (2 * a) ?
				(-b + sqrt(e->dis)) / (2 * a) : (-b - sqrt(e->dis)) / (2 * a));
	}
}
