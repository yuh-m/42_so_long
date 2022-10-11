/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:05:41 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/11 01:55:41 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *msg)
{
	ft_printf("Error - %s \n", msg);
}

void	ck_complete_map(t_data *data)
{
	if (data->cnt_collectible == 0 \
	& data->player_pos.x == data->exit_pos.x \
	& data->player_pos.y == data->exit_pos.y)
	{
		ft_printf("COMPLETED \n");
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_map_no_player(data);
		exit(0);
	}

}
