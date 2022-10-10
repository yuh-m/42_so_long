/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:01:07 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/10 23:01:36 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Initial player movement is on draw_map function

void	get_positions(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_pos.x = x;
				data->player_pos.y = y;
			}
			else if (data->map[y][x] == 'E')
			{
				data->exit_pos.x = x;
				data->exit_pos.y = y;
			}
			else if (data->map[y][x] == 'C')
				data->cnt_collectible += 1;
			x++;
		}
		y++;
	}
}