/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:13:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/16 12:19:14 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood(int x, int y, t_path *path)
{
	if (path->map[x][y] != '1')
	{
		if (path->map[x][y] == 'E')
			path->path_toexit = 0;
		if (path->map[x][y] == 'C')
			path->cnt_collectible = path->cnt_collectible - 1;
		path->map[x][y] = '1';
		flood(x + 1, y, path);
		flood(x - 1, y, path);
		flood(x, y + 1, path);
		flood(x, y - 1, path);
	}
}

int	validate_path(t_data *data, char *map_file)
{
	t_path	path;

	path.map = read_map_file(map_file);
	path.path_toexit = 1;
	path.player_pos = data->player_pos;
	path.cnt_collectible = data->cnt_collectible;
	flood (path.player_pos.y, path.player_pos.x, &path);
	free_map(path.map);
	if (path.path_toexit == 0 & path.cnt_collectible == 0)
	{
		return (PATH_EXIST);
	}
	exit_error("Valid path does not exist\n\n");
	return (0);
}
