/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:20:47 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 17:01:53 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int *tmp;

	if (y > WIN_Y || x > WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}

void	ft_norm(double *x, double *y, double *z)
{
	double n;

	n = sqrt(*x * *x + *y * *y + *z * *z);
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

int		ft_key(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
