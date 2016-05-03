/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:22:57 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 17:21:08 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int		main(int argc, char **argv)
{
	t_env e;

	if (argc == 2 && (((!(ft_strcmp(argv[1], "1"))))
		|| ((!(ft_strcmp(argv[1], "2")))) || ((!(ft_strcmp(argv[1], "3")))
		|| ((!(ft_strcmp(argv[1], "4"))))) || ((!(ft_strcmp(argv[1], "5")))
		|| ((!(ft_strcmp(argv[1], "6")))))))
	{
		ft_init(&e, argv[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "rtv1");
		e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
		e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
		ft_algo(&e);
		mlx_put_image_to_window(e.mlx, e.win, e.im, 0, 0);
		mlx_hook(e.win, 2, (1L << 0), ft_key, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : argument failed");
}

void	ft_init(t_env *e, char *str)
{
	if (!(ft_strcmp(str, "1")))
		ft_inis_1(e);
	if (!(ft_strcmp(str, "2")))
		ft_inis_2(e);
	if (!(ft_strcmp(str, "3")))
		ft_inis_3(e);
	if (!(ft_strcmp(str, "4")))
		ft_inis_4(e);
	if (!(ft_strcmp(str, "5")))
		ft_inis_5(e);
	if (!(ft_strcmp(str, "6")))
		ft_inis_6(e);
}
