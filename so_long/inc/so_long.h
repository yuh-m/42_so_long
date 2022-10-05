/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:04:26 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/10/05 05:18:37 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./libft.h"

# define WINDOW_WID 600
# define WINDOW_HEI 400
# define MLX_ERROR 1

typedef struct s_date
{
	void	*mlx;
	void	*mlx_win;
} t_data;

int so_long(int argc, char **argv);
int validate_extension(char *filename);
int load_map(char *map_file);

/*Handle.c*/
int handle_no_event(void *data);
int handle_keypress(int keysym, t_data *data);
int handle_keyrelease(int keysym, t_data *data);



#endif

