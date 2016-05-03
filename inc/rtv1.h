/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:20:01 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 17:20:16 by mfortin          ###   ########.fr       */
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
	double			szcos;
	double			szsin;
	double			r;
	double			g;
	double			b;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_lig
{
	t_ray			lum;
	double			r;
	double			g;
	double			b;
	struct s_lig	*next;
}					t_lig;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*im;
	char			*imc;
	int				bpp;
	int				imlen;
	int				endi;

	t_ray			*cam;
	t_obj			*obj;
	t_obj			*bg;
	t_obj			*m_obj;
	t_lig			*lig;

	double			agl;
	double			cdx;
	double			cdy;
	double			cdz;
	double			**mx;

	double			t;
	double			m_t;
	char			m_name;
	double			dis;

	double			shw;

	double			cam_ligx;
	double			cam_ligy;
	double			cam_ligz;

	double			ex;
	double			ey;
	double			ez;
	double			ea;

	double			a;
	double			b;
	double			c;

	double			r;
	double			g;
	double			bl;

	double			nx;
	double			ny;
	double			nz;
}					t_env;

void				ft_ini_ray(t_env *e);
void				ft_ini_objs(t_env *e);

void				ft_algo(t_env *e);

void				ft_matrix(t_env *e);
double				**ft_matrix_a(double a, double x, double y, double z);
double				**ft_matrix_b(double a);
double				**ft_matrix_c(double a, double x, double y, double z);
void				ft_smx(t_env *e, double **m_a, double **m_b, double **m_c);

void				ft_norm(double *x, double *y, double *z);
void				ft_rot_vect(t_env *e, t_ray *r);

void				ft_all_lig(t_env *e);
void				ft_normal(t_env *e, t_obj *o, double m_t);
void				ft_normal_c_y(t_env *e, t_obj *o, double m_t);
void				ft_angle(t_env *e, t_obj *o);

void				ft_all_obj(t_env *e, t_ray *r);
void				ft_put_col(t_env *e, int x, int y);

void				ft_sphere(t_env *e, t_ray *r);
void				ft_cone(t_env *e, t_ray *r);
void				ft_cylindre(t_env *e, t_ray *r);
void				ft_plan(t_env *e);

void				ft_put_pixel(t_env *e, int x, int y, int color);
int					ft_key(int keycode);
void				ft_error(char *str);

void				ft_init(t_env *e, char *str);

void				ft_inis_1(t_env *e);
void				ft_inis_1_1(t_env *e);

void				ft_inis_2(t_env *e);
void				ft_inis_2_1(t_env *e);

void				ft_inis_3(t_env *e);
void				ft_inis_3_1(t_env *e);

void				ft_inis_4(t_env *e);
void				ft_inis_4_1(t_env *e);

void				ft_inis_5(t_env *e);
void				ft_inis_5_1(t_env *e);
void				ft_inis_5_2(t_env *e);
void				ft_inis_5_3(t_obj *obj2);
void				ft_inis_5_4(t_obj *obj3);
void				ft_inis_5_5(t_obj *obj4);

void				ft_inis_6(t_env *e);
void				ft_inis_6_1(t_env *e);
void				ft_inis_6_2(t_env *e);
void				ft_inis_6_3(t_obj *obj2);
void				ft_inis_6_4(t_obj *obj3);
void				ft_inis_6_5(t_obj *obj4);

#endif
