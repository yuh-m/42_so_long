/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:56:35 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 08:14:38 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void get_map_size(t_data *data)
{
	int	i;

	i = 0;
	data->map_sz.x = (ft_strlen(data->map[i]) * PXL_SZ);
	while (data->map[i] != (void *)0)
		i++;
	data->map_sz.y = i * PXL_SZ;
}

int		load_game(char *map_file, t_data data)
{
	ft_printf("Loading map %s \n", map_file);
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.mlx = mlx_init();
	get_map_size(&data);
	data.mlx_win = mlx_new_window(data.mlx, data.map_sz.x, data.map_sz.y, "so_long");
	if (data.mlx == NULL)
	{
		free(data.mlx_win);
		return(MLX_ERROR);
	}
	mlx_loop_hook(data.mlx, &handle_no_event, &data);

	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress,&data);
	//mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease,&data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &handle_x, &data);

	load_sprite(&data);
	draw_map(&data);
	mlx_loop(data.mlx);

	mlx_destroy_display(data.mlx);
	free(data.mlx);

	return(0);
}




