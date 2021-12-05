/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:40:16 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/05 15:40:17 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_keyhook(int keycode, t_main *main)
{
	if (keycode == 53)
		ft_exit(main);
	return (0);
}

int	ft_exithook(t_main *main)
{
	ft_exit(main);
	return (0);
}
