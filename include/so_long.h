/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:36:35 by ihama             #+#    #+#             */
/*   Updated: 2023/08/04 15:46:29 by ihama            ###   ########.fr       */
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
	int			collect_cpy;
	int			img_size;
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
void	check_ber(char *map_file);
char	*read_map_file(char *filename);
void	check_empty_line(char *map);
void	check_empty_map(char *map);
void	check_contents_map(t_game *game);
int		get_map_size(char *map);
void	check_contents_map(t_game *game);
int		check_rectangle_map(char *map);
void	validate_and_count_characters(t_game *game, char c, int x, int y);
void	check_walls(t_game *game);
void	error_message(char *msg);
void	free_map(char **array);
int		count_line(char **xy_map);
int		count_rupees(t_game *game);
int		count_rupees(t_game *game);
void	collect_rupee(t_game *game);
void	delete_orbs(t_game *game, int y, int x);
int		*start_pos(char **map);
void	flood_map(t_game *game, int y, int x);
int		check_flood(t_game *game);
int		valid_path(t_game *game, char *fd);
void	free_map(char **map);

/* initialisation */
t_game	*initilize_data(t_game *game);

/*MLX Image*/
void	get_image(t_game *game);
void	get_texture(t_game *game);
void	resize_image(t_game *game);
void	fill_background(t_game *data);
void	render_map(t_game *data);
void	get_width_and_height(t_game *game);
void	image_select(t_game *data, char val, size_t ay, size_t ax);
int		start_game(t_game *game);

/*move mlx */

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	my_key_hook(mlx_key_data_t keydata, void	*param);

#endif