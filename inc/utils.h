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

#include <stddef.h>

/*utils*/

size_t	ft_strlen(char *str);
char	**ft_tabcpy(char **tab);
char	*ft_strdup(char *s1);
int		ft_is_news(char c);

#endif