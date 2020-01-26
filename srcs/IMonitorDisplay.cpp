/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:32 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 01:39:33 by rreedy           ###   ########.fr       */
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

	initscr();					// ncurses: setup alt screen
	curs_set(FALSE);			// ncurses: hide cursor
	cbreak();					// ncurses: set noncanonical mode
	noecho();					// ncurses: disable echoing
	keypad(stdscr, TRUE);		// ncurses: enable ability to capture multibyte characters
	nodelay(stdscr, TRUE);		// ncurses: make the getch() function not wait for a character before returning
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

	endwin();			// ncurses: screen destructed
}

/*
**	Operator Overloaders
*/

IMonitorDisplay		&IMonitorDisplay::operator=(const IMonitorDisplay &other)
{
	std::cout << "IMonitorDisplay: = operator overloader called" << std::endl;
	_show_border = other.get_show_border();
	_show_title = other.get_show_title();
	_color = other.get_color();
	return (*this);
}

/*
**	Other Member Functions
*/

bool			IMonitorDisplay::get_show_border(void) const
{
	return (_show_border);
}

bool			IMonitorDisplay::get_show_title(void) const
{
	return (_show_title);
}

int				IMonitorDisplay::get_color(void) const
{
	return (_color);
}

void			IMonitorDisplay::set_show_border(bool new_show_border)
{
	_show_border = new_show_border;
}

void			IMonitorDisplay::set_show_title(bool new_show_title)
{
	_show_title = new_show_title;
}

void			IMonitorDisplay::set_color(int new_color)
{
	_color = new_color;
}
