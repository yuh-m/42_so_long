/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:33:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/15 02:34:15 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ck_rectangle(t_data data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(data.map[i]);
	while (data.map[i] != (void *)0)
	{
		if (ft_strlen(data.map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	ck_border(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (data.map[i] != (void *)0)
	{
		j = 0;
		if (i == 0 || i == data.map_sz.y - 1)
		{
			while (data.map[i][j] != '\0')
			{
				if (data.map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
			if (data.map[i][0] != '1' || data.map[i][data.map_sz.x - 1] != '1')
				return (0);
		i++;
	}
	return (1);
}

static int	is_allowed_chars(t_data data, int x, int y)
{
	if (data.map[x][y] == 'E' || data.map[x][y] == 'P' || \
		data.map[x][y] == 'C' || data.map[x][y] == '0' || \
		data.map[x][y] == '1')
	{
		return (1);
	}
	exit_error("Char not allowed in the map \n");
	return (0);
}

int	ck_elements(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (data.map[i] != (void *)0)
	{
		j = 0;
		while (data.map[i][j] != '\0')
		{
			if (data.map[i][j] == 'C')
				data.cnt_collectible++;
			else if (data.map[i][j] == 'P')
				data.cnt_player++;
			else if (data.map[i][j] == 'E')
				data.cnt_exit++;
			else if (is_allowed_chars(data, i, j) != 1)
				return (0);
			j++;
		}
		i++;
	}
	if ((data.cnt_collectible < 1 || data.cnt_exit < 1 || data.cnt_player < 1) \
		|| (data.cnt_exit > 1 || data.cnt_player > 1))
		return (0);
	return (1);
}

int	validate_map(t_data data)
{
	if (ck_rectangle(data) & ck_border(data) & ck_elements(data))
		return (1);
	return (0);
}
