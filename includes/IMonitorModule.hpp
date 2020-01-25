/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:12:43 by rreedy            #+#    #+#             */
/*   Updated: 2020/01/25 04:12:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMonitorModule_HPP
# define IMonitorModule_HPP

class			IMonitorModule
{
	public:
		IMonitorModule(void);
		IMonitorModule(const IMonitorModule &other);
		~IMonitorModule(void);
		IMonitorModule		&operator=(const IMonitorModule &other);

	private:
		tmp;
};

#endif
