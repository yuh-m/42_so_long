/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:44:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/10 19:47:06 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int handle_no_event()
{
	return(0);
}
int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (keysym == XK_w || keysym == XK_W)
	{
		if (data->map[data->player_pos.y - 1][data->player_pos.x] !=  '1')
		{
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			data->player_pos.y -= 1;
			mlx_clear_window(data->mlx, data->mlx_win);
			data->map[data->player_pos.y][data->player_pos.x] = 'P';
			draw_map(data);
		}
	}
	ft_printf("keypress = %d \n",keysym);
	return(0);
}

int handle_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_printf("Closing \n");
	return(0);
}

