/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayCLI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:05 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 06:39:51 by rreedy           ###   ########.fr       */
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
		bool			get_show_border(void) const;
		bool			get_show_title(void) const;
		int				get_color(void) const;
		void			set_show_border(bool new_show_border);
		void			set_show_title(bool new_show_title);
		void			set_color(int new_color);
		void			display_border(WINDOW *win) const;
		void			display_graph(std::string title, int info[]) const;
		void			display_bar(std::string title, unsigned int percentage) const;
		void			display_info(std::string info) const;
		void			display_info_2_part(std::string info, std::string secondary_info) const;

	private:
		bool			_show_border;
		bool			_show_title;
		int				_color;
};

#endif
