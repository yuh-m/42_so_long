/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:05:42 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/06 04:58:30 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void		load_img(t_data *data, t_img **img, char *addr)
{
	int		wid;
	int		hei;

	*img = mlx_xpm_file_to_image(data->mlx, addr, &wid, &hei);
	if (*img == 0)
		ft_printf("Error loading sprite \n");
	//(*img)->width = wid;
	//(*img)->height = hei;
	mlx_put_image_to_window(data->mlx, data->mlx_win, *img, 50,50);
}

static void get_img(t_data *data)
{
	load_img(data, &data->player, "./img/test.xpm");
	//load_img(data, &data->player, IMG_ADDR_0);
	//load_img(data, &data->player, IMG_ADDR_1);
	//load_img(data, &data->player, IMG_ADDR_C);
	//load_img(data, &data->player, IMG_ADDR_E);
	//load_img(data, &data->player, IMG_ADDR_P);
}

int load_sprite(t_data *data)
{
	if(data->mlx_win != NULL)
	{
		//mlx_pixel_put(data->mlx, data->mlx_win, WINDOW_WID / 2, WINDOW_HEI / 2, 0xFF0000);
		//put_img(data->mlx, data->mlx_win, img,0 ,0);
		get_img(data);
	}
	return(0);
}

/*
void	put_pixel(t_img *img, int x, int y, int color);
{
	char	*pix;

	pix = img->addr + (x *(img-> bbp / 8) + y * img-> line_len);
	*(int *)pix = color;
}
*/
