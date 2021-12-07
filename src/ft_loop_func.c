/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:52:19 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/07 14:12:50 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "cub3d.h"
#include "raytrace_return.h"

t_raytrace_return	raytrace(t_vec2 pos,
	t_vec2 dir, const char **map, t_vec2i map_dim);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	draw_wall(t_vec2 dir, t_main *main, int x, t_raytrace_return r)
{
	const float	a = atan2f(dir.y, dir.x) - atan2f(main->player_dir.y, main->player_dir.x);
	const int	wall_len = SIZE_Y / (cosf(a) * r.d);
	int y2;
	int	y;

	y = -1;
	while (++y < (SIZE_Y - wall_len) / 2)
		my_mlx_pixel_put(&main->img, x, y, 0xff0000);
	y2 = y;
	y--;
	while (++y - y2 < wall_len)
		my_mlx_pixel_put(&main->img, x, y, 0x00ff00);
	y2 = y;
	y--;
	while (++y - y2 < (SIZE_Y - wall_len) / 2)
		my_mlx_pixel_put(&main->img, x, y, 0x0000ff);
}

int	ft_loop_func(t_main *main)
{
	t_raytrace_return	r;
	const t_vec2		p = rotate(main->player_dir, PI / 2);
	t_vec2				dir;
	int					x;

	x = -1;
	while (++x < SIZE_X)
	{
		dir.x = main->player_dir.x / 2. + p.x * (x - SIZE_X / 2.) / (float)SIZE_X;
		dir.y = main->player_dir.y / 2. + p.y * (x - SIZE_X / 2.) / (float)SIZE_X;
		dir = unit(dir);
		r = raytrace(main->player_pos, dir, (const char **)main->map, main->map_dim);
		draw_wall(dir, main, x, r);
	}
	mlx_put_image_to_window(main->mlx, main->win, main->img.img, 0, 0);
	return (0);
}
