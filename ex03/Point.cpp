/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:03:11 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/16 12:13:25 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
	return ;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::Point(const Point &other) : _x(other.x_get()), _y(Fixed(other.y_get()))
{
	return ;
}

Point&	Point::operator=(const Point &other)
{
	(void) other;
	return (*this);
}

Fixed	Point::x_get(void) const
{
	return (this->_x);
}

Fixed	Point::y_get(void) const
{
	return (this->_y);
}

Point	Point::operator-(const Point &other) const
{
	return (Point(
				(this->x_get() - other.x_get()).toFloat(),
				(this->y_get() - other.y_get()).toFloat()
				));
}

Point::~Point(void)
{
	return ;
}

