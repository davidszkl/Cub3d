/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:44:09 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 14:44:11 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "cub3d.h"

int	ft_check_params(char **tab)
{
	size_t	n;
	char	*tmp;
	int		fd;

	n = 0;
	while (tab[n])
	{
		if (ft_strncmp(tab[n], "NO ", 3) && ft_strncmp(tab[n], "SO ", 3)
			&& ft_strncmp(tab[n], "WE ", 3) && ft_strncmp(tab[n], "EA ", 3)
			&& ft_strncmp(tab[n], "F ", 2) && ft_strncmp(tab[n], "C ", 2))
			return (1);
		tmp = ft_getword_simple(tab[n], 3);
		if (!tmp)
			return (2);
		if (n < 4)
		{
			fd = open(tmp, O_RDONLY);
			if (fd < 0)
				return (2);
			close(fd);
		}
		free(tmp);
		n++;
	}
	return (0);
}
