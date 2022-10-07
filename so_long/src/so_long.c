/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:32:29 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/06 01:52:44 by eryudi-m         ###   ########.fr       */
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
			//still need to validate games rules before loading
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
