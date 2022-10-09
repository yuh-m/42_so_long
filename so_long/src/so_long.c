/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:32:29 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/10 01:44:39 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_map_size(t_data *data)
{
	int	i;

	i = 0;
	data->map_sz.x = ft_strlen(data->map[i]);
	data->map_sz_px.x = data->map_sz.x * PXL_SZ;
	while (data->map[i] != (void *)0)
		i++;
	data->map_sz.y = i;
	data->map_sz_px.y = data->map_sz.y * PXL_SZ;
}

void	init_data(t_data *data)
{
	ft_printf("Starting game \n");
	get_map_size(data);
	data->cnt_player = 0;
	data->cnt_collectible = 0;
	data->cnt_exit = 0;
}

char	**read_map_file(char *map_file)
{
	int		fd;
	char	*accumulator;
	char	*holder;
	char	*line;
	char	**map;

	fd = open(map_file, O_RDONLY);
	if (fd == 1)
		return (NULL);
	accumulator = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = accumulator;
		accumulator = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(accumulator, '\n');
	free(accumulator);
	close(fd);
	return (map);
}

int	so_long(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (validate_extension(argv[1]))
		{
			data.map = read_map_file(argv[1]);
			if (search_empty_line(data))
			{
				exit_error("Map with empty line \n");
				return (0);
			}
			init_data(&data);
			if (validate_map(data))
				load_game(argv[1], data);
			else
				exit_error("Map elements does not comply all rules");
		}
		else
			exit_error("Wrong map format\n");
	}
	else
		exit_error("Provide only the map to be loaded");
	return (0);
}
