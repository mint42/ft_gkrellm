/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 07:08:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayCLI.hpp"
#include "IMonitorDisplay.hpp"
#include <vector>
#include <iostream>
#include <unistd.h>
#include <curses.h>

/*
**	Constructors
*/

#define PADDING 1

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

void			DisplayCLI::display_border(WINDOW *win, std::string title) const
{
	box(win, 0, 0);
	wrefresh(win);
	wmove(win, 0, 2);
	wprintw(win, " %s ", title.c_str());
	wrefresh(win);
}

void			DisplayCLI::display_graph(WINDOW *win, std::string title, int info[]) const

{
	(void)info;
	wprintw(win, "%s graph here", title.c_str());
	wrefresh(win);
}

void			DisplayCLI::display_bar(WINDOW *win, std::string title, unsigned int percentage) const
{
	wprintw(win, "%s %d%%", title.c_str(), percentage);
	wrefresh(win);
}

void			DisplayCLI::display_line(WINDOW *win, std::string title) const
{
	wprintw(win, "%s", title.c_str());
	wrefresh(win);
}

void			DisplayCLI::display_line_2(WINDOW *win, std::string title, std::string info) const
{
	wprintw(win, "%s %s", title.c_str(), info.c_str());
	wrefresh(win);
}


void			DisplayCLI::display(std::vector<WINDOW*> windows, std::list<std::string>modules)
{
	std::list<std::string>::const_iterator	it;
	std::list<std::string>::const_iterator	ite = modules.end();
	std::vector<WINDOW*>::const_iterator	wit;

	wit = windows.begin();
	for (it = modules.begin() ; it != ite; it++)
	{
		display_border(*wit, *it);
		++wit;
	}
}

std::vector<WINDOW*>		DisplayCLI::make_windows(unsigned int nmodules)
{
	std::vector<WINDOW*>	windows;
	unsigned int			win_height;
	unsigned int			win_width;
	unsigned int			mod_win_width = 25;
	unsigned int			mod_win_height;
	unsigned int			new_start;

	getmaxyx(stdscr, win_height, win_width);
	mod_win_height = win_height / (nmodules + PADDING);
//	if (mod_win_height < 5)
//		t;
	new_start = 1;
	for (unsigned int i = 0; i < nmodules; i++)
	{
		windows.push_back(newwin(mod_win_height, mod_win_width, new_start, 1));
		new_start = new_start + mod_win_height;
	}
	return (windows);
}

void			DisplayCLI::manage_display(std::list<std::string> modules)
{
	std::vector<WINDOW*>	windows = make_windows(modules.size());

	while (1)
	{
		display(windows, modules);
		sleep(5);
	}
}
