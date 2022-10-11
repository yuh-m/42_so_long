/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:05:42 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/11 03:43:16 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_img(t_data *data, t_img **img, char *addr)
{
	*img = mlx_xpm_file_to_image(data->mlx, addr, &data->map_sz_px.x, \
	&data->map_sz_px.y);
	if (*img == 0)
		exit_error("Error loading sprite \n");
}

static void	get_img(t_data *data)
{
	load_img(data, &data->player, IMG_ADDR_P);
	load_img(data, &data->ground, IMG_ADDR_0);
	load_img(data, &data->wall, IMG_ADDR_1);
	load_img(data, &data->collectible, IMG_ADDR_C);
	load_img(data, &data->exit, IMG_ADDR_E);
	load_img(data, &data->exit2, IMG_ADDR_E_END);
}

int	load_sprite(t_data *data)
{
	if (data->mlx_win != NULL)
	{
		get_img(data);
	}
	return (0);
}
