/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:44:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/10 23:51:24 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void move_axis(t_data *data, int x, int y)
{
	if (data->map[data->player_pos.y + y][data->player_pos.x + x] !=  '1')
		{
			if (data->map[data->player_pos.y + y][data->player_pos.x + x] == 'C')
				data->cnt_collectible -= 1;
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			data->player_pos.x = data->player_pos.x + x;
			data->player_pos.y = data->player_pos.y + y;
			mlx_clear_window(data->mlx, data->mlx_win);
			data->map[data->player_pos.y][data->player_pos.x] = 'P';
			draw_map(data);
			data->cnt_steps +=1;
			ft_printf("STEPS = %d \n",data->cnt_steps);
		}
}

int handle_no_event()
{
	return(0);
}
int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->mlx_win);
	else if (keysym == XK_w)
		move_axis(data, 0, -1);
	else if (keysym == XK_s)
		move_axis(data, 0, 1);
	else if (keysym == XK_a)
		move_axis(data, -1, 0);
	else if (keysym == XK_d)
		move_axis(data, 1, 0);
	return(0);
}

int handle_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_printf("Closing \n");
	return(0);
}

