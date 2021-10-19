/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:42:44 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/19 21:42:44 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

namespace ft
{
	class stack
	{
	private:
		/* data */
	public:
		// Constructors & Destructors
		stack();
		~stack();

		// Copy constructor
		stack(const stack & copy);

		// Operation overload =
		stack &	operator=(const stack &	copy);
	};
}

#endif
