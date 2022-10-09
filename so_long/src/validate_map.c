/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:33:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 15:31:56 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ck_rectangle (t_data data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(data.map[i]);
	while (data.map[i] != (void *)0)
	{
		if (ft_strlen(data.map[i]) != len)
			return(0);
		i++;
	}
	return(1);
}


int ck_border (t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (data.map[i] != (void *)0)
	{
		j=0;
		if(i == 0 || i == data.map_sz.y - 1)
		{
			while (data.map[i][j] != '\0')
			{
				if (data.map[i][j] != '1')
					return(0);
				j++;
			}
		}
		else
			if (data.map[i][0] != '1' || data.map[i][data.map_sz.x - 1] != '1')
				return (0);
		i++;
	}
	return(1);
}

int ck_elements (t_data data)
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
			j++;
		}
		i++;
	}
	if ((data.cnt_collectible < 1 || data.cnt_exit < 1 || data.cnt_player < 1)\
	|| (data.cnt_exit > 1 || data.cnt_player > 1))
		return(0);
	return (1);
}

int validate_extension(char *filename)
{
	char	*extension;
	int 	len;
	int		i;

	len = ft_strlen(filename);
	extension = "reb.";
	i = 4;
	while (i > 0)
	{
		if (filename[len -i] != extension[i - 1])
			return (0);
		i--;
	}
	return (1);
}
