/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:50:51 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/16 16:42:39 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	bs_triangle_area(Point const a, Point const b, Point const c)
{
	Point	AB(b.x_get() - a.x_get(), b.y_get() - a.y_get());
	Point	AC(c.x_get() - a.x_get(), c.y_get() - a.y_get());
	Fixed	cp(AB.x_get() * AC.y_get() - AB.y_get() * AC.y_get());
	Fixed	crossproduct(AB.x_get() * AC.y_get() - AB.y_get() * AC.x_get());
	if (crossproduct < 0)
		return (crossproduct / 2 * -1);
	return (crossproduct / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	is_inside;

	Fixed ABP_area (bs_triangle_area(a, b, point));
	Fixed ACP_area (bs_triangle_area(a, c, point));
	Fixed BCP_area (bs_triangle_area(b, c, point));
	Fixed ABC_area (bs_triangle_area(a, b, c));
	is_inside = false;
	if (ABP_area + ACP_area + BCP_area <= ABC_area)
		is_inside = true;
	if (ABC_area == 0 || ACP_area == 0 || BCP_area == 0)
	{
		is_inside = false;
	}
	return (is_inside);
}
