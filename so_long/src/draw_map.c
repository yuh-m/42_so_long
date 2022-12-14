/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:17:04 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/16 12:22:51 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_img(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x * PXL_SZ, \
	y * PXL_SZ);
}

void	draw_map(t_data *data, t_img **exit_img)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			put_img(data, data->ground, x, y);
			if (data->map[y][x] == '1')
				put_img(data, data->wall, x, y);
			else if (data->map[y][x] == '0')
				put_img(data, data->ground, x, y);
			else if (data->map[y][x] == 'C')
				put_img(data, data->collectible, x, y);
			put_img(data, *exit_img, data->exit_pos.x, data->exit_pos.y);
			put_img(data, data->player, data->player_pos.x, data->player_pos.y);
			x++;
		}
		y++;
	}
}

void	draw_map_no_player(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			put_img(data, data->ground, x, y);
			if (data->map[y][x] == '1')
				put_img(data, data->wall, x, y);
			else if (data->map[y][x] == '0')
				put_img(data, data->ground, x, y);
			else if (data->map[y][x] == 'C')
				put_img(data, data->collectible, x, y);
			put_img(data, data->exit2, data->exit_pos.x, data->exit_pos.y);
			x++;
		}
		y++;
	}
}
