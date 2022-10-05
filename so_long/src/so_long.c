/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:32:29 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/05 03:10:36 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int so_long(int argc, char **argv)
{
	if (argc == 2)
	{
		if (validate_extension(argv[1]))
		{
			ft_printf("starting game \n");
			load_map(argv[1]);
		}
		else
		{
			ft_printf("wrong format\n");
		}
	}
	else
	{
		ft_printf("Provide only with the map to loaded");
	}

	return (0);
}
