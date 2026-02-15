/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:03:11 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/15 16:13:20 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		Point&	operator=(const Point &other);
		Point	operator-(const Point &other);
		//Point	operator*(const Point &other);
		~Point(void);
		Fixed	x_get(void);
		Fixed	y_get(void);

	private:
		Fixed const	_x;
		Fixed const	_y;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
