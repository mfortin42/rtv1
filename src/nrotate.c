/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:13:40 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/26 15:19:01 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_norm(t_ray *r)
{
	r->dx /= sqrt(pow(r->dx, 2) + pow(r->dy, 2) + pow(r->dz, 2));
	r->dy /= sqrt(pow(r->dx, 2) + pow(r->dy, 2) + pow(r->dz, 2));
	r->dz /= sqrt(pow(r->dx, 2) + pow(r->dy, 2) + pow(r->dz, 2));
}

void	ft_rot_vect(t_env *e, t_ray *r)
{
	r->dx = e->mx[0][0] * r->dx + e->mx[0][1] * r->dy + e->mx[0][2] * r->dz;
	r->dy = e->mx[1][0] * r->dx + e->mx[1][1] * r->dy + e->mx[1][2] * r->dz;
	r->dz = e->mx[2][0] * r->dx + e->mx[2][1] * r->dy + e->mx[2][2] * r->dz;
}
