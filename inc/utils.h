/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:56:08 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 10:56:09 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

/*includes*/

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*utils*/

size_t	ft_strlen(char *str);
char	**ft_tabcpy(char **tab);
char	*ft_getword_simple(char *str, int n);
char	*ft_strdup(char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_putstr_fd(char *s, int fd);
int		ft_get_gnl_len(char *file);
int		ft_is_empty(char *line);
int		ft_is_news(char c);
int		ft_isspace(char c);
int		ft_isprint(char c);

#endif