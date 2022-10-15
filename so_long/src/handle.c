/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:44:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/15 00:57:29 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_axis(t_data *data, int x, int y)
{
	if (data->map[data->player_pos.y + y][data->player_pos.x + x] != '1')
	{
		if (data->map[data->player_pos.y + y][data->player_pos.x + x] == 'C')
			data->cnt_collectible -= 1;
		data->map[data->player_pos.y][data->player_pos.x] = '0';
		data->player_pos.x = data->player_pos.x + x;
		data->player_pos.y = data->player_pos.y + y;
		data->map[data->player_pos.y][data->player_pos.x] = 'P';
		draw_map(data, &data->exit);
		data->cnt_steps += 1;
		ft_printf("STEPS = %d \n", data->cnt_steps);
		ck_complete_map(data);
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_file(data);
	else if (keysym == XK_w)
		move_axis(data, 0, -1);
	else if (keysym == XK_s)
		move_axis(data, 0, 1);
	else if (keysym == XK_a)
		move_axis(data, -1, 0);
	else if (keysym == XK_d)
		move_axis(data, 1, 0);
	return (0);
}

int	handle_no_event(t_data *data)
{
	if (data->cnt_collectible == 0)
	{
		draw_map(data, &data->exit2);
		if (data->player_pos.x == data->exit_pos.x \
		& data->player_pos.y == data->exit_pos.y)
			draw_map_no_player(data);
	}
	else
		draw_map(data, &data->exit);
	return (0);
}

int	handle_x(t_data *data)
{
	exit_file(data);
	return (0);
}
