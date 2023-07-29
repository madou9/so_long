/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:36:35 by ihama             #+#    #+#             */
/*   Updated: 2023/07/28 22:29:09 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>
# include <stdbool.h>
# include <string.h>

# define TRUE 1
# define FALSE 0
# define PIXEL 50
#define WIDTH 460
#define HEIGHT 160

typedef struct s_textures {
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collec;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_2;
}				t_textures;

typedef struct s_images {
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collec;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*exit_2;
}				t_images;

typedef struct s_game
{
	t_textures	*textu;
	t_images	*imag;
	int			collect;
	int			move_count;
	int			exit;
	int			width;
	int			height;
	int			player;
	int			link_x;
	int			link_y;
	char		**grid;
	char		**mapcopy;
	int			player_pos;
	mlx_t		*mlx;
}				t_game;

/* check map */

void	check_map(t_game *game);
int		get_map_size(char *map);
char	*read_map_file(char *filename);

/*MLX Image*/
void	get_image(t_game *game);
void	get_texture(t_game *game);
void	put_img_floor(t_game *game, t_images *image);
void	put_img_map(t_game *game, t_images *image);
int		row_count(char **grid);
int		valide_mlx_game(t_game *game);
t_game	*initilize_data(t_game *game);

/* initialisation */
void	check_empty(char *map);
int		count_line(char **xy_map);
void	free_string_array(char **array);
int		check_shape(char *map);
void	check_map(t_game *game);
void	validate_and_count_characters(t_game *game, char c, int x, int y);
void	error_message(char *msg);
void	check_walls(t_game *game);

int		count_rupees(t_game *game);
int		get_link_pos(t_game *game, char c );
int		get_exit_pos(t_game *game, char c );

void	image_select(t_game *data,char val, size_t ay, size_t ax);
void	render_map(t_game *data);
void	resize_image(t_game *game);

#endif