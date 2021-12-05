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

static int	check_n(int n)
{
	if (n < 0 || n > 255)
		return (1);
	return (0);
}

int	ft_atoi_mod(char *str, int *modify)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (str[j] == ' ' || str[j] == ',' || str[j] == 9)
		j++;
	if (!ft_isdigit(str[j]))
		return (-1);
	while (ft_isdigit(str[j]))
	{
		if (check_n(n))
			return (-1);
		n = n * 10 + (str[j++] - '0');
	}
	if (check_n(n))
		return (-1);
	*modify = n;
	return (j);
}
