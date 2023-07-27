/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:12:26 by ihama             #+#    #+#             */
/*   Updated: 2023/07/27 16:17:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		error_message("please put one file");
	game = initilize_data(argv[1]);
	game->mlx = mlx_init(game->width * PIXEL,
			game->height * PIXEL, "so_long", false);
	if (!game->mlx)
		return (FALSE);
}


// int	main(int argc, char **argv)
// {
// 	char *map_as_str;
// 	char **map_as_array;
// 	t_game	game;
// 	initilize_data(&game);
// 	game = malloc(sizeof(t_game));
// 	char *map_as_str;
// 	printf("%s\n", map_as_str);
// 	map_as_str = read_map_file(argv[1]);
// 	check_shape(map_as_str);
// 	check_empty(map_as_str);
// 	game.grid = ft_split(map_as_str, '\n');
// 	game.grid = map_as_array;
// 	check_walls(&game);
// 	check_map(&game);
// 	free(map_as_str);
// }
