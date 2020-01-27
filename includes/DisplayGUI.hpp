/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayGUI.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:02 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 20:18:34 by rreedy           ###   ########.fr       */
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
		void			display_border(std::string title) const;
		void			display_graph(std::string title, int info[]) const;
		void			display_bar(std::string title, unsigned int percentage) const;
		void			display_line(std::string title) const;
		void			display_line_2(std::string title, std::string info) const;
		void			display_cat(int frame) const;
		void			manage_display(std::vector<IMonitorModule*> modules);

	private:
		unsigned int				_cur_pos;
		void						display(sf::RenderWindow &window, std::vector<unsigned int> sub_windows, std::vector<IMonitorModule*>modules);
		std::vector<unsigned int>	make_sub_windows(std::vector<IMonitorModule*> modules);
};

#endif
