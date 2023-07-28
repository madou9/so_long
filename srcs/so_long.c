/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:19 by ihama             #+#    #+#             */
/*   Updated: 2023/07/28 22:23:13 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(int argc, char *argv[])
{
    t_game  game;
    char *map_as_str;

    if (argc != 2)
        printf("Error: put one file\n");
    map_as_str = read_map_file(argv[1]);
    game.grid = &map_as_str;
    valide_mlx_game(&game);
//     check_empty(*(game.grid));
//     check_shape(*(game.grid));
//    map_as_array = ft_split(*(game.grid), '\n');
//     check_walls(&game);
//     check_map(&game);
//     free_string_array(game.grid);
}
