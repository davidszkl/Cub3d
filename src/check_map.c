/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:25:41 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/30 09:25:43 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "free.h"
#include "cub3d.h"

//newline in the middle of map
//chars other than 1, 0, space, N, W, E, S
//multiple N, W, E, S

static int	ft_map_check(char **tab)
{
	size_t	n;
	size_t	j;
	size_t	count;

	n = 0;
	count = 0;
	while (tab[n])
	{
		j = 0;
		while (tab[n][j])
		{
			if (tab[n][j] == '\n' && j < ft_strlen(tab[n]))
				return (1);
			if (!ft_is_news(tab[n][j]) && tab[n][j] != '1' && tab[n][j] != '0')
				return (1);
			if (ft_is_news(tab[n][j] && count++ > 0))
				return (1);
			j++;
		}
		n++;
	}
	return (0);
}

// if not on space continue
// if border -> X
// if u,d,l,r is X -> X

static int	ft_algo_check(char **tab, char **cpy)
{
	size_t	n;
	size_t	j;
	int		rval;

	n = 0;
	rval = 0;
	while (tab[n])
	{
		j = 0;
		while (tab[n][j])
		{
			if (((tab[n][j] != '.' && tab[n][j] != '0')
				|| cpy[n][j] == 'X') && j++ >= 0)
				continue ;
			if ((!n || !tab[n + 1] || !j || j == ft_strlen(tab[n])) && ++rval)				
				cpy[n][j] = 'X';
			else if ((cpy[n - 1][j] == 'X' || cpy[n][j - 1] == 'X'
				|| cpy[n + 1][j] == 'X' || cpy[n][j + 1] == 'X') && ++rval)
				cpy[n][j] = 'X';
			j++;
		}
		n++;
	}
	return (rval);
}

static int	ft_check_close(char **tab)
{
	char	**cpy;
	int		change;
	int		n;
	int		j;
	
	cpy = ft_tabcpy(tab);
	if (!cpy)
		return (1);
	change = 1;
	n = -1;
	while (change)
		change = ft_algo_check(tab, cpy);
	while (tab[++n])
	{
		j = -1;
		while (tab[n][++j])
		{
			if ((tab[n][j] == '0' || ft_is_news(tab[n][j])) && cpy[n][j] == 'X')
				return (ft_myfree(cpy, 1));
			if (tab[n][j] == ' ' && cpy[n][j] != 'X')
				tab[n][j] = '0';
		}
	}
	free(cpy);
	return (0);
} 

int	ft_check_map(char **tab)
{
	if (ft_map_check(tab))
		return (1);
	if (ft_check_close(tab))
		return (1);
	return (0);
}