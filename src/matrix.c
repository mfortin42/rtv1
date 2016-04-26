/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:46:07 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/26 15:12:32 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_matrix(t_env *e, t_ray *r)
{
	double **mx_a;
	double **mx_b;
	double **mx_c;

	mx_a = ft_matrix_a(1 - cos(e->angle), r->dx, r->dy, r->dz);
	mx_b = ft_matrix_b(cos(e->angle));
	mx_c = ft_matrix_c(sin(e->angle), r->dx, r->dy, r->dz);
	ft_sum_matrix(e, mx_a, mx_b, mx_c);
}

double	**ft_matrix_a(double a, double x, double y, double z)
{
	int		i;
	double	**matrix;

	i = -1;
	matrix = (double **)malloc(sizeof(double) * 9);
	while (++i < 3)
		matrix[i] = (double *)malloc(sizeof(double) * 3);
	matrix[0][0] = x * x * a;
	matrix[0][1] = x * y * a;
	matrix[0][2] = x * z * a;
	matrix[1][0] = y * x * a;
	matrix[1][1] = y * y * a;
	matrix[1][2] = y * z * a;
	matrix[2][0] = z * x * a;
	matrix[2][1] = z * y * a;
	matrix[2][2] = z * z * a;
	return (matrix);
}

double	**ft_matrix_b(double a)
{
	int		i;
	int		j;
	double	**matrix;

	i = -1;
	matrix = (double **)malloc(sizeof(double) * 9);
	while (++i < 3)
	{
		matrix[i] = (double *)malloc(sizeof(double) * 3);
		j = -1;
		while (++j < 3)
		{
			if (i == j)
				matrix[i][j] = a;
			else
				matrix[i][j] = 0;
		}
	}
	return (matrix);
}

double	**ft_matrix_c(double a, double x, double y, double z)
{
	int		i;
	double	**matrix;

	i = -1;
	matrix = (double **)malloc(sizeof(double) * 9);
	while (++i < 3)
		matrix[i] = (double *)malloc(sizeof(double) * 3);
	matrix[0][0] = 0;
	matrix[0][1] = -z * a;
	matrix[0][2] = y * a;
	matrix[1][0] = z * a;
	matrix[1][1] = 0;
	matrix[1][2] = -x * a;
	matrix[2][0] = -y * a;
	matrix[2][1] = z * a;
	matrix[2][2] = 0;
	return (matrix);
}

void	ft_sum_matrix(t_env *e, double **mx_a, double **mx_b, double **mx_c)
{
	int i;
	int j;

	i = -1;
	e->mx = (double **)malloc(sizeof(double) * 9);
	while (++i < 3)
		e->mx[i] = (double *)malloc(sizeof(double) * 3);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			e->mx[i][j] = mx_a[i][j] + mx_b[i][j] + mx_c[i][j];
		free(mx_a[i]);
		free(mx_b[i]);
		free(mx_c[i]);
	}
	free(mx_a);
	free(mx_b);
	free(mx_c);
}
