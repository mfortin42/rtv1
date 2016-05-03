/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5_6_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:11:31 by mfortin           #+#    #+#             */
/*   Updated: 2016/05/03 17:22:40 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	ft_inis_5_5(t_obj *obj4)
{
	t_obj *obj5;

	if (!(obj5 = malloc(sizeof(t_obj))))
		ft_error("error : malloc failed");
	obj5 = malloc(sizeof(t_obj));
	obj4->next = obj5;
	obj5->n = 'p';
	obj5->ox = 200;
	obj5->oy = 100;
	obj5->oz = 10000;
	obj5->dx = 0;
	obj5->dy = 1;
	obj5->dz = 0;
	ft_norm(&obj5->dx, &obj5->dy, &obj5->dz);
	obj5->sz = 0;
	obj5->r = 0;
	obj5->g = 0;
	obj5->b = 255;
	obj5->next = NULL;
}

void	ft_inis_6_5(t_obj *obj4)
{
	t_obj *obj5;

	if (!(obj5 = malloc(sizeof(t_obj))))
		ft_error("error : malloc failed");
	obj5 = malloc(sizeof(t_obj));
	obj4->next = obj5;
	obj5->n = 'p';
	obj5->ox = 200;
	obj5->oy = 100;
	obj5->oz = 10000;
	obj5->dx = 0;
	obj5->dy = 1;
	obj5->dz = 0;
	ft_norm(&obj5->dx, &obj5->dy, &obj5->dz);
	obj5->sz = 0;
	obj5->r = 0;
	obj5->g = 0;
	obj5->b = 255;
	obj5->next = NULL;
}
