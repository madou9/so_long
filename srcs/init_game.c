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

t_game	initilize_data(t_game *game)
{
	game->grid = NULL;
	game->mapcopy = NULL;
	game->link_x = 0;
	game->link_y = 0;
	game->collect = 0;
	game->copycollect = 0;
	game->player = 0;
	game->exit = 0;
	return (*game);
}
