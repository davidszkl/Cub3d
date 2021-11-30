/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:32:01 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/30 15:32:03 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	**ft_freetab(char **tab)
{
	int	n;

	n = 0;
	while (tab[n])
		free(tab[n++]);
	free(tab);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	const size_t	l = ft_strlen(s1);
	char			*s;

	s = malloc(l + 1);
	if (!s)
		return (0);
	while (*s1)
		*s++ = *s1++;
	*s = 0;
	return (s - l);
}

char	**ft_tabcpy(char **tab)
{
	char	**new;
	size_t	n;

	n = 0;
	while (tab[n])
		n++;
	new = (char **)malloc(sizeof(char *) * (n + 1));
	if (!new)
		return (NULL);
	n = 0;
	while (tab[n])
	{
		new[n] = (char *)malloc(sizeof(char) * (ft_strlen(tab[n]) + 1));
		if (!new[n])
			return (ft_freetab(new));
		new[n] = ft_strdup(tab[n++]);
	}
	new[n] = NULL;
	return (new);
}
