/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/18 04:42:59 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cmath>
#include "../iterator/iterator.h"
#include "../utils/color.h"
#include "../utils/ft_print_memory.h"

/*
must be reimplemented :
	iterator_traits,
	reverse_iterator,
	enable_if,
	is_integral,
	equal/lexicographical com-pare, 
	std::pair,
	std::make_pair
*/

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector //_____________________________________________________________
	{
	public:
		typedef T						value_type;
		typedef value_type *			pointer;
		typedef const value_type 		const_pointer;
		typedef value_type &			reference;
		typedef const value_type &		const_reference;
		typedef typename std::ptrdiff_t	difference_type;
		typedef size_t					size_type;
		typedef Allocator				allocator_type;


		/// Vector Iterator ____________________________________________________
		class vector_iterator : public random_access_iterator_tag //_________
		{
		public:
			typedef T											value_type;
			typedef value_type *								pointer;
			typedef const value_type 							const_pointer;
			typedef value_type &								reference;
			typedef const value_type &							const_reference;
			typedef typename std::ptrdiff_t						difference_type;

			typedef typename std::random_access_iterator_tag 	iterator_category;

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
			reference		operator[](difference_type rhs)			{ return (*(_ptr + rhs)); }
			const_reference	operator[](difference_type rhs) const	{ return (*(_ptr + rhs)); }

			///   Random access vvv
			vector_iterator	operator+ (difference_type rhs)	{ vector_iterator	it(_ptr + rhs); return (it);		}
			vector_iterator	operator- (difference_type rhs)	{ vector_iterator	it(_ptr - rhs); return (it);		}
			difference_type	operator- (vector_iterator rhs)	{ difference_type	df(_ptr - rhs._ptr); return (df);	}

			///   Pre
			vector_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
			vector_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
			///   Post
			vector_iterator	operator++(int)	{ vector_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
			vector_iterator	operator--(int) { vector_iterator tmp = *this; --(this->_ptr); return (tmp);	}

			// operator	vector_iterator<const T> {	return vector_iterator<const T>(_ptr);	}	// conversion from const iterator to iterator

			reference		operator* ()	{ return (*_ptr); }

		// private:
			pointer _ptr;

		};	// iterator _______________________________________________________
		typedef vector_iterator iterator;

		/// Constructors & Destructors _________________________________________

		vector(void) : _value_data(NULL), _value_size(sizeof(T)), _value_count(0), _value_chunk_size(0)
		{
			_value_data = _allocator.allocate(_value_chunk_size);
		}

		vector(difference_type nb, const T & elem) : vector()
		{
			for (int i = 0; i < nb; ++i) {
				this->push_back(elem);
			}
		}

		virtual	~vector(void)
		{
			std::cout <<RED<< "vector destructor" <<RST<< std::endl;
			_allocator.deallocate(_value_data, _value_chunk_size);
			_value_data = NULL;
			_value_size = 0;
			_value_count = 0;
			_value_chunk_size = 0;
		}

		vector(const vector<T> & copy)
		{
			_value_data = _allocator.allocate(copy._value_size * copy._value_chunk_size);
			std::copy(&copy._value_data[0], &copy._value_data[copy._value_count], _value_data);
			_value_count = copy._value_count;
			_value_size  = copy._value_size;
			_value_chunk_size = copy._value_chunk_size;
		}

		vector<T> &	operator=(vector<T> & copy)	// should be const
		{
			vector_iterator i;	// this
			vector_iterator j;	// copy

			_allocator.deallocate(_value_data, _value_chunk_size);

			_value_data = _allocator.allocate(copy._value_size * copy._value_chunk_size);

			i = copy.begin();
			j = this->begin();
			while (i != copy.end())
			{
				*j = *i;
				++i;
				++j;
			}

			_value_size			= copy._value_size;
			_value_count		= copy._value_count;
			_value_chunk_size	= copy._value_chunk_size;

			return *this;
		}

		/// assign() & get_allocator() _________________________________________
		allocator_type	get_allocator() const { return this->_allocator; }

		/// Element access _____________________________________________________

		/// Iterators __________________________________________________________

		vector_iterator	begin() const		{ return vector_iterator(_value_data);					}

		vector_iterator end() const			{ return vector_iterator(_value_data + _value_count);	}

		/// Capacity ___________________________________________________________

		bool			empty() const		{ return _value_count == 0;								}	//	or : return begin() == end();

		size_type		size() const		{ return _value_count;									}

		size_type		max_size() const
		{
			if (sizeof(T) == 1)
				return ((size_type)-1) / (sizeof(T) + 1);
			return ((size_type)-1) / sizeof(T);
		}

		size_type		capacity() const	{ return _value_count * _value_size;					}

		/// Modifiers __________________________________________________________

		void			clear()				{ _value_count = 0;	}

		// insert single element
		iterator insert(iterator position, const value_type &val)
		{

		}
		// insert fill n
		void insert(iterator position, size_type n, const value_type &val);
		// insert by range
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);


		// void std::vector<T>::push_back(const T &obj)
		// {
		// 	this->insert(this->end(), obj);
		// }

		void			push_back(const T & rhs)
		{
			pointer			data;
			int				i;
			vector_iterator	it;

			if (_value_count >= _value_chunk_size)
			{
				data = _allocator.allocate(_value_size * (_value_count + 4));
				_value_chunk_size = _value_count + 4;

				i = 0;
				it = this->begin();
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
			else
			{
				_value_data[_value_count] = rhs;
				++_value_count;
			}

		}

		void			pop_back()
		{
			if (_value_count > 0)
			{
				_value_data[_value_count - 1] = 0;
				--_value_count;
			}
		}

	// private:
		pointer			_value_data;
		size_t			_value_size;
		size_t			_value_count;
		size_t			_value_chunk_size;	// will be used for optimisation
		Allocator		_allocator;

	}; // vector _______________________________________________________________

} // namespace ft ______________________________________________________________

#endif
