/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayGUI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:02 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 22:21:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYGUI_HPP
# define DISPLAYGUI_HPP

#include "IMonitorModule.hpp"
#include <SFML/Graphics.hpp>
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
		void			display_border(std::string title);
		void			display_graph(std::string title, int info[]);
		void			display_bar(std::string title, unsigned int percentage);
		void			display_line(std::string title);
		void			display_line_2(std::string title, std::string info);
		void			display_cat(int frame);
		void			manage_display(std::vector<IMonitorModule*> modules);

	private:
		unsigned int				_cur_pos;
		sf::RenderWindow			_window;
		sf::Font					_font;
		void						display(std::vector<unsigned int> sub_windows, std::vector<IMonitorModule*>modules);
		std::vector<unsigned int>	make_sub_windows(std::vector<IMonitorModule*> modules);
};

#endif
