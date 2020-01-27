/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:39:56 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 18:36:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include "DisplayCLI.hpp"
#include "DisplayGUI.hpp"
#include "IMonitorModule.hpp"
#include "Mhu.hpp"
#include "Mos.hpp"
#include "Mdate.hpp"
#include "Mcpu.hpp"
#include "Mram.hpp"
#include "Mnt.hpp"
#include "Mcat.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <curses.h>

#include "config.hpp"
#define OP_HU 1
#define OP_OS 2
#define OP_DT 3
#define OP_CPU 4
#define OP_RAM 5
#define OP_NET 6
#define OP_CAT 7
#define NMODS 7

// usage

static void		show_usage(void)
{
	std::cout << "./ft_gkrellm [--cli/--gui] [ModuleID#] ..." << std::endl;
	std::cout << std::endl;
	std::cout << "ID   MODULE" << std::endl;
	std::cout << OP_HU <<  "    " << MOD_HU << std::endl;
	std::cout << OP_OS <<  "    " << MOD_OS << std::endl;
	std::cout << OP_DT <<  "    " << MOD_DT << std::endl;
	std::cout << OP_CPU << "    " << MOD_CPU << std::endl;
	std::cout << OP_RAM << "    " << MOD_RAM << std::endl;
	std::cout << OP_NET << "    " << MOD_NET << std::endl;
	std::cout << OP_CAT << "    " << MOD_CAT << std::endl;
	std::cout << std::endl;
}

#include <cstdlib>

static std::vector<IMonitorModule*>	parse_input(int argc, char **argv)
{
	static std::string				all_modules[] =
	{
		MOD_HU,
		MOD_OS,
		MOD_DT,
		MOD_CPU,
		MOD_RAM,
	};
	std::vector<IMonitorModule*>		cur_modules;
	int									param;

	if (argc <= 1)
		throw (std::string("bad"));
	for (int i = 1; i < argc; i++)
	{
		param = std::atoi(argv[i]);
		switch (param)
		{
			case OP_HU:
			{
				cur_modules.push_back(new Mhu());
				break ;
			}
			case OP_OS:
			{
				cur_modules.push_back(new Mos());
				break ;
			}
			case OP_DT:
			{
				cur_modules.push_back(new Mdate());
				break ;
			}
			case OP_CPU:
			{
				cur_modules.push_back(new Mcpu());
				break ;
			}
			case OP_RAM:
			{
				cur_modules.push_back(new Mram());
				break ;
			}
			case OP_NET:
			{
				cur_modules.push_back(new Mnt());
				break ;
			}
			case OP_CAT:
			{
				cur_modules.push_back(new Mcat());
				break ;
			}
			default:
			{
				throw (std::string("bad"));
				break ;
			}
		}
	}
	return (cur_modules);
}

static void							run(std::vector<IMonitorModule*> modules)
{
	IMonitorDisplay			*display_mode = new DisplayCLI();

	display_mode->manage_display(modules);
}

int								main(int argc, char **argv)
{
	std::vector<IMonitorModule*>			modules;

	try
	{
		modules = parse_input(argc, argv);
	}
	catch (std::string msg)
	{
		(void)msg;
		show_usage();
		return (1);
	}
	run(modules);
	return (0);
}
