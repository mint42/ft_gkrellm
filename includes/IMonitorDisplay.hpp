/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:32 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 14:45:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <vector>
#include <curses.h>

class						IMonitorModule;

class						IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void) {};
		virtual void		display_border(std::string title) const = 0;
		virtual void		display_graph(std::string title, int info[]) const = 0;
		virtual void		display_bar(std::string title, unsigned int percentage) const = 0;
		virtual void		display_line(std::string title) const = 0;
		virtual void		display_line_2(std::string title, std::string info) const = 0;
		virtual void		manage_display(std::vector<IMonitorModule*> modules) = 0;
};

#endif
