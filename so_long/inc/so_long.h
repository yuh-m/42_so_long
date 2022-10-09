/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:04:26 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/09 06:24:06 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include <fcntl.h>
# include "./libft.h"

# define WINDOW_WID 1200
# define WINDOW_HEI 800
# define PXL_SZ 32
# define IMG_ADDR_0 "./img/tile00_32px.xpm"
# define IMG_ADDR_1 "./img/tile01_32px.xpm"
# define IMG_ADDR_C "./img/ball_32px.xpm"
# define IMG_ADDR_E "./img/ladder_32px.xpm"
# define IMG_ADDR_P "./img/player_32px.xpm"
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

typedef struct s_coord
{
	int x;
	int y;
}	t_coord;

typedef struct s_date
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_img	*ground;
	t_img	*wall;
	t_img	*player;
	t_img	*collectible;
	t_img	*exit;
	t_coord map_sz;
	t_coord player_pos;

} t_data;

int		so_long(int argc, char **argv);
int		validate_extension(char *filename);
int		load_map(char *map_file);
void	draw_map(t_data *data);

/*Handle.c*/
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_x(t_data *data);

/*Images loading */
int load_sprite(t_data *data);


#endif

