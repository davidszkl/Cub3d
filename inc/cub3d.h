/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <dszklarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:07:54 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 11:49:21 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H
# define PATH_ERR "Error\nunvalid path: could not be opened\n"
# define ID_ERR "Error\nidentifier error: missing or wrong id\n"
# define MAP1_ERR "Error\nmap error: wrong characters in map\n"
# define MAP2_ERR "Error\nmap error: space not enclosed\n"

/*includes*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*structures*/

typedef struct s_img {
	void	*img;
	char	*path;
}	t_img;

typedef struct s_main {
	t_img	*north;
	t_img	*south;
	t_img	*east;
	t_img	*west;
	void	*mlx;
	void	*win;
	char	**file;
	char	**params;
	char	**map;
	char	*temp;
	int		tmp_int;
}	t_main;

/*functions*/

int		ft_file_struct(t_main *main, char *file);
int		ft_check_params(char **tab);
int		ft_check_map(char **tab);

/*ERASE*/

void	ft_showtab(char **tab);
#endif
