/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:55:22 by ihama             #+#    #+#             */
/*   Updated: 2023/07/23 22:30:30 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	initilize_data(char **map)
{
	t_game	*data;
	char	*map_as_str;
	char	**map_as_array;

	map_as_str = read_map(*map);
	check_empty_map(&map_as_str);
	check_empty_line(&map_as_str);
	check_content_map(&map_as_str);
	map_as_array = ft_split(map_as_str, '\n');
	check_map_rectangle(map_as_array);
	data = (t_game *)malloc(sizeof(t_game));
	if (!data)
		display_error("Memory allocation failed.", true);
	data->winsize->width = 0;
	data->winsize->height = 0;
	data->winsize->x = 0;
	data->winsize->y = 0;
	data->coins = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->grid = map_as_array;
	check_wall(data);
	check_path(data);
	free(map_as_str);
	return (*data);
}
