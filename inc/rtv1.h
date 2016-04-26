/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:20:01 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/26 15:01:56 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_X 1920
# define WIN_Y 1080

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

typedef struct		s_ray
{
	double			ox;
	double			oy;
	double			oz;
	double			dx;
	double			dy;
	double			dz;
}					t_ray;

typedef struct		s_obj
{
	char			n;
	double			ox;
	double			oy;
	double			oz;
	double			dx;
	double			dy;
	double			dz;
	double			sz;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*im;
	char			*imc;
	int				bpp;
	int				imlen;
	int				endi;

	t_obj			*obj;
	t_obj			*bg;

	double			**mx;
	double			angle;

	double			t;
	double			m_t;
	char			m_name;
	double			dis;
}					t_env;

void				ft_ini_ray(t_ray *r);
void				ft_ini_objs(t_env *e);

void				ft_algo(t_env *e, t_ray *r);

void				ft_matrix(t_env *e, t_ray *r);
double				**ft_matrix_a(double a, double x, double y, double z);
double				**ft_matrix_b(double a);
double				**ft_matrix_c(double a, double x, double y, double z);
void				ft_sum_matrix(t_env *e, double **mx_a, double **mx_b, double **mx_c);

void				ft_norm(t_ray *r);
void				ft_rot_vect(t_env *e, t_ray *r);

void				ft_all_obj(t_env *e);
void				ft_put_col(t_env *e, int x, int y);

void				ft_sphere(t_env *e);
void				ft_cone(t_env *e);
void				ft_cylindre(t_env *e);
void				ft_plan(t_env *e);

void				ft_put_pixel(t_env *e, int x, int y, int color);

#endif
