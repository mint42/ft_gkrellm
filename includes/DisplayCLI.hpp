/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 07:08:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYCLI_HPP
# define DISPLAYCLI_HPP

#include "IMonitorDisplay.hpp"
#include <string>
#include <list>
#include <vector>
#include <ncurses.h>
#include <curses.h>

class					DisplayCLI : public IMonitorDisplay
{
	public:
		DisplayCLI(void);
		DisplayCLI(const DisplayCLI &other);
		~DisplayCLI(void);
		DisplayCLI		&operator=(const DisplayCLI &other);
		void			display_border(WINDOW *win, std::string title) const;
		void			display_graph(WINDOW *win, std::string title, int info[]) const;
		void			display_bar(WINDOW *win, std::string title, unsigned int percentage) const;
		void			display_line(WINDOW *win, std::string title) const;
		void			display_line_2(WINDOW *win, std::string title, std::string info) const;
		void			manage_display(std::list<std::string> modules);

	private:
		void						display(std::vector<WINDOW*> windows, std::list<std::string>modules);
		std::vector<WINDOW*>		make_windows(unsigned int nmodules);
};

#endif
