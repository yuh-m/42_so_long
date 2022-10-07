/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:04:26 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/06 04:46:21 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include "./libft.h"

# define WINDOW_WID 1200
# define WINDOW_HEI 800
# define IMG_ADDR_0 "./img/ground2_white.xpm"
# define IMG_ADDR_1 "./img/rock2.xpm"
# define IMG_ADDR_C "./img/collect1.xpm"
# define IMG_ADDR_E "./img/exit_2.xpm"
# define IMG_ADDR_P "./img/player_3.xpm"
# define MLX_ERROR 1

typedef struct s_img
{
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}				t_img;

typedef struct s_date
{
	void	*mlx;
	void	*mlx_win;
	t_img	*ground;
	t_img	*wall;
	t_img	*player;
	t_img	*collectible;
	t_img	*exit;
} t_data;

int so_long(int argc, char **argv);
int validate_extension(char *filename);
int load_map(char *map_file);

/*Handle.c*/
int handle_no_event(void *data);
int handle_keypress(int keysym, t_data *data);
int handle_keyrelease(int keysym, t_data *data);
int handle_x(t_data *data);

/*Images loading */
int load_sprite(t_data *data);
//test func

#endif

