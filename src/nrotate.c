/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:13:40 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/29 16:05:06 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_norm(double *x, double *y, double *z)
{
	double	n;

	n = sqrt(pow(*x, 2) + pow(*y, 2) + pow(*z, 2));
	*x /= n;
	*y /= n;
	*z /= n;
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
