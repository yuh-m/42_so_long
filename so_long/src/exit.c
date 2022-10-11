/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:05:41 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/11 03:50:17 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i] != (void *)0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_error(char *msg)
{
	ft_printf("Error - %s \n", msg);
}

void	ck_complete_map(t_data *data)
{
	if (data->cnt_collectible == 0)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_map(data, &data->exit2);
		if (data->player_pos.x == data->exit_pos.x \
		& data->player_pos.y == data->exit_pos.y)
		{
			ft_printf("COMPLETED \n");
			mlx_clear_window(data->mlx, data->mlx_win);
			draw_map_no_player(data);
			exit_file(data);
		}
	}
}

int	exit_file(t_data *data)
{
	ft_printf("Closing window \n");
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->exit2);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	exit(0);
	return (0);
}
