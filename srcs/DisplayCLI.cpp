/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 07:03:05 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayCLI.hpp"
#include "IMonitorDisplay.hpp"
#include <iostream>
#include <curses.h>

/*
**	Constructors
*/

DisplayCLI::DisplayCLI(void)
{
	std::cout << "DisplayCLI: default construct called" << std::endl;
	_show_border = true;
	_show_title = true;
	_color = 0;
}

DisplayCLI::DisplayCLI(const DisplayCLI &other)
{
	std::cout << "DisplayCLI: copy construct called" << std::endl;
	*this = other;
}

/*
**	Destructor
*/

DisplayCLI::~DisplayCLI(void)
{
	std::cout << "DisplayCLI: default destructor called" << std::endl;
}

/*
**	Operator Overloaders
*/

DisplayCLI		&DisplayCLI::DisplayCLI::operator=(const DisplayCLI &other)
{
	std::cout << "DisplayCLI: operator= overloader called" << std::endl;
	_show_border = other.get_show_border();
	_show_title = other.get_show_title();
	_color = other.get_color();
	return (*this);
}

/*
**	Other Member Functions
*/
bool			DisplayCLI::get_show_border(void) const
{
	return (_show_border);
}

bool			DisplayCLI::get_show_title(void) const
{
	return (_show_title);
}

int				DisplayCLI::get_color(void) const
{
	return (_color);
}

void			DisplayCLI::set_show_border(bool new_show_border)
{
	_show_border = new_show_border;
}

void			DisplayCLI::set_show_title(bool new_show_title)
{
	_show_title = new_show_title;
}

void			DisplayCLI::set_color(int new_color)
{
	_color = new_color;
}

void			DisplayCLI::display_border(WINDOW *win) const
{
	box(win, 0, 0);
}

void			DisplayCLI::display_graph(std::string title, int info[]) const
{
	(void)info;
	std::cout << title << "graph here" << std::endl;
}

void			DisplayCLI::display_bar(std::string title, unsigned int percentage) const
{
	std::cout << title << "	" << percentage << " %" << std::endl;
}

void			DisplayCLI::display_info(std::string info) const
{
	std::cout << info << std::endl;
}

void			DisplayCLI::display_info_2_part(std::string info, std::string secondary_info) const
{
	std::cout << info << "	" << secondary_info << std::endl;
}
