/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:32:29 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 08:46:50 by eryudi-m         ###   ########.fr       */
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

int so_long(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		if (validate_extension(argv[1]))
		{
			data.map = read_map_file(argv[1]);
			ft_printf("starting game \n");
			if(ck_rectangle(data) & ck_border(data))
				load_game(argv[1], data);
			else
				exit_error("Map elements does not comply all rules");
		}
		else
		{
			ft_printf("wrong format\n");
		}
	}
	else
	{
		exit_error("Provide only the map to be loaded");
	}
	return (0);
}
