/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:36:24 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/05 14:36:25 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "cub3d.h"

static int	ft_mlx_clear(t_main *main, int rval)
{
	mlx_destroy_window(main->mlx, main->win);
	if (main->north.img)
		mlx_destroy_image(main->mlx, main->north.img);
	if (main->south.img)
		mlx_destroy_image(main->mlx, main->south.img);
	if (main->east.img)
		mlx_destroy_image(main->mlx, main->east.img);
	if (main->west.img)
		mlx_destroy_image(main->mlx, main->west.img);
	return (rval);
}

static int	ft_mlx_load_imgs1(t_main *main)
{
	main->east.img = mlx_xpm_file_to_image(main->mlx, main->east.path,
			&main->east.w, &main->east.h);
	if (!main->east.img)
		return (ft_mlx_clear(main, 1));
	main->east.addr = mlx_get_data_addr(main->east.img, &main->east.bpp,
			&main->east.ll, &main->east.end);
	if (!main->east.addr)
		return (ft_mlx_clear(main, 1));
	main->west.img = mlx_xpm_file_to_image(main->mlx, main->west.path,
			&main->west.w, &main->west.h);
	if (!main->west.img)
		return (ft_mlx_clear(main, 1));
	main->west.addr = mlx_get_data_addr(main->west.img, &main->west.bpp,
			&main->west.ll, &main->west.end);
	if (!main->west.addr)
		return (ft_mlx_clear(main, 1));
	return (0);
}

static int	ft_mlx_load_imgs(t_main *main)
{
	main->north.img = mlx_xpm_file_to_image(main->mlx, main->north.path,
			&main->north.w, &main->north.h);
	if (!main->north.img)
		return (ft_mlx_clear(main, 1));
	main->north.addr = mlx_get_data_addr(main->north.img, &main->north.bpp,
			&main->north.ll, &main->north.end);
	if (!main->north.addr)
		return (ft_mlx_clear(main, 1));
	main->south.img = mlx_xpm_file_to_image(main->mlx, main->south.path,
			&main->south.w, &main->south.h);
	if (!main->south.img)
		return (ft_mlx_clear(main, 1));
	main->south.addr = mlx_get_data_addr(main->south.img, &main->south.bpp,
			&main->south.ll, &main->south.end);
	if (!main->south.addr)
		return (ft_mlx_clear(main, 1));
	return (ft_mlx_load_imgs1(main));
}

static int	ft_mlx_fillstruct(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		return (1);
	main->win = mlx_new_window(main->mlx, SIZE_X, SIZE_Y, "Cub3d");
	if (!main->mlx)
		return (1);
	mlx_key_hook(main->win, ft_keyhook, main);
	mlx_hook(main->win, 17, 1L << 2, ft_exithook, main);
	return (0);
}

int	ft_mlx_init(t_main *main)
{
	if (ft_mlx_fillstruct(main))
		return (1);
	if (ft_mlx_load_imgs(main))
		return (1);
	mlx_loop(main->mlx);
	return (ft_mlx_clear(main, 0));
}
