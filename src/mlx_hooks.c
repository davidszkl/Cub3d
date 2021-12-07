/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:40:16 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/07 14:27:17 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define LEFT 123
#define RIGHT 124

int	ft_keyhook(int keycode, t_main *main)
{
	t_vec2	player_dir01 = (t_vec2) {main->player_dir.x * 0.1, main->player_dir.y * 0.1};
	if (keycode == 53)
		ft_exit(main);
	if (keycode == LEFT)
		main->player_dir = rotate(main->player_dir, -PI / 100);
	if (keycode == RIGHT)
		main->player_dir = rotate(main->player_dir, PI / 100);
	if (keycode == W)
		main->player_pos = add(main->player_pos, player_dir01);
	if (keycode == S)
		main->player_pos = sub(main->player_pos, player_dir01);
	if (keycode == A)
		main->player_pos = add(main->player_pos, rotate(player_dir01, -PI / 2.));
	if (keycode == D)
		main->player_pos = sub(main->player_pos, rotate(player_dir01, -PI / 2.));
	return (0);
}

int	ft_exithook(t_main *main)
{
	ft_exit(main);
	return (0);
}
