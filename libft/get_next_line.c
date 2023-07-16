/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:46:30 by ihama             #+#    #+#             */
/*   Updated: 2023/07/16 20:52:30 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char *ft_stradd(char *str, char buff)
{
    int i;
    char *ret;

    i = 0;
    ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
    
}