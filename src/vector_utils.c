/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:18:54 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/07 11:14:56 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vec2	unit(const t_vec2 v)
{
	const float	x2 = v.x * v.x;
	const float	y2 = v.y * v.y;
	const float	c = sqrtf(x2 + y2);

	return ((t_vec2){v.x / c, v.y / c});
}

t_vec2	rotate(const t_vec2 v, float alpha)
{
	const float	s = sinf(alpha);
	const float	c = cosf(alpha);

	return ((t_vec2){v.x * c - v.y * s, v.y * c + v.x * s});
}
