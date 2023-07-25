/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:19 by ihama             #+#    #+#             */
/*   Updated: 2023/07/23 17:37:32 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv) 
{
	(void)argc;
	t_game game;
	char *map_as_str;
	printf("main!\n");
	initilize_data(&game);
	map_as_str = read_map_file(argv[1]);
	if (map_as_str == NULL)
	{
		printf("Error reading map file.\n");
		return 1;
	}
	if (check_shape(map_as_str) != 0)
	{
		free(map_as_str);
		return 1;
	}
	check_empty(map_as_str);
	game.grid = ft_split(map_as_str, '\n');
	printf("%s\n", map_as_str);
	free(map_as_str);
	if (game.grid == NULL)
	{
		printf("Error splitting map into grid.\n");
		return 1;
	}
	check_walls(&game);
	check_map(&game);
	path_ok(&game);
	free_string_array(game.grid);
	//Check if the path is valid
	// if (path_ok(&game))
	// 	printf("Congratulations! You can win the game!\n");
	// else
	// 	printf("Sorry, no valid path found.\n");
	// return 0;
	// // Copy the map for simulation
	// if (!grid(&game))
	// {
	// 	printf("Error copying the map.\n");
	// 	return 1;
	// }

}
