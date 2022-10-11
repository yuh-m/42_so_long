/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:39:45 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/11 03:41:47 by eryudi-m         ###   ########.fr       */
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
