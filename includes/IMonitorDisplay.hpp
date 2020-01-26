/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:32 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 07:08:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include <string>
#include <list>
#include <ncurses.h>

class						IMonitorDisplay
{
	public:
		IMonitorDisplay(void);
		IMonitorDisplay(const IMonitorDisplay &other);
		virtual ~IMonitorDisplay(void) = 0;
		IMonitorDisplay		&operator=(const IMonitorDisplay &other);
		bool				get_show_border(void) const;
		bool				get_show_title(void) const;
		int					get_color(void) const;
		void				set_show_border(bool new_show_border);
		void				set_show_title(bool new_show_title);
		void				set_color(int new_color);
		virtual void		display_border(WINDOW *win, std::string title) const = 0;
		virtual void		display_graph(WINDOW *win, std::string title, int info[]) const = 0;
		virtual void		display_bar(WINDOW *win, std::string title, unsigned int percentage) const = 0;
		virtual void		display_line(WINDOW *win, std::string title) const = 0;
		virtual void		display_line_2(WINDOW *win, std::string title, std::string info) const = 0;
		virtual void		manage_display(std::list<std::string> modules) = 0;

	private:
		bool				_show_border;
		bool				_show_title;
		int					_color;
};

#endif
