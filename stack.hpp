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
		: c(ctnr)
		{}

		~stack ()
		{}

		// Copy constructor
		stack (const stack& copy)
		{
			*this = copy;
		}

		// Operation overload =
		stack&				operator= (const stack &	copy)
		{
			c = copy.c;
			return (*this);
		}

		// * Member functions __________________________________________________

		bool				empty () const
		{
			return (c.empty());
		}

		size_type			size () const
		{
			return (c.size());
		}

		value_type& 		top ()
		{
			typename container_type::iterator	it = --c.end();
			return (*it);
		}

		const value_type&	top () const
		{
			typename container_type::iterator	it = --c.end();
			return (*it);
		}

		void				push (const value_type& val)
		{
			c.push_back(val);
		}

		void				pop ()
		{
			c.pop_back();
		}

		// * Comparisons _______________________________________________________

		// ? friend allow us to compare the protected variable c
		// ? and making comparisons non-member allow comparisons between
		// ? const and non const

		template <class _T, class  _Container>
		friend bool			operator==(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		
		template <class _T, class  _Container>
		friend bool			operator!=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

		template <class _T, class  _Container>
		friend bool			operator< (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

		template <class _T, class  _Container>
		friend bool			operator<=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

		template <class _T, class  _Container>
		friend bool			operator> (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

		template <class _T, class  _Container>
		friend bool			operator>=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

		/// * Variables ________________________________________________________
	protected:
		container_type		c;
	};

	/// * Non-member functions _________________________________________________

	template <class T, class Container>
	bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
	bool	operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool	operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <class T, class Container>
	bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}

}

#endif
