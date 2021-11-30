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
#include <stdio.h>

static int	ft_algo_check(char **tab)
{
	char	**cpy;
	size_t	n;
	size_t	j;

	cpy = ft_tabcpy(tab);
	n = 0;
	while (tab[n])
	{
		j = 0;
		while (tab[n][j])
		{
			if (!n || !tab[n + 1] || !j || j == ft_strlen(tab[n]))
				cpy[n][j] = 0;
			if (tab[n - 1][j] == ' ' || tab[n][j - 1] || !tab[n + 1][j]
				|| !tab[n][j + 1])
			j++;
		}
		n++;
	}
}

static int	ft_check_close(char **tab)
{
	int	true;

	true = 1;
	while (true)
		true = ft_algo_check(tab);
	return (0);
}

int	main()
{
	int n = 0;
	char **tab = (char *[]){"   111       \n",
							"   1.1       \n",
							"   1111111   \n",
							"   1..1...1  \n",
							"  1.......1  \n",
							"  1.......1  \n",
							"  1.......1  \n",
							"  1.......1  \n",
							"   1111111   \n",
							"             \n",
							0};
	printf("%d\n", ft_check_close(tab));
	return (0);
}