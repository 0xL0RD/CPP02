/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/14 19:44:16 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_binarypoint = 8;

Fixed::Fixed(void) : _fpnb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nb << _binarypoint);
}

Fixed::Fixed(const int nb, const bool isRawBytes)
{
	std::cout << "Int (isRawBytes) constructor called" << std::endl;
	if (isRawBytes == false)
		this->setRawBits(nb << _binarypoint);
	else
		this->setRawBits(nb);
}

Fixed::Fixed(const float nb)
{
	int	r;

	std::cout << "Float constructor called" << std::endl;
	r = (int) roundf(nb * (1 << _binarypoint));
	this->setRawBits(r);
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
	return ;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fpnb = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &other) const
{
	std::cout << "> operator called" << std::endl;
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(Fixed const &other) const
{
	std::cout << "< operator called" << std::endl;
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(Fixed const &other) const
{
	std::cout << ">= operator called" << std::endl;
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const &other) const
{
	std::cout << "<= operator called" << std::endl;
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(Fixed const &other) const
{
	std::cout << "== operator called" << std::endl;
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(Fixed const &other) const
{
	std::cout << "!= operator called" << std::endl;
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other)
{
	std::cout << "+ operator called" << std::endl;
	return (Fixed(this->getRawBits() + other.getRawBits(), true));
}

Fixed Fixed::operator-(Fixed const &other)
{
	std::cout << "- operator called" << std::endl;
	return (Fixed(this->getRawBits() - other.getRawBits(), true));
}

Fixed Fixed::operator*(Fixed const &other)
{
	std::cout << "* operator called" << std::endl;
	return (Fixed(
				(this->getRawBits() * other.getRawBits()) >> this->_binarypoint,
				true));
}

Fixed Fixed::operator/(Fixed const &other)
{
	std::cout << "/ operator called" << std::endl;
	return (Fixed(
				(this->getRawBits() << _binarypoint) / other.getRawBits(),
				true));
}

Fixed& Fixed::operator++(void)	//pre increment
{
	std::cout << "++(pre) operator called" << std::endl;
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)	//post increment
{
	int	tmp;

	std::cout << "++(post) operator called" << std::endl;
	tmp = this->getRawBits();
	this->setRawBits(this->getRawBits() + 1);
	return (Fixed(tmp, true));
}

Fixed& Fixed::operator--(void)
{
	std::cout << "--(pre) operator called" << std::endl;
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	int	tmp;

	std::cout << "--(post) operator called" << std::endl;
	tmp = this->getRawBits();
	this->setRawBits(this->getRawBits() - 1);
	return (Fixed(tmp, true));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&		Fixed::min(Fixed &a, Fixed &b)
{
	std::cout << "MIN (no const) operator called" << std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
	std::cout << "MIN (const) operator called" << std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed&		Fixed::max(Fixed &a, Fixed &b)
{
	std::cout << "MAX (no const) operator called" << std::endl;
	if (a > b)
		return (a);
	return (b);
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
	std::cout << "MAX (const) operator called" << std::endl;
	if (a > b)
		return (a);
	return (b);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
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
