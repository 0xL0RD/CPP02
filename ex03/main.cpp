/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:24:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/16 12:26:03 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>
int main(void)
{
	bool	r;

	r = bsp(Point(1,10), Point(10,10), Point(10, 1), Point (9, 9));
	std::cout << "Is in?: " << r << std::endl;
	r = bsp(Point(1,10), Point(10,10), Point(10, 1), Point (11, 1));
	std::cout << "Is in?: " << r << std::endl;
	r = bsp(Point(1,1), Point(10,10), Point(10, 1), Point (11, 0));
	std::cout << "Is in?: " << r << std::endl;
	return (0);
}
