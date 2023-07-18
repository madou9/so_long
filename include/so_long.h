/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:36:35 by ihama             #+#    #+#             */
/*   Updated: 2023/07/18 20:25:14 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define WALL 1
#define WALL 1
#define WALL 1


typedef struct jeux
{
    size_t      height;
    size_t      weight;
    char        **grid;
    
} t_game;
/* libft */

void	ft_putchar(char c);
void	ft_putstr(char *s);
char	**ft_split(const char *s, char c);
int64_t	ft_atoi(const char *str);
int		ft_is_sign(char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_sqrt(int number);
int		ft_strcmp(char *str_1, char *str_2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

#endif