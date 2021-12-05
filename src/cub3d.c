/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:17:40 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/30 09:17:41 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "free.h"

void	ft_exit(t_main *main)
{
	ft_free_all(main, 0);
	exit(0);
}

static void	ft_init_struct(t_main *main, int argc)
{
	(void)argc;
	main->north.path = 0;
	main->north.img = 0;
	main->south.path = 0;
	main->south.img = 0;
	main->east.path = 0;
	main->east.img = 0;
	main->west.path = 0;
	main->west.img = 0;
}

int	main(int argc, char **argv)
{
	t_main	main;

	ft_init_struct(&main, argc);
	if (ft_file_struct(&main, argv[1]))
		return (1);
	ft_showstate(&main);
	if (ft_mlx_init(&main))
		return (ft_free_all(&main, 1));
	return (0);
}
