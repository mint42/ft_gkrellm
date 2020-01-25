/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayGUI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:02 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 06:37:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYGUI_HPP
# define DISPLAYGUI_HPP

#include <string>
#include <curses.h>

class					DisplayGUI
{
	public:
		DisplayGUI(void);
		DisplayGUI(const DisplayGUI &other);
		~DisplayGUI(void);
		DisplayGUI		&operator=(const DisplayGUI &other);
		bool			get_show_border(void);
		bool			get_show_title(void);
		int				get_primary_color(void);
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
