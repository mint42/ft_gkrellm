/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleManager.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:42:12 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 01:51:09 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleManager.hpp"
#include <iostream>

/*
**	Constructors
*/

ModuleManager::ModuleManager(void)
{
	std::cout << "ModuleManager: Default constructor called" << std::endl;
}

ModuleManager(list<std::string> names)
{
	std::cout << "ModuleManager: Parameterized constructor called" << std::endl;

	_module_names = names;
	_nmodules = names.size();
	_min_width = 0;
	_min_height = 0;
}

ModuleManager::ModuleManager(const ModuleManager &other)
{
	std::cout << "ModuleManager: Copy constructor called" << std::endl;

	*this = other;
}

/*
**	Destructor
*/

ModuleManager::~ModuleManager(void)
{
	std::cout << "ModuleManager: Destructor called" << std::endl;
}

/*
**	Operator Overloaders
*/

ModuleManager		&ModuleManager::operator=(const ModuleManager &other)
{
	std::cout << "ModuleManager: = operator overloader called" << std::endl;

	_module_names = other.get_names();
	_nmodules = other.get_nmodules();
	_min_width = other.get_min_width();
	_min_height = other.get_min_height();
	return (*this);
}

/*
**	Other Member Functions
*/

list<std::string>	get_module_names() const
{
	return (_module_names);
}

unsigned int		get_nmodules() const;
{
	return (_module_names);
}

unsigned int		get_min_width() const
{
	return (_min_width);
}

unsigned int		get_min_height() const;
{
	return (_min_height);
}

void				set_module_names(list<std::string> names);
{
	_module_names = names;
}

void				set_nmodules(unsigned int n);
{
	_nmodules = n;
}

void				set_min_width(unsigned int n);
{
	_min_width = n;
}

void				set_min_height(unsigned int n);
{
	_min_height = n;
}

