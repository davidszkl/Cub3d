/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:30:05 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 15:30:07 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "utils.h"

void	ft_showtab(char **tab)
{
	int	n;

	n = 0;
	if (!tab)
		return ;
	while (tab[n])
	{
		write(1, tab[n], ft_strlen(tab[n]));
		n++;
	}
	write(1, "\n", 1);
}
