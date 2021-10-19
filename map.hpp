/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/19 21:38:23 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
	class map
	{
	private:
		/* data */
	public:
		// Constructors & Destructors
		map(void);
		// map(/* args */);
		~map(void);

		// Copy constructor
		map(const map & copy);

		// Operation overload =
		map &	operator=(const map &	copy);
	};
}

#endif