/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/14 16:16:53 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/* 
 * Return values:
 * https://en.cppreference.com/w/cpp/language/operator_arithmetic.html
 * https://en.cppreference.com/w/cpp/language/operator_comparison.html
 * https://en.cppreference.com/w/cpp/language/operator_incdec.html
*/

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int nb);
		Fixed(const int nb, bool isRawBytes);
		Fixed(const float nb);
		Fixed(const Fixed &other);
		Fixed&	operator=(Fixed const &other);

		bool	operator>(Fixed const &other) const;
		bool	operator<(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;

		Fixed	operator+(Fixed const &other);
		Fixed	operator-(Fixed const &other);
		Fixed	operator*(Fixed const &other);
		Fixed	operator/(Fixed const &other);

		/*
		Fixed&	operator++(void);	//pre increment
		Fixed	operator++(int);	//post increment
		Fixed&	operator--(void);
		Fixed	operator--(int);
		*/

		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed const&	min(Fixed const &a, Fixed const &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static Fixed const&	max(Fixed const &a, Fixed const &b);

		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fpnb;
		static const int	_binarypoint;
};

//std::ostream&	std::ostream::operator<<(std::ostream &os, Fixed &f);
std::ostream& operator<<(std::ostream &os, Fixed const &input);

#endif
