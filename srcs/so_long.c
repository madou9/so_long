/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:19 by ihama             #+#    #+#             */
/*   Updated: 2023/07/27 20:43:55 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char *map_as_str;
	char **map_as_array;
	t_game	*game;
	game = malloc(sizeof(t_game));
	char *map_as_str;
	printf("%s\n", map_as_str);
	map_as_str = read_map_file(argv[1]);
	check_shape(map_as_str);
	check_empty(map_as_str);
	map_as_array = ft_split(map_as_str, '\n');
    initilize_data(&game);
	check_walls(&game);
	check_map(&game);
    if (valid_path(&game, map_as_str))
        {
            printf("Map is valid. There is a valid path from the player to all collectibles and the exit.\n");
        }
        else
        {
            printf("Map is invalid. There is no valid path from the player to all collectibles and the exit.\n");
        }

        // Free memory and clean up
        free(map_as_str);
        free_string_array(game.grid);

        return 0;
}
