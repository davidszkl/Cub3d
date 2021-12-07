/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:31:29 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/07 12:05:17 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_dir(char c)
{
	return (c == 'N'
			|| c == 'S'
			|| c == 'E'
			|| c == 'W');
}

static t_vec2	set_dir(char c)
{
	t_vec2	r;

	if (c == 'N')
		r = NORTH_VECTOR;
	if (c == 'S')
		r = SOUTH_VECTOR;
	if (c == 'E')
		r = EAST_VECTOR;
	if (c == 'W')
		r = WEST_VECTOR;
	return (r);
}

void	ft_init_player(t_main *main)
{
	t_vec2i	i;

	i.y = -1;
	while (++i.y < main->map_dim.y)
	{
		i.x = -1;
		while (++i.x < main->map_dim.x)
			if (is_dir(main->map[i.y][i.x]))
			{
				main->player_dir = set_dir(main->map[i.y][i.x]);
				main->player_pos = (t_vec2){i.x + .5, i.y + .5};
				return ;
			}
	}
}
