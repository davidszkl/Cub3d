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
#include "free.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	size_t	l = ft_strlen(s1);
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
		new[n] = ft_strdup(tab[n]);
		if (!new[n])
		{
			ft_freetab(new, 0);
			return (NULL);
		}
		n++;
	}
	new[n] = NULL;
	return (new);
}

int	ft_is_news(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}