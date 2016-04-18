/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:20:01 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/18 15:44:23 by mfortin          ###   ########.fr       */
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

typedef struct		s_cam
{
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			r_dir_x;
	double			r_dir_y;
	double			r_dir_z;
}					t_cam;

typedef struct		s_obj
{
	char			name;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			dir_x;
	double			dir_y;
	double			dir_z;
	double			size;
	double			depth;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_env
{
	t_cam			cam;
	t_obj			*obj;
	t_obj			*begin;

	void			*mlx;
	void			*win;
	void			*im;
	char			*imc;
	int				bpp;
	int				imlen;
	int				endi;

	double			x;
	double			y;

	double			t;
	double			m_t;
	char			m_name;
	double			dis;
}					t_env;

void				ft_ini_cam(t_env *e);
void				ft_ini_objs(t_env *e);

void				ft_algo(t_env *e);
void				ft_all_obj(t_env *e);
void				ft_put_col(t_env *e);

void				ft_sphere(t_env *e);
void				ft_plan(t_env *e);

void				ft_put_pixel(t_env *e, int x, int y, int color);

#endif
