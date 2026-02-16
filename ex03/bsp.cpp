/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:50:51 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/16 12:44:44 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	is_inside;
	float	w1;
	float	w2;
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
			).toFloat();
	Fixed safe_e = Fixed(e.y_get());
	if (e.y_get() == 0)
		safe_e.setRawBits(1);
	std::cout << "saveE: " << safe_e.toFloat() << std::endl;
	w2 = (
			(point.y_get() - a.y_get() - Fixed(w1) * d.y_get())
				/// e.y_get()
				/ safe_e
		 ).toFloat();
	is_inside = false;
	/*
	std::cout << "w1: " << w1 << std::endl
		<< "w2: " << w2 << std::endl
		<< "w1+w2: " << w1 + w2 << std::endl;
		*/
	if (w1 > 0 && w2 > 0 && w1 + w2 <= 1)
		is_inside = true;
	return (is_inside);
}
