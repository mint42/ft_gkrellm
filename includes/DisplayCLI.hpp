/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 07:58:35 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYCLI_HPP
# define DISPLAYCLI_HPP

#include "IMonitorDisplay.hpp"
#include <string>
#include <curses.h>

class					DisplayCLI : public IMonitorDisplay
{
	public:
		DisplayCLI(void);
		DisplayCLI(const DisplayCLI &other);
		~DisplayCLI(void);
		DisplayCLI		&operator=(const DisplayCLI &other);
		void			display_border(std::string title, WINDOW *win) const;
		void			display_graph(std::string title, int info[]) const;
		void			display_bar(std::string title, unsigned int percentage) const;
		void			display_line(std::string title) const;
		void			display_line_2(std::string title, std::string info) const;

	private:
};

#endif
