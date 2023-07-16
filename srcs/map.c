/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:29 by ihama             #+#    #+#             */
/*   Updated: 2023/07/16 20:37:48 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (!fd)
		printf("Error opening the map file.\n");
		exit(1);
	
}