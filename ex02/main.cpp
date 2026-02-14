/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/14 18:13:19 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
int main(void)
{
	Fixed a;

	std::cout << "------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "sum (double): " << std::endl;
	std::cout << a + a << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "subtract (zero): " << std::endl;
	std::cout << a - a << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "b (multiplication): " << std::endl;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	{
		Fixed const b( Fixed( 5 ) * Fixed( 2 ) );
		std::cout << b << std::endl;
	}
	std::cout << "------------" << std::endl;
	std::cout << "b (div): " << std::endl;
	Fixed const b( Fixed( 5 ) / Fixed( 2 ));
	std::cout << b << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "max (a, b): " << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
