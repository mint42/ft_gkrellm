/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:39:56 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 06:59:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include "DisplayCLI.hpp"
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

//static std::list<std::string>		parse_input(int argc, char **argv)
//{
//	std::list<std::string>	modules;
//
//	// not really using args yet, just testing some functionality
//	(void)argc;
//	(void)argv;
//	modules.push_back(NAMES);
//	modules.push_back(OSINFO);
//	return (modules);
//}

//static void						manage(list<std::string> modules)
//{
//	ModuleManager	manager(modules);
//
//	while (42)
//	{
//	
//	}
//}

int								main(void)
{
//	std::list<std::string>	modules;
	IMonitorDisplay			*mode;
	DisplayCLI				cli_mode;

	mode = &cli_mode;

/*
**	try
**	{
**		if (argc == 1)
**			mode = new DisplayCLI;
**		else
**		{
**			if (ft_strequ(argv[1], "--cli"))
**			if (ft_strequ(argv[1], "--gui"))
**			else
**				throw (USAGE);
**		}
**	}
**	catch (...)
**	{
**		std::cout << USAGE << std::endl;
**	}
*/

//	modules = parse_input(argc, argv);

//	manage_program(modules, display);
	return (0);
}
