/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:26:25 by ihama             #+#    #+#             */
/*   Updated: 2023/07/18 21:15:14 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_content_map(int i)
{
	if (!(ft_strchr("PEC01\n", i)))
		printf("map not containt valid character");
}

void	check_content_map(char *map)
{
	int	i;
	int	p;
	int	e;
	int	c;

	while (map[i] != 0)
	{
		if (map[i] == 'P')
			p++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'C')
			c++;
		else
			check_content_map(map[i]);
	}
	if (p == 0 || e <= 0 || c <= 0)
		printf("content Map is not valid");
		exit(1);
}

void check_map_rectangle(char **map)
{
	
}