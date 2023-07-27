/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:36:35 by ihama             #+#    #+#             */
/*   Updated: 2023/07/27 20:51:27 by ihama            ###   ########.fr       */
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
#define WIDTH 256
#define HEIGHT 256

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
	t_images	*imag;
	t_textures	*textu;
	int			collect;
	int			copycollect;
	int			exit_x;
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
void	put_img_map(t_game *game, t_game *image);

/* initialisation */

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

#endif