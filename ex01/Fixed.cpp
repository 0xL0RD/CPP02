/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/14 13:09:50 by rubsanch         ###   ########.fr       */
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

Fixed::Fixed(const float nb)
{
	int	r;

	std::cout << "Float constructor called" << std::endl;
	r = nb * (1 << _binarypoint);
	this->setRawBits(r);
}

Fixed::Fixed(Fixed const &other) : _fpnb(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
	//this->_fpnb = other.getRawBits(); //If you wan exact order from example
	return ;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//this->_fpnb = other.getRawBits();
	this->_fpnb = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
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
	int	r;

	r = this->getRawBits() / (1 << _binarypoint); //TODO: no idea
	return ((float) r);
}

int		Fixed::toInt(void) const
{
	int	r;

	r = this->getRawBits() >> _fpnb;
	return (r);
}

//std::ostream&	std::ostream::operator<<(std::ostream &os, Fixed &f)
//std::ostream&	operator<<(std::ostream &os, Fixed &f)
std::ostream & operator<<(std::ostream & os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}
