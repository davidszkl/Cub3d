/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:19:32 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 10:19:34 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_myfree(void	*ptr, int rval)
{
	free(ptr);
	return (rval);
}

int	ft_freetab(char	**tab, int rval)
{
	int	n;

	n = 0;
	while (tab[n])
		free(tab[n++]);
	free(tab);
	return (rval);
}
