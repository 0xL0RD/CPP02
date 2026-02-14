/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/14 14:51:13 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &other);
		Fixed&	operator=(Fixed const &other);

		Fixed&	operator>(Fixed const &other);
		Fixed&	operator<(Fixed const &other);
		Fixed&	operator>=(Fixed const &other);
		Fixed&	operator<=(Fixed const &other);
		Fixed&	operator==(Fixed const &other);
		Fixed&	operator!=(Fixed const &other);

		Fixed&	operator+(Fixed const &other);
		Fixed&	operator-(Fixed const &other);
		Fixed&	operator*(Fixed const &other);
		Fixed&	operator/(Fixed const &other);

		Fixed&	operator++(void);	//pre increment
		Fixed&	operator++(int);	//post increment
		Fixed&	operator--(void);
		Fixed&	operator--(int);

		static Fixed&	min(Fixed &a, Fixed &b);
		static Fixed&	min(Fixed const &a, Fixed const &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static Fixed&	max(Fixed const &a, Fixed const &b);

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
