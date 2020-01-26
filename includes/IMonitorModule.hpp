/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:43 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 06:47:50 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMonitorModule_HPP
# define IMonitorModule_HPP
#define __USE_POSIX
#include <string>
#include <iostream>
#include <unistd.h>
#include <limits>
#include <sys/utsname.h>
#include <sstream>
#include <fstream>

class			IMonitorModule
{
	public:
		virtual ~IMonitorModule(void) {};
		virtual std::string getMName() const = 0;
		virtual void execute() const = 0;
};

#endif
