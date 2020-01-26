/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayGUI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:02 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 14:46:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYGUI_HPP
# define DISPLAYGUI_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <vector>
#include <curses.h>

class					DisplayGUI : virtual public IMonitorDisplay
{
	public:
		DisplayGUI(void);
		DisplayGUI(const DisplayGUI &other);
		~DisplayGUI(void);
		DisplayGUI		&operator=(const DisplayGUI &other);
		void			display_border(std::string title) const;
		void			display_graph(std::string title, int info[]) const;
		void			display_bar(std::string title, unsigned int percentage) const;
		void			display_line(std::string title) const;
		void			display_line_2(std::string title, std::string info) const;
		void			manage_display(std::vector<IMonitorModule*> modules);

	private:
};

#endif
