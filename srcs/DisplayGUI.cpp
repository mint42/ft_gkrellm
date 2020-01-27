/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayGUI.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:02 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 20:21:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayGUI.hpp"
#include <SFML/Graphics.hpp>

/*
**	Constructors
*/

DisplayGUI::DisplayGUI(void)
{
}

DisplayGUI::DisplayGUI(const DisplayGUI &other)
{
	*this = other;
}

/*
**	Destructor
*/

DisplayGUI::~DisplayGUI(void)
{
}

/*
**	Operator Overloaders
*/

DisplayGUI		&DisplayGUI::operator=(const DisplayGUI &other)
{
	(void)other;
	return (*this);
}

/*
**	Other Member Functions
*/

void			DisplayGUI::display_border(std::string title) const
{
	(void)title;
}

void			DisplayGUI::display_graph(std::string title, int info[]) const
{
	(void)title;
	(void)info;
}

void			DisplayGUI::display_bar(std::string title, unsigned int percentage) const
{
	(void)title;
	(void)percentage;
}

void			DisplayGUI::display_line(std::string title) const
{
	(void)title;
}

void			DisplayGUI::display_line_2(std::string title, std::string info) const
{
	(void)title;
	(void)info;
}

void			DisplayGUI::display_cat(int frame) const
{
	(void)frame;
}

void			DisplayGUI::display(sf::RenderWindow &window, std::vector<unsigned int> sub_windows, std::vector<IMonitorModule*>modules)
{
	std::vector<IMonitorModule*>::const_iterator	it;
	std::vector<IMonitorModule*>::const_iterator	ite = modules.end();
	std::vector<unsigned int>::const_iterator		wit = sub_windows.begin();

	(void)window;
	for (it = modules.begin(); it != ite; it++)
	{
		_cur_pos = *wit;
		display_border((*it)->getMName());
		(*it)->execute(this);
		++wit;
	}
}

std::vector<unsigned int>     DisplayGUI::make_sub_windows(std::vector<IMonitorModule*> modules)
{
	std::vector<unsigned int>						sub_windows;
	unsigned int									current_height;
	std::vector<IMonitorModule*>::const_iterator	it;
	std::vector<IMonitorModule*>::const_iterator	ite = modules.end();

	current_height = 1;
	for (it = modules.begin(); it != ite; it++)
	{
		sub_windows.push_back(current_height);
		current_height = current_height + (*it)->get_height() + PADDING;
	}
	return (sub_windows);
}

void			DisplayGUI::manage_display(std::vector<IMonitorModule*> modules)
{
	sf::RenderWindow			window(sf::VideoMode(800, 600), "ft_gkrellm");
	std::vector<unsigned int>	sub_windows = make_sub_windows(modules);
	sf::CircleShape		shape(100.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
//		display(window, sub_windows, modules);
	}
}
