/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_str.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:48:31 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 23:02:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>

std::string		cmd_to_str(const char *command)
{
	FILE*					file = popen(command, "r");
	char					line[1024] ;
	std::stringstream		ss;
	std::string				str;

	if (file)
	{
		while (fgets(line, 1024, file))
			ss << line;
		pclose(file) ;
		str = ss.str();
	}
	if (str.length())
		str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	return (str);
}

std::string		cmd_to_str_DummyThicc(const char *command)
{
    FILE *f = popen(command, "r");
    char buffer [4096];

    long i = 0;
    long o = 0;
    while (fgets(buffer, 4096, f)) {
        std::string line(buffer);
        if(line.find("input") == line.npos && line.find("packets") == line.npos) {
            long discard;
            std::stringstream ss(line);
            ss >> discard;
            ss >> discard;
            ss >> i;
            ss >> discard;
            ss >> discard;
            ss >> o;
            std::stringstream ss2;
            ss2 << "Input: " << i << " Output: " << o;
            return (ss2.str());
        }
    }
    return ("");
}
