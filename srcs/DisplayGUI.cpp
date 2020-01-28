/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayGUI.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:13:02 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 22:51:08 by rreedy           ###   ########.fr       */
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

void			DisplayGUI::display_border(std::string title)
{
	sf::Text	text;
	sf::Font	font;

	text.setFont(_font);
	text.setString(title);
	text.setPosition(5, _cur_pos);
	_window.draw(text);

	_cur_pos += (text.getLocalBounds().height * 2);
}

void			DisplayGUI::display_graph(std::string title, int info[])
{
	(void)title;
	(void)info;
}

void			DisplayGUI::display_bar(std::string title, unsigned int percentage)
{
	(void)title;
	(void)percentage;
}

void			DisplayGUI::display_line(std::string title)
{
	sf::Text	text;

	text.setFont(_font);
	text.setString(title);
	text.setPosition(5, _cur_pos);
	_window.draw(text);

	_cur_pos += (text.getLocalBounds().height * 2);
}

void			DisplayGUI::display_line_2(std::string title, std::string info)
{
	sf::Text	text;
	sf::Text	text_info;

	text.setFont(_font);
	text.setString(title);
	text.setPosition(5, _cur_pos);
	_window.draw(text);
	text_info.setFont(_font);
	text_info.setString(info);
	text_info.setPosition(text.getLocalBounds().width * 3, _cur_pos);
	_window.draw(text_info);

	_cur_pos += (text.getLocalBounds().height * 2);
}

void			DisplayGUI::display_cat(int frame)
{
	(void)frame;
}

void			DisplayGUI::display(std::vector<unsigned int> sub_windows, std::vector<IMonitorModule*>modules)
{
	std::vector<IMonitorModule*>::const_iterator	it;
	std::vector<IMonitorModule*>::const_iterator	ite = modules.end();
	std::vector<unsigned int>::const_iterator		wit = sub_windows.begin();

	_cur_pos = 1;
	for (it = modules.begin(); it != ite; it++)
	{
		display_border((*it)->getMName());
		(*it)->execute(this);
		++wit;
		_cur_pos += 40;
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
	std::vector<unsigned int>	sub_windows = make_sub_windows(modules);

	if (!_font.loadFromFile("./FontTrebuchetMS.ttf"))
		return ;
	_window.create(sf::VideoMode(1000, 2000), "ft_gkrellm");
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
		}
		_window.clear();
		display(sub_windows, modules);
		_window.display();
	}
}
