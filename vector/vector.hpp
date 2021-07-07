/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/08 01:54:15 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "../iterator/iterator.h"
#include "../utils/color.h"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T						value_type;
		typedef value_type *			pointer;
		typedef const value_type 		const_pointer;
		typedef value_type &			reference;
		typedef const value_type &		const_reference;
		typedef typename std::ptrdiff_t	difference_type;

		class vector_iterator : public ft::iterator<T>
		{
		public:
			typedef T						value_type;
			typedef value_type *			pointer;
			typedef const value_type 		const_pointer;
			typedef value_type &			reference;
			typedef const value_type &		const_reference;
			typedef typename std::ptrdiff_t	difference_type;

			vector_iterator() : ft::iterator<T>()		{}
			vector_iterator(pointer x_t) : _ptr(x_t)	{}
			// vector_iterator(const difference_type rhs) : ft::iterator<T>(rhs) {}
			~vector_iterator()	{}
			/// Member Operators
			vector_iterator	&operator= (const vector_iterator &rhs)	{	_ptr = rhs._ptr; return (*this);	}

			///   Random access vvv
			vector_iterator	operator+ (difference_type rhs)	{ vector_iterator	it(_ptr + rhs); return (it);		}
			vector_iterator	operator- (difference_type rhs)	{ vector_iterator	it(_ptr - rhs); return (it);		}
			difference_type	operator- (vector_iterator rhs)	{ difference_type	df(_ptr - rhs._ptr); return (df);	}

			// operator	vector_iterator<const T> {	return vector_iterator<const T>(_ptr);	}	// conversion from const iterator to iterator

		// private:
			pointer _ptr;

		};
		typedef vector_iterator iterator;

		// Constructors & Destructors
		vector(void) : _value_data(0), _value_size(sizeof(T)), _value_count(0)
		{
			std::cout <<GRN<<"vector constructor"<<RST<< std::endl;
			_value_data = reinterpret_cast<pointer>(::operator new (sizeof(int)));
			_value_data[0] = 666;
			std::cout <<GRN<< reinterpret_cast<void *>(_value_data) <<RST<< std::endl;

			std::cout <<GRN<< _value_data[0] <<std::endl;
		}
		// vector(/* args */);
		virtual	~vector(void) { delete [] _value_data; }

		// Copy constructor
		vector(const vector<T> & copy)	{}

		// Operation overload =
		vector<T> &	operator=(const vector<T> &	copy)
		{
			_value_size = copy._value_size;
			_value_count = copy._value_size;
		}

		vector_iterator	begin()	{ return vector_iterator(_value_data); }

		vector_iterator end() { return vector_iterator(_value_data + _value_count); }

		// faire des listes
		void	push_back(const T & rhs)
		{
			// pointer data;
			// int		i;

			// i = 0;
			// data = _allocator.allocate(_value_size * (_value_count + 1));
			
			// vector_iterator it = _value_data;
			// // vector_iterator iv = data->_value_data;

			// while (it != this->end())
			// {
			// 	data[i++] = *it;
			// 	++it;
			// }
			// data[i] = rhs._value_data[i];

			// ++_value_count;
			// delete [] _value_data;
			// _value_data = data;

			// std::cout << "> " << _value_data << std::endl;
		}

	// private:
		pointer			_value_data;
		uint64_t		_value_size;
		uint64_t		_value_count;
		// uint64_t		_value_chunk_size;	// will be used for optimisation
		Allocator		_allocator;

	};

} // namespace ft

#endif
