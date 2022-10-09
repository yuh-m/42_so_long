/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:17:04 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 01:17:05 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



void draw_map(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, 200,100);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, 200,200);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, 400,400);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, 350,500);
	//map_size(data);

}

