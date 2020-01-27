/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:43 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 17:19:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
#define __USE_POSIX
#include <string>
#include <iostream>
#include <unistd.h>
#include <limits>
#include <sys/utsname.h>
#include <sstream>
#include <fstream>
#include "IMonitorDisplay.hpp"

class							IMonitorDisplay;

class							IMonitorModule
{
	public:
		virtual ~IMonitorModule(void) {};
		virtual std::string getMName(void) const = 0;
		virtual void			execute(IMonitorDisplay *display_mode) = 0;
		virtual unsigned int	get_height(void) const = 0;
	
	protected:
		unsigned int			_height;
};

#endif
