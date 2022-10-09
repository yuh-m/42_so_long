/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:56:35 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 01:35:08 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char **read_map_file(char *map_file)
{
	int fd;
	char *accumulator;
	char *holder;
	char *line;
	char **map;

	fd = open(map_file, O_RDONLY);
	if (fd == 1)
		return (NULL);
	accumulator = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		holder = accumulator;
		accumulator = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(accumulator,'\n');
	free(accumulator);
	close(fd);
	return(map);
}

int load_map(char *map_file)
{
	t_data	data;

	ft_printf("Loading map %s \n", map_file);
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.map = read_map_file(map_file);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WINDOW_WID, WINDOW_HEI, "so_long");
	//window size actually depends on the number of rows and columns
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
	mlx_loop(data.mlx);

	mlx_destroy_display(data.mlx);
	free(data.mlx);

	return(0);
}




