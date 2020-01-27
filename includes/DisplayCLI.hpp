/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 21:36:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYCLI_HPP
# define DISPLAYCLI_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <string>
#include <vector>
#include <curses.h>

class							DisplayCLI : virtual public IMonitorDisplay
{
	public:
		DisplayCLI(void);
		DisplayCLI(const DisplayCLI &other);
		~DisplayCLI(void);
		DisplayCLI				&operator=(const DisplayCLI &other);
		void					display_border(std::string title);
		void					display_graph(std::string title, int info[]);
		void					display_bar(std::string title, unsigned int percentage);
		void					display_line(std::string title);
		void					display_line_2(std::string title, std::string info);
		void					display_cat(int frame);
		void					manage_display(std::vector<IMonitorModule*> modules);

	private:
		WINDOW					*_cur_win;
		void					display(std::vector<WINDOW*> windows, std::vector<IMonitorModule*> modules);
		std::vector<WINDOW*>	make_windows(std::vector<IMonitorModule*> modules);
};

#endif
