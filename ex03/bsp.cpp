/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:50:51 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/15 13:15:37 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed tr_area(Point const a, Point const b, Point const c)
{
	Fixed	triangle_area;

	/*
	 *   .C
	 *
	 *   .A
	 *             .B
	 */  
	/*
	 *   .C
	 *
	 *   .A        .B
	 */  
	/*
	 *          .C
	 *
	 *   .A
	 *             .B
	 */
	/*
	 *   .A(1,1)            (1,1)
	 *                      
	 *   .B        .C                            cy-ay,cx-bx
	 *     (1,3)     (11,3)             (11,3)   11-1, 3-1 = 10, 2 = 10*2/2 = 10
	 */  
	/*
	 *    D       .B
	 *        /           .P
	 *   w1 /
	 *  A. ______  .C
	 *      w2
	 *        E
	 */

	/*
	triangle_area = 1/2 * (
				  (b.y - a.y)      //TODO: this is wrong for not square triangles
				* (c.x - b.x)
			);
			*/
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	is_inside;
	Point	d;
	Point	e;
	float	w1;
	float	w2;

	d = b - a;
	e = c - a;

	w1 = (e.x * (a.y - p.y) + e.y * (p.x - a.x)) / (d.x * e.y - d.y * e.x);
	w2 = (p.y - a.y - w1 * d.y) / e.y;
	return (is_inside);
}
