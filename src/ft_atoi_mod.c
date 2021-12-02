/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:19:54 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/02 14:19:56 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static int    check_n(int n, char c)
{
    if ((255 - (c - '0')) / 10 < n)
        return (0);
    return (1);
}

int    ft_atoi_mod(char *str, int *modify)
{
    int	n;
	int	j;

    n = 0;
	j = 0;
    while (ft_isdigit(str[j]))
    {
        if (!check_n(n, str[j]))
            return (-1);
        n = n * 10 + (str[j++] - '0');
    }
    if (!ft_isdigit(str[j]))
        return (-1);
	*modify = n;
	return (j);
}
