/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:39:45 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/15 02:07:44 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	validate_extension(char *filename)
{
	char	*extension;
	int		len;
	int		i;

	len = ft_strlen(filename);
	extension = "reb.";
	i = 4;
	while (i > 0)
	{
		if (filename[len - i] != extension[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	search_empty_line(t_data data)
{
	int		i;

	i = 0;
	while (data.map[i] != (void *)0)
	{
		if (data.map[i + 1] == (void *)0)
			return (0);
		i++;
	}
	return (1);
}
