/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:13:40 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/27 12:38:27 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_norm(t_ray *r)
{
	double	n;

	n = sqrt(pow(r->dx, 2) + pow(r->dy, 2) + pow(r->dz, 2));
	r->dx /= n;
	r->dy /= n;
	r->dz /= n;
}

void	ft_rot_vect(t_env *e, t_ray *r)
{
	double tmpx;
	double tmpy;
	double tmpz;

	tmpx = r->dx;
	tmpy = r->dy;
	 tmpz = r->dz;
	r->dx = e->mx[0][0] * tmpx + e->mx[0][1] * tmpy + e->mx[0][2] * tmpz;
	r->dy = e->mx[1][0] * tmpx + e->mx[1][1] * tmpy + e->mx[1][2] * tmpz;
	r->dz = e->mx[2][0] * tmpx + e->mx[2][1] * tmpy + e->mx[2][2] * tmpz;
}
