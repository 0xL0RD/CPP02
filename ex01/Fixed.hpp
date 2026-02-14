/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/14 19:16:56 by rubsanch         ###   ########.fr       */
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
		Fixed&	operator=(const Fixed &other);
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
