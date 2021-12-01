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

/*includes*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*structures*/

typedef struct s_main {
	void	*mlx;
	void	*window;
	char	**file;
	char	**params;
	char	**map;
	char	*temp;
	
}	t_main;

/*functions*/

int	ft_read_file(t_main *main, char	*file);
int	ft_check_params(char **tab);
int	ft_check_map(char **tab);


/*ERASE*/

void	ft_showtab(char **tab);
#endif
