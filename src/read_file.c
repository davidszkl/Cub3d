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
#include "utils.h"
#include "free.h"
#include "get_next_line.h"

//get map from main->file

static char	**ft_get_map(char **tab)
{
	size_t	count;
	int		n;
	char	**new;

	count = 0;
	n = -1;
	while (tab[++n] && count++ < 6)
		while (tab[n] && ft_is_empty(tab[n]))
			n++;
	while (tab[n] && ft_is_empty(tab[n]))
		n++;
	if (!tab[n])
		return (NULL);
	count = n;
	while (tab[n])
		n++;
	new = (char **)malloc(sizeof(char *) * (n - count + 1));
	if (!new)
		return (NULL);
	n = 0;
	while (tab[count])
		new[n++] = tab[count++];
	new[n] = NULL;
	return (new);
}

//get_params from main->file into params

static char	**ft_get_params(char **file)
{
	size_t	count;
	size_t	newcount;
	char	**new;

	count = 0;
	newcount = 0;
	new = malloc(sizeof(char *) * 7);
	if (!new)
		return (NULL);
	while (file[count] && newcount < 6)
	{
		while (ft_is_empty(file[count]))
			count++;
		new[newcount++] = file[count++];
	}
	new[newcount] = NULL;
	return (new);
}

// read file to main->file

static char	**ft_read_file(char *file_name)
{
	int		count;
	char	**new;
	int		fd;

	count = ft_get_gnl_len(file_name);
	if (count == -1)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	count = 0;
	new[count] = get_next_line(fd);
	while (new[count] && count++ >= 0)
		new[count] = get_next_line(fd);
	new[count + 1] = NULL;
	return (new);
}

// second part for norm

static int	ft_file_struct1(t_main *main)
{
	int	rval;

	rval = ft_check_map(main->map);
	if (rval)
	{
		if (rval == 1)
			ft_putstr_fd(MAP1_ERR, 2);
		else if (rval == 2)
			ft_putstr_fd(MAP2_ERR, 2);
		free(main->file);
		free(main->params);
		free(main->map);
		return (1);
	}
	free(main->file);
	return (0);
}

// read file to main->file, get param, check param, get map, check map

int	ft_file_struct(t_main *main, char *file)
{
	main->file = ft_read_file(file);
	if (!main->file)
		return (1);
	main->params = ft_get_params(main->file);
	if (!main->params)
		return (ft_myfree(main->file, 1));
	main->a = ft_check_params(main, main->params);
	if (main->a)
	{
		if (main->a == 2)
			perror(file);
		free(main->file);
		return (ft_myfree(main->params, 1));
	}
	main->map = ft_get_map(main->file);
	if (!main->map)
	{
		free(main->file);
		return (ft_myfree(main->params, 1));
	}
	if (ft_file_struct1(main))
		return (1);
	return (0);
}
