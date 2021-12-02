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
# define ID_ERR "Error\nid error: missing / wrong / duplicate id\n"
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
	char	*path;		//malloc
	int		line;
}	t_img;

typedef struct s_fill {
	char	*rgb;		//malloc
	int		line;
	int		rgb1[3];
}	t_fill;

typedef struct s_main {
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_fill	floor;
	t_fill	ceilling;
	void	*mlx;
	void	*win;
	char	**file;		//malloc
	char	**params;	//malloc
	char	**map;		//malloc
	char	*temp;
	int		a;
}	t_main;

/*functions*/

int		ft_file_struct(t_main *main, char *file);
int		ft_check_params(t_main *main, char **tab);
int		ft_check_map(char **tab);

/*ERASE*/

void	ft_showtab(char **tab);
#endif
