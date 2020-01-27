/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:32 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 21:35:58 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <vector>
#include <curses.h>

#define PADDING 1

class						IMonitorModule;

class						IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void) {};
		virtual void		display_border(std::string title) = 0;
		virtual void		display_graph(std::string title, int info[]) = 0;
		virtual void		display_bar(std::string title, unsigned int percentage) = 0;
		virtual void		display_line(std::string title) = 0;
		virtual void		display_line_2(std::string title, std::string info) = 0;
		virtual void		display_cat(int frame) = 0;
		virtual void		manage_display(std::vector<IMonitorModule*> modules) = 0;
};

#endif
