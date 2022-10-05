/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:56:35 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/05 03:26:53 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int load_map(char *map_file)
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;

	width = 300;
	height = 400;
	ft_printf("Loading map %s \n", map_file);
	mlx =mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "so_long");
	mlx_loop(mlx);

	return(0);
}




