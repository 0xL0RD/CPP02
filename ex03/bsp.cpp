/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:50:51 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/16 14:59:54 by rubsanch         ###   ########.fr       */
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
		std::cout << "on the line" << std::endl;
		is_inside = false;
	}
	return (is_inside);
}

/*
bool	bsp2(Point const a, Point const b, Point const c, Point const point)
{
	bool	is_inside;
	//float	w1;
	//float	w2;
	Fixed	w1;
	Fixed	w2;
	//Fixed	save_e;
	//Fixed	safe;

	Point d(b -	a);
	Point e(c - a);

	w1 = (
		(
		 e.x_get() * (a.y_get() - point.y_get())
		 + e.y_get() * (point.x_get() - a.x_get())
		)
		/ (d.x_get() * e.y_get() - d.y_get() * e.x_get())
			);
	Fixed safe_e = Fixed(e.y_get());
	if (e.y_get() == 0)
		safe_e.setRawBits(1);
	std::cout << "saveE: " << safe_e.toFloat() << std::endl;
	w2 = (
			(point.y_get() - a.y_get() - Fixed(w1) * d.y_get())
				/ e.y_get()
				/// safe_e
		 );
	std::cout << "p.y: " << point.y_get() << std::endl;
	std::cout << "a.y: " << a.y_get() << std::endl;
	std::cout << "w1: " << w1 << std::endl;
	std::cout << "d.y: " << d.y_get() << std::endl;
	std::cout << "saf.y: " << safe_e << std::endl;
	std::cout << "num: " << (point.y_get() - a.y_get() - Fixed(w1) * d.y_get()) << std::endl;
	std::cout << "den: " << safe_e << std::endl;

	is_inside = false;
	std::cout << "w1: " << w1 << std::endl
		<< "w2: " << w2 << std::endl
		<< "w1+w2: " << w1 + w2 << std::endl;
	if (w1 > 0 && w2 > 0 && w1 + w2 <= 1)
		is_inside = true;
	return (is_inside);
}
*/
