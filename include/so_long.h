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
# include <fcntl.h>
# include <memory.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h> 

# define TRUE 1
# define FALSE 0

typedef struct s_game
{
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
}				t_game;

/* check map */

void	check_map(t_game *game);
t_game	initilize_data(t_game *game);
int		get_map_size(char *map);
int		path_ok(t_game *game);
int		exitcheck(t_game *game);
int		checkplayer(t_game *game, int x, int y);
char	*read_map_file(char *filename);
void	check_empty(char *map);
void	check_path(t_game *game);
void	free_grid(char **grid, size_t height);

/*error function*/

/* initialisation */

t_game	initilize_data(t_game *game);

int		count_line(char **xy_map);
void	free_string_array(char **array);
int		check_shape(char *map);
void	check_map(t_game *game);
void	aroundplayer(t_game *game, int x, int y);
void	validate_and_count_characters(t_game *game, char c, int x, int y);
void	error_message(char *msg);
void	check_walls(t_game *game);

int	count_rupees(t_game *game);
int	get_link_pos(t_game *game, char c );
int	get_exit_pos(t_game *game, char c );

#endif