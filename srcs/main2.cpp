/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:39:56 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 07:28:36 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "IMonitorDisplay.hpp"
#include "../includes/Mdate.hpp"
#include "../includes/Mhu.hpp"
#include "../includes/Mos.hpp"
#include "../includes/Mcpu.hpp"
#include "../includes/Mram.hpp"
//#include "DisplayCLI.hpp"
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
// #include <exception>
// #include <curses.h>

// modules
#define NAMES "Names"
#define OSINFO "OS info"

#define USAGE "./ft_gkrellm [--cli/--gui] [modules]"

// only turning it into a list because i assume it will be parsing a config soon
// but for now it can just take cl args

/*
**	static std::list<std::string>		parse_input(int argc, char **argv)
**	{
**		std::list<std::string>	modules;
**
**		modules.push_back(NAMES);
**		modules.push_back(OSINFO);
**		return (modules);
**	}
*/

/*
**	static void						manage(list<std::string> modules)
**	{
**		ModuleManager	manager(modules);
**
**		while (42)
**		{
**
**		}
**	}
*/

int								main(void)
{
//	std::list<std::string>	modules;
//	IMonitorDisplay			*mode;
//	DisplayCLI				cli_mode;

	/* ncurses */

//	initscr();							// setup alt screen
//	curs_set(FALSE);					// hide cursor
//	cbreak();							// set noncanonical mode
//	noecho();							// disable echoing
//	keypad(stdscr, TRUE);				// enable ability to capture multibyte characters
//	nodelay(stdscr, TRUE);				// make the getch() function not wait for a character before returning
//	mode = &cli_mode;
//	mode->display_border("Test", stdscr);
//	while (1)
//	{

//	}

//	modules = parse_input(argc, argv);
//	manage_program(modules, display);

//	endwin();
	Mdate d;
	Mhu hu;
	Mos os;
	Mcpu cpu;
	Mram ram;
	d.execute();
	hu.execute();
	os.execute();
	cpu.execute();
	ram.execute();
	return (0);
}
