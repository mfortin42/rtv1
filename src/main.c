/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:22:57 by mfortin           #+#    #+#             */
/*   Updated: 2016/04/27 12:43:50 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int		main(void)
{
	t_env	e;
	t_ray	r;

	ft_ini_ray(&e, &r);
	ft_ini_objs(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "rtv1");
	e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
	ft_algo(&e, &r);
	mlx_put_image_to_window(e.mlx, e.win, e.im, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
