/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:19:31 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/07 12:06:13 by mlefevre         ###   ########.fr       */
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

void	ft_showstate(t_main *main)
{
	printf("n = %s\n", main->north.path);
	printf("s = %s\n", main->south.path);
	printf("e = %s\n", main->east.path);
	printf("w = %s\n", main->west.path);
	printf("floor = %d,%d,%d\n", main->floor.rgb1[0], main->floor.rgb1[1],
		main->floor.rgb1[2]);
	printf("ceilling = %d,%d,%d\n", main->ceilling.rgb1[0],
		main->ceilling.rgb1[1], main->ceilling.rgb1[2]);
	printf("player_dir = (%f, %f)\n", main->player_dir.x, main->player_dir.y);
	printf("player_pos = (%f, %f)\n", main->player_pos.x, main->player_pos.y);
	ft_showtab(main->map);
}
