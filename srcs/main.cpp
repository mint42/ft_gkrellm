/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:39:56 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 07:11:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include "DisplayCLI.hpp"
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ncurses.h>
#include <curses.h>

// modules
#define NAMES "Names"
#define OSINFO "OS info"

#define USAGE "./ft_gkrellm [--cli/--gui] [modules]"

static std::list<std::string>		parse_input(int argc, char **argv)
{
	std::list<std::string>	modules;

	if (argc <= 1)
		throw (std::string(USAGE));
	for (int i = 1; i < argc; i++)
	{
		modules.push_back(std::string(argv[i]));
	}
	return (modules);
}

static void						run(std::list<std::string> modules)
{
	IMonitorDisplay			*display_mode = new DisplayCLI();

	display_mode->manage_display(modules);
}

int								main(int argc, char **argv)
{
	std::list<std::string>	modules;
//	IMonitorModule			modules(module_names);

	try
	{
		modules = parse_input(argc, argv);
	}
	catch (std::string msg)
	{
		std::cout << msg << std::endl;
		return (1);
	}
	run(modules);
	return (0);
}
