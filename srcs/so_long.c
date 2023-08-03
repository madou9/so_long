/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:19 by ihama             #+#    #+#             */
/*   Updated: 2023/08/03 15:29:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;
	char	**map_as_array;
	char	*map_as_str;

	if (argc != 2)
	{
		printf("Error: put one file\n");
		return (0);
	}
	check_ber(argv[1]);
	game = malloc(sizeof(t_game));
	map_as_str = read_map_file(argv[1]);
	check_empty_map(map_as_str);
	check_rectangle_map(map_as_str);
	map_as_array = ft_split(map_as_str, '\n');
	printf("map : %s\n", map_as_str);
	game->grid = map_as_array;
	check_walls(game);
	check_contents_map(game);
	valid_path(game, argv[1]);
	start_game(game);
	free_map(game->grid);
	free(game);
	system("leaks so_long");
	return (0);
}
