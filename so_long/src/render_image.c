/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:05:42 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/06 03:05:52 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int render(t_data *data)
{
	if(data->mlx_win != NULL)
	{
		mlx_pixel_put(data->mlx, data->mlx_win, WINDOW_WID / 2, WINDOW_HEI / 2, 0xFF0000);
	}
	return(0);
}

void	img_pix_put(t_img *img, int x, int y, int color);
{
	char	*pix;

	pix = img->addr + (x *(img-> bbp / 8) + y * img-> line_len);
	*(int *)pix = color;
}
