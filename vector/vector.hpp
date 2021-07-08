/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/08 05:46:32 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "../iterator/iterator.h"
#include "../utils/color.h"
#include "../utils/ft_print_memory.h"

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

		class vector_iterator : public ft::iterator<T> //______________________
		{
		public:
			typedef T						value_type;
			typedef value_type *			pointer;
			typedef const value_type 		const_pointer;
			typedef value_type &			reference;
			typedef const value_type &		const_reference;
			typedef typename std::ptrdiff_t	difference_type;

			vector_iterator() {}
			vector_iterator(pointer x_t) : _ptr(x_t) {}
			// vector_iterator(const difference_type rhs) : ft::iterator<T>(rhs) {}
			~vector_iterator() {}
			/// Member Operators
			vector_iterator	&operator= (const vector_iterator &rhs)	{	_ptr = rhs._ptr; return (*this);	}

			/// Equality Operators
			bool	operator==(const vector_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
			bool	operator!=(const vector_iterator &rhs) const	{ return (_ptr != rhs._ptr); }
			bool	operator<=(const vector_iterator &rhs) const	{ return (_ptr <= rhs._ptr); }
			bool	operator>=(const vector_iterator &rhs) const	{ return (_ptr >= rhs._ptr); }
			bool	operator< (const vector_iterator &rhs) const	{ return (_ptr < rhs._ptr);  }
			bool	operator> (const vector_iterator &rhs) const	{ return (_ptr > rhs._ptr);  }

			///  Dereferense
			reference		operator[](difference_type rhs) { return (*(_ptr + rhs)); }
			const_reference	operator[](difference_type rhs) const { return (*(_ptr + rhs)); }

			///   Random access vvv
			vector_iterator	operator+ (difference_type rhs)	{ vector_iterator	it(_ptr + rhs); return (it);		}
			vector_iterator	operator- (difference_type rhs)	{ vector_iterator	it(_ptr - rhs); return (it);		}
			difference_type	operator- (vector_iterator rhs)	{ difference_type	df(_ptr - rhs._ptr); return (df);	}

			///   Pre
			vector_iterator	&operator++() { ++(this->_ptr); return (*this);	}
			///   Post
			vector_iterator	operator++(int){ iterator tmp = *this; ++(this->_ptr); return (tmp);	}	// optional

			// operator	vector_iterator<const T> {	return vector_iterator<const T>(_ptr);	}	// conversion from const iterator to iterator

			reference		operator* () { return (*_ptr); }

		// private:
			pointer _ptr;

		};	// iterator _______________________________________________________
		typedef vector_iterator iterator;

		// Constructors & Destructors
		vector(void) : _value_data(NULL), _value_size(sizeof(T)), _value_count(0)
		{
			// std::cout <<GRN<< "vector constructor" <<RST<< std::endl;
			_value_data = reinterpret_cast<pointer>(::operator new (0));
		}
		// vector(/* another vector */);
		virtual	~vector(void) { delete _value_data; }

		// Copy constructor
		vector(const vector<T> & copy) {}

		// Operation overload =
		vector<T> &	operator=(vector<T> & copy)	// should be const
		{
			vector_iterator i;	// this
			vector_iterator j;	// copy

			delete _value_data;

			_value_data = _allocator.allocate(copy._value_size * copy._value_count);

			i = copy.begin();
			j = this->begin();
			while (i != copy.end())
			{
				*j = *i;
				++i;
				++j;
			}

			_value_size = copy._value_size;
			_value_count = copy._value_count;

			return *this;
		}

		vector_iterator	begin()	{ return vector_iterator(_value_data); }

		vector_iterator end()	{ return vector_iterator(_value_data + _value_count); }

		// faire des listes
		void	push_back(const T & rhs)
		{
			pointer	data;
			int		i;

			data = _allocator.allocate(_value_size * (_value_count + 1));
			
			i = 0;
			vector_iterator it = this->begin();
			while (it != this->end())
			{
				data[i++] = *it;
				++it;
			}
			data[i] = rhs;

			++_value_count;
			delete _value_data;
			_value_data = data;

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
