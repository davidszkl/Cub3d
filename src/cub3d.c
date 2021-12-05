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

static void	ft_init_struct(t_main *main, int argc)
{
	(void)argc;
	main->north.path = 0;
	main->south.path = 0;
	main->east.path = 0;
	main->west.path = 0;
}

int	main(int argc, char **argv)
{
	t_main	main;

	ft_init_struct(&main, argc);
	if (ft_file_struct(&main, argv[1]))
		return (1);
	ft_showstate(&main);
	ft_free_all(&main, 0);
	return (0);
}
