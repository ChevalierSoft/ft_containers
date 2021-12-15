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

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack /// * __________________________________________________________
	{
	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;

		// * Constructors & Destructors ________________________________________
	public:
		explicit stack (const container_type& ctnr = container_type())
		: _c(ctnr)
		{}

		~stack ()
		{}

		// Copy constructor
		stack (const stack& copy)			{ *this = copy;			}

		// Operation overload =
		stack&				operator= (const stack &	copy)
		{
			_c = copy._c;
			return (*this);
		}

		bool				empty () const	{ return (_c.empty());	}

		size_type			size () const	{ return (_c.size()); 	}

		value_type& 		top ()
		{
			return (_c[_c.size()]);
		}

		const value_type&	top () const
		{
			return (_c[_c.size()]);
		}

		void				push (const value_type& val)
		{
			_c.push_back(val);
		}

		void				pop ()
		{
			_c.pop_back();
		}

		/// * Variables ________________________________________________________
	private:
		container_type	_c;
	};

	/// * Non-member functions _________________________________________________

	template <class T, class Container>
	bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c == rhs.c);
	}

	template <class T, class Container>
	bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c != rhs.c);
	}

	template <class T, class Container>
	bool	operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c < rhs.c);
	}

	template <class T, class Container>
	bool	operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c > rhs.c);
	}

	template <class T, class Container>
	bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c <= rhs.c);
	}

	template <class T, class Container>
	bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c >= rhs.c);
	}

}


#endif
