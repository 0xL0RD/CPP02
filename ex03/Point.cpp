/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:03:11 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/15 16:15:48 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
	return ;
}

Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point(const Point &other) : x(other.x_get), y(Fixed(other.y_get))
{
	return ;
}

Point&	Point::operator=(const Point &other)
{
	this->_x = other.x_get;
	this->_y = other.y_get;
	return (this);
}

Fixed	Point::x_get(void)
{
	return (this->_x);
}

Fixed	Point::y_get(void)
{
	return (this->_y);
}

Point	Point::operator-(const Point &other)
{
	return (Point(this->x_get - other.x_get, this->y_get - other->y_get);
}

/*
Point	operator*(const Point &other)
{
	return (Point(this->x * other.x, this->y * other->y);
}
*/

~Point(void)
{
	return ;
}

