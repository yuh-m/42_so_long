/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:56:35 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/16 12:05:32 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Player movement are dealed on the handle file in backend and draw_map file
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

void	manage_hook(t_data data)
{
	draw_map(&data, &data.exit);
	mlx_loop_hook(data.mlx, handle_no_event, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &handle_x, \
			&data);
	mlx_loop(data.mlx);
	exit_file(&data);
	free(data.mlx);
}

int	load_game(char *map_file, t_data data)
{
	ft_printf("Loading map %s \n", map_file);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.map_sz_px.x, \
								data.map_sz_px.y, "so_long");
	if (data.mlx == NULL)
	{
		free(data.mlx_win);
		return (MLX_ERROR);
	}
	load_sprite(&data);
	get_positions(&data);
	if (!validate_path(&data, map_file))
	{
		exit_file(&data);
		return (0);
	}
	manage_hook(data);
	return (0);
}
