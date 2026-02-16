/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/16 16:43:21 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>
int main(void)
{
	bool	r;

	r = bsp(Point(1,10), Point(10,10), Point(10, 1), Point (9, 9));
	std::cout << "1) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,10), Point(10,10), Point(10, 1), Point (9, 8));
	std::cout << "2) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,1), Point(10,10), Point(10, 1), Point (9, 5));
	std::cout << "3) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,1), Point(10,10), Point(10, 1), Point (9, 2));
	std::cout << "4) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,1), Point(100,100), Point(100, 1), Point (90, 2));
	std::cout << "5) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,10), Point(10,10), Point(10, 1), Point (11, 1));
	std::cout << "6) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,1), Point(10,10), Point(10, 1), Point (11, 0));
	std::cout << "7) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,1), Point(10,10), Point(10, 1), Point (0, 0));
	std::cout << "8) Is in?: " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,1), Point(10,10), Point(10, 1), Point (5, 1));
	std::cout << "9) Is in? (on the line): " << r << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	r = bsp(Point(1,1), Point(10,10), Point(10, 1), Point (10, 3));
	std::cout << "10) Is in? (on the line): " << r << std::endl;
	return (0);
}
