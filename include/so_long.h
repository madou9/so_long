/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:36:35 by ihama             #+#    #+#             */
/*   Updated: 2023/07/24 17:03:31 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>
# include <time.h>

#define WALL '1'
#define COLLECTIBLE 'C'
#define EXIT 'E'
#define WIDTH 500
#define HEIGHT 500

typedef struct t_winsize
{
	size_t	height;
	size_t	width;
	size_t	x;
	size_t	y;
}			t_winsize;

typedef struct s_game
{
	int			collect;
	int			copycollect;
	int			exit;
	int			player;
	size_t		link_x;
	size_t		link_y;
	char		**grid;
	char		**mapcopy;
	t_winsize	*winsize;
	int			player_pos;
}				t_game;

/* check map */

char	*read_map(const char *str);
void	check_content_map(char **map);
void	check_map_rectangle(char **map);
void	check_empty_map(char **map);
void	check_empty_line(char **map);
int		check_ber(char *map_file);
void	check_wall(t_game *game);
int		flood_fill(t_game *temp, size_t y, size_t x);
void	free_grid(char **grid, size_t height);
void	check_path(t_game *game);

/*error function*/
void	display_error(const char *error_msg, bool exit_program);

/* initialisation */

t_game	initilize_data(char **map);

#endif
