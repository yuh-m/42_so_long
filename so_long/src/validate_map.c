/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:33:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 08:46:39 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*static int ck_rectangle (size_t line, size_t len)
{
	if(ft_strlen())
}
*/

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
	char	*first_col;
	char	*last_col;
	int		i;
	int		j;

	i = 0;
		while (data.map[i] !=)

	return(1);
}


//int ck_elements (t_data data)

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
