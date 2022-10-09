/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:17:04 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 08:11:43 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//still need to test how to have two images overlapping each other

void draw_map(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if(data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, x * PXL_SZ, y * PXL_SZ);
			else if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, x * PXL_SZ, y * PXL_SZ);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible, x * PXL_SZ, y * PXL_SZ);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x * PXL_SZ, y * PXL_SZ);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, x * PXL_SZ, y * PXL_SZ);
			x++;
		}
		y++;
	}
}





