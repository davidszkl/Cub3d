/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <dszklarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:07:54 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/02 15:27:32 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

/*settings*/

# define SIZE_X 1080
# define SIZE_Y	1920
/*errors*/

# define ID_ERR "Error\nid error: missing / wrong / duplicate id\n"
# define RGB_ERR "Error\nrgb error: wrong rgb values (range 0-255)\n"
# define MAP_ERR "Error\nmap error: missing map\n"
# define MAP1_ERR "Error\nmap error: wrong characters in map\n"
# define MAP3_ERR "Error\nmap error: space not enclosed\n"
# define MAP2_ERR "Error\nmap error: duplicate character token\n"

/*sides convention*/

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

/*includes*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "img.h"

/*structures*/

typedef struct s_fill {
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
	char	**file;		//malloc tab
	char	**params;
	char	**map;
	char	*temp;
	int		a;
}	t_main;

/*parser*/

char	**ft_read_nospace_file(char *tmp, char **new, int count, int fd);
int		ft_file_struct(t_main *main, char *file);
int		ft_check_params(t_main *main, char **tab);
int		ft_check_map(t_main *main);

/*mlx*/

int		ft_mlx_init(t_main *main);
int		ft_keyhook(int keycode, t_main *main);
int		ft_exithook(t_main *main);

/*free*/

void	ft_exit(t_main *main);
int		ft_free_paths(t_main *main, int rval);
int		ft_free_all(t_main *main, int rval);

/*ERASE*/

void	ft_showstate(t_main *main);
void	ft_showtab(char **tab);

#endif
