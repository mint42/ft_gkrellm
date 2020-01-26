/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:39:56 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 02:07:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include "DisplayCLI.hpp"
#include "ModuleManager"
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
// #include <exception>
#include <ncurses.h>

// modules
#define NAMES "Names"
#define OSINFO "OS info"

#define USAGE "./ft_gkrellm [--cli/--gui] [modules]"

// only turning it into a list because i assume it will be parsing a config soon
// but for now it can just take cl args


static std::list<std::string>		parse_input(int argc, char **argv)
{
	std::list<std::string>	modules;

	if (argc <= 1)
		throw (InvalidParseException);
	for (int i = 0; i < argc; i++)
	{
		modules.push_back(std::string(argv[i]));
	}
	return (modules);
}

static void						manage(list<std::string> modules)
{
	IMonitorDisplay			*mode = new DisplayCLI();
	ModuleManager			manager(modules);

	manager.get_nmodules();
	manager.create_windows();
	while (1)
	{
	}
}

int								main(void)
{
	std::list<std::string>	modules;

	try
	{
		modules = parse_input(int argc, char **argv);
	}
	catch (InvalidParseException)
	{
		std::cout << USAGE << std::endl;
	}
	manage(modules);
	return (0);
}
