/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:32 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 06:37:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include <string>
#include <curses.h>

class						IMonitorDisplay
{
	public:
		IMonitorDisplay(void);
		IMonitorDisplay(const IMonitorDisplay &other);
		virtual ~IMonitorDisplay(void);
		IMonitorDisplay		&operator=(const IMonitorDisplay &other);
		virtual bool		get_show_border(void) const = 0;
		virtual bool		get_show_title(void) const = 0;
		virtual int			get_color(void) const = 0;
		virtual void		set_show_border(bool new_show_border) = 0;
		virtual void		set_show_title(bool new_show_title) = 0;
		virtual void		set_color(int new_color) = 0;
		virtual void		display_border(WINDOW *win) const = 0;
		virtual void		display_graph(std::string title, int info[]) const = 0;
		virtual void		display_bar(std::string title, unsigned int percentage) const = 0;
		virtual void		display_info(std::string info) const = 0;
		virtual void		display_info_2_part(std::string info, std::string secondary_info) const = 0;

	private:
		bool				_show_border;
		bool				_show_title;
		int					_color;
};

#endif
