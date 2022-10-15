/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:13:37 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/15 03:52:23 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//if exit_found == 1 and cnt_collettibles == 0 THEN return 1  (cleared conditions)

int	validate_path(t_data data)
{
	t_path	path;

	path.cnt_exit = data.cnt_exit;
	ft_printf("path = %d &&& data = %d\n",path.cnt_exit, data.cnt_exit);

	path.cnt_exit = 10;
	ft_printf("path = %d &&& data = %d",path.cnt_exit, data.cnt_exit);

	path.cnt_collectible = data.cnt_collectible;
	ft_printf("path = %d &&& data = %d\n",path.cnt_collectible, data.cnt_collectible);

	path.cnt_collectible = 10;
	ft_printf("path = %d &&& data = %d",path.cnt_collectible, data.cnt_collectible);

	return (1);
}

//free map validation
