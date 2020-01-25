/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:32 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 06:55:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include <iostream>

/*
**	Constructors
*/

IMonitorDisplay::IMonitorDisplay(void)
{
	std::cout << "IMonitorDisplay: Default constructor called" << std::endl;
	_show_border = true;
	_show_title = true;
	_color = 0;
}

IMonitorDisplay::IMonitorDisplay(const IMonitorDisplay &other)
{
	std::cout << "IMonitorDisplay: Copy constructor called" << std::endl;
	*this = other;
}

/*
**	Destructor
*/

IMonitorDisplay::~IMonitorDisplay(void)
{
	std::cout << "IMonitorDisplay: Destructor called" << std::endl;
}

/*
**	Operator Overloaders
*/

IMonitorDisplay		&IMonitorDisplay::operator=(const IMonitorDisplay &other)
{
	std::cout << "IMonitorDisplay: = operator overloader called" << std::endl;
	(void)other;
	return (*this);
}

/*
**	Other Member Functions
*/
