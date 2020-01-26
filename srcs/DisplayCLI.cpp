/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 01:28:32 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayCLI.hpp"
#include "IMonitorDisplay.hpp"
#include <iostream>
#include <ncurses.h>

/*
**	Constructors
*/

DisplayCLI::DisplayCLI(void)
{
	std::cout << "DisplayCLI: default construct called" << std::endl;
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

DisplayCLI		&DisplayCLI::operator=(const DisplayCLI &other)
{
	std::cout << "DisplayCLI: operator= overloader called" << std::endl;
	(void)other;
	return (*this);
}

/*
**	Other Member Functions
*/

void			DisplayCLI::display_border(std::string title, WINDOW *win) const
{
	box(win, 0, 0);
	wrefresh(win);
	wmove(win, 0, 2);
	wprintw(win, " %s ", title.c_str());
	wrefresh(win);
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

void			DisplayCLI::display_line(std::string title) const
{
	std::cout << title << std::endl;
}

void			DisplayCLI::display_line_2(std::string title, std::string info) const
{
	std::cout << title << "	" << info << std::endl;
}
