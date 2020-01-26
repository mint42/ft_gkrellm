/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleManager.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:42:12 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/26 01:51:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ModuleManager_HPP
# define ModuleManager_HPP

class			ModuleManager
{
	public:
		ModuleManager(void);
		ModuleManager(list<std::string> module_names);
		ModuleManager(const ModuleManager &other);
		~ModuleManager(void);
		ModuleManager		&operator=(const ModuleManager &other);
		list<std::string>	get_module_names() const;
		unsigned int		get_nmodules() const;
		unsigned int		get_min_width() const;
		unsigned int		get_min_height() const;
		void				set_module_names(list<std::string> names);
		void				set_nmodules(unsigned int n);
		void				set_min_width(unsigned int n);
		void				set_min_height(unsigned int n);

	private:
		list<std::string>	module_names;		// list of strings is temporary
		unsigned int		_nmodules;
		unsigned int		_min_width;
		unsigned int		_min_height;
};

#endif
