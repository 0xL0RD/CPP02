/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/16 12:44:25 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_binarypoint = 8;

Fixed::Fixed(void) : _fpnb(0)
{
	return ;
}

Fixed::Fixed(const int nb)
{
	this->setRawBits(nb << _binarypoint);
}

Fixed::Fixed(const int nb, const bool isRawBytes)
{
	if (isRawBytes == false)
		this->setRawBits(nb << _binarypoint);
	else
		this->setRawBits(nb);
}

Fixed::Fixed(const float nb)
{
	int	r;

	r = (int) roundf(nb * (1 << _binarypoint));
	this->setRawBits(r);
}

Fixed::Fixed(Fixed const &other)
{
	this->setRawBits(other.getRawBits());
	return ;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fpnb = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(Fixed const &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(Fixed const &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other)
{
	return (Fixed(this->getRawBits() + other.getRawBits(), true));
}

Fixed Fixed::operator-(Fixed const &other)
{
	return (Fixed(this->getRawBits() - other.getRawBits(), true));
}

Fixed Fixed::operator*(Fixed const &other)
{
	return (Fixed(
				(this->getRawBits() * other.getRawBits()) >> this->_binarypoint,
				true));
}

Fixed Fixed::operator/(Fixed const &other)
{
	//std::cout << "this : " << this->toInt() << std::endl;
	//std::cout << "other: " << other.toInt() << std::endl;
	return (Fixed(
				(this->getRawBits() << _binarypoint) / other.getRawBits(),
				true));
}

Fixed& Fixed::operator++(void)	//pre increment
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)	//post increment
{
	int	tmp;

	tmp = this->getRawBits();
	this->setRawBits(this->getRawBits() + 1);
	return (Fixed(tmp, true));
}

Fixed& Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	int	tmp;

	tmp = this->getRawBits();
	this->setRawBits(this->getRawBits() - 1);
	return (Fixed(tmp, true));
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed&		Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&		Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fpnb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpnb = raw;
}

float	Fixed::toFloat(void) const
{
	float	r;

	r = (float) this->getRawBits() / (1 << _binarypoint);
	return (r);
}

int		Fixed::toInt(void) const
{
	int	r;

	r = this->getRawBits() >> this->_binarypoint;
	return (r);
}

std::ostream& operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}
