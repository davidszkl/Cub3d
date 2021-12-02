/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:18:54 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/02 13:36:45 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vec2	unit_v2(const t_vec2 v)
{
	const float	x2 = v.x * v.x;
	const float	y2 = v.y * v.y;
	const float	c = sqrtf(x2 + y2);

	return ((t_vec2){x2 / c, y2 / c});
}

t_vec3	unit_v3(const t_vec3 v)
{
	const float	x2 = v.x * v.x;
	const float	y2 = v.y * v.y;
	const float	z2 = v.z * v.z;
	const float	c = sqrtf(x2 + y2 + z2);

	return ((t_vec3){x2 / c, y2 / c, z2 / c});
}

t_vec2	rotate(const t_vec2 v, float alpha)
{
	const float	s = sinf(alpha);
	const float	c = cosf(alpha);

	return ((t_vec2){v.x * c - v.y * s, v.y * c + v.x * s});
}
