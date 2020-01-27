/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 16:33:34 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayCLI.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
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

	initscr();					// ncurses: setup alt screen
	curs_set(FALSE);			// ncurses: hide cursor
	cbreak();					// ncurses: set noncanonical mode
	noecho();					// ncurses: disable echoing
	keypad(stdscr, TRUE);		// ncurses: enable ability to capture multibyte characters
	nodelay(stdscr, TRUE);		// ncurses: make the getch() function not wait for a character before returning
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

	endwin();			// ncurses: screen destructed
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

void			DisplayCLI::display_border(std::string title) const
{
	unsigned int		cur_height;
	unsigned int		cur_width;

	wmove(_cur_win, 0, 0);
	wrefresh(_cur_win);

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_CYAN);
	whline(_cur_win, 0, 80);
	wrefresh(_cur_win);
	wmove(_cur_win, 0, 2);
	wrefresh(_cur_win);
	wprintw(_cur_win, " %s ", title.c_str());
	wrefresh(_cur_win);

	getyx(_cur_win, cur_height, cur_width);
	wmove(_cur_win, cur_height + 2, 3);
	wrefresh(_cur_win);
}

void			DisplayCLI::display_graph(std::string title, int info[]) const

{
	unsigned int		cur_height;
	unsigned int		cur_width;

	(void)info;
	wprintw(_cur_win, "%s graph here", title.c_str());
	wrefresh(_cur_win);

	getyx(_cur_win, cur_height, cur_width);
	wmove(_cur_win, cur_height + 1, 3);
	wrefresh(_cur_win);
}

void			DisplayCLI::display_bar(std::string title, unsigned int percentage) const
{
	unsigned int		cur_height;
	unsigned int		cur_width;

	wprintw(_cur_win, "%s %d%%", title.c_str(), percentage);
	wrefresh(_cur_win);

	getyx(_cur_win, cur_height, cur_width);
	wmove(_cur_win, cur_height + 1, 3);
	wrefresh(_cur_win);
}

void			DisplayCLI::display_line(std::string title) const
{
	unsigned int		cur_height;
	unsigned int		cur_width;

	wprintw(_cur_win, "%s", title.c_str());
	wrefresh(_cur_win);

	getyx(_cur_win, cur_height, cur_width);
	wmove(_cur_win, cur_height + 1, 3);
	wrefresh(_cur_win);
}

void			DisplayCLI::display_line_2(std::string title, std::string info) const
{
	unsigned int		cur_height;
	unsigned int		cur_width;

	wprintw(_cur_win, "%s %s", title.c_str(), info.c_str());
	wrefresh(_cur_win);

	getyx(_cur_win, cur_height, cur_width);
	wmove(_cur_win, cur_height + 1, 3);
	wrefresh(_cur_win);
}


void			DisplayCLI::display(std::vector<WINDOW*> windows, std::vector<IMonitorModule*>modules)
{
	std::vector<IMonitorModule*>::const_iterator	it;
	std::vector<IMonitorModule*>::const_iterator	ite = modules.end();
	std::vector<WINDOW*>::const_iterator			wit = windows.begin();

	for (it = modules.begin(); it != ite; it++)
	{
		_cur_win = *wit;
		display_border((*it)->getMName());
		(*it)->execute(this);
		++wit;
	}
}

std::vector<WINDOW*>		DisplayCLI::make_windows(unsigned int nmodules)
{
	std::vector<WINDOW*>	windows;
	unsigned int			win_height;
	unsigned int			win_width;
	unsigned int			mod_win_width = 80;
	unsigned int			mod_win_height;
	unsigned int			new_start;

	getmaxyx(stdscr, win_height, win_width);
	mod_win_height = (win_height / nmodules) - PADDING;
//	if (mod_win_height < 5)
//		error
	new_start = 1;
	for (unsigned int i = 0; i < nmodules; i++)
	{
		windows.push_back(newwin(mod_win_height, mod_win_width, new_start, 1));
		new_start = new_start + mod_win_height + PADDING;
	}
	return (windows);
}

void			DisplayCLI::manage_display(std::vector<IMonitorModule*> modules)
{
	std::vector<WINDOW*>	windows = make_windows(modules.size());

	while (1)
	{
		display(windows, modules);
		sleep(1);
	}
}
