/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:54:18 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 10:54:20 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "get_next_line.h"

//read the file and assign structures

int	ft_read_file(t_main *main, char	*file)
{
	int		fd;
	size_t	count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	main->temp = get_next_line(fd);
	while (main->temp && count++ >= 0)
		main->temp = get_next_line(fd);
	return (0);
}