/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/06 18:07:30 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cmath>
#include "../iterator/iterator.h"
#include "../iterator/random_access_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../utils/color.h"
#include "../utils/ft_print_memory.h"
#include "../utils/utils.hpp"

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
		typedef T										value_type;
		typedef value_type *							pointer;
		typedef const value_type * 						const_pointer;
		typedef value_type &							reference;
		typedef const value_type &						const_reference;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef Allocator								allocator_type;
		typedef ft::random_access_iterator<T>			iterator;
		typedef ft::random_access_iterator<const T>		const_iterator;
		// typedef ft::reverse_iterator<T>				reverse_iterator;
		// typedef ft::reverse_iterator<const T>		const_reverse_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		/// Constructors & Destructors _________________________________________

		vector() : _value_data(NULL), _value_size(sizeof(T)), _value_count(0), _value_chunk_size(0) {}

		// vector(std::initializer_list<T> list) : vector()				// c++11
		// {
		// 	for (auto l : list) {
		// 		this->push_back(l);
		// 	}
		// }

		vector(difference_type nb, const T & elem) : vector()
		{
			for (int i = 0; i < nb; ++i)
				this->push_back(elem);
		}

		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last,
		// 	const allocator_type& alloc = allocator_type())
		// {
		// }

		vector(const vector<T> & copy)
		{
			_allocator = copy.get_allocator();
			_value_data = _allocator.allocate(copy._value_size * copy._value_chunk_size);
			std::copy(&copy._value_data[0], &copy._value_data[copy._value_count], _value_data);
			_value_count = copy._value_count;
			_value_size  = copy._value_size;
			_value_chunk_size = copy._value_chunk_size;
		}

		virtual ~vector()
		{
			// std::cout <<RED<< "vector destructor" <<RST<< std::endl;
			this->clear();
			_allocator.deallocate(_value_data, _value_chunk_size);
		}

		vector<T> &				operator= (vector<T> & copy)	// should be const
		{
			iterator i;	// this
			iterator j;	// copy

			if (*this == copy)
				return (*this);

			this->clear();
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

			return (*this);
		}

		/// assign() & get_allocator() _________________________________________
		allocator_type			get_allocator() const { return this->_allocator; }

		/// Element access _____________________________________________________

		reference				at( size_type pos )
		{
			if (pos <= 0 || pos >= _value_count)
				throw std::out_of_range("vector::_M_range_check: __n (which is "+ ft::to_string(pos) + ") >= this->size() (which is " + ft::to_string(_value_count) + ")");
			return (_value_data[pos]);
		}

		const_reference			at( size_type pos ) const
		{
			if (pos <= 0 || pos >= _value_count)
				throw std::out_of_range("vector::_M_range_check: __n (which is "+ ft::to_string(pos) + ") >= this->size() (which is " + ft::to_string(_value_count) + ")");
			return (_value_data[pos]);
		}

		reference				front() 		{	return (*begin());		}

		const_reference			front() const	{	return (*begin());		}

		reference				back()			{	return (_value_data[_value_count -1]);		}

		const_reference			back() const	{	return (_value_data[_value_count -1]);		}

		// pointer					data()			{	return (_value_data);	}	// c++11
		// const_pointer			data() const	{	return (_value_data);	}	// c++11

		/// Iterators __________________________________________________________

		iterator				begin() 		{ return ( _value_data );					}

		iterator				end() 			{ return ( _value_data + _value_count );	}

		const_iterator			begin() const	{ return ( _value_data );					}

		const_iterator			end() const		{ return ( _value_data + _value_count );	}

		reverse_iterator		rbegin() 		{ return reverse_iterator( _value_data + _value_count - 1 );}

		reverse_iterator		rend() 			{ return reverse_iterator( _value_data - 1 );				}

		const_reverse_iterator	rbegin() const	{ return const_reverse_iterator( _value_data + _value_count - 1 );	}

		const_reverse_iterator	rend() const	{ return const_reverse_iterator( _value_data - 1 );			}

		/// Capacity ___________________________________________________________

		bool					empty() const		{ return ( _value_count == 0 );			}

		size_type				size() const		{ return ( _value_count );				}

		size_type				max_size() const	{ return this->_allocator.max_size();	} // deprecated in C++17


		void					reserve(size_type new_cap)
		{
			if (new_cap > max_size())
				throw std::length_error("std::bad_alloc");
			else if (!new_cap)
				_value_chunk_size = 4;
			if (new_cap > _value_chunk_size)
				_value_chunk_size = new_cap;
			pointer tmp = _allocator.allocate(_value_chunk_size);		// allocate _value_chunk_size * sizeof(_allocator::value_type)
			for (size_type i = 0; i < _value_count; ++i)
			{
				_allocator.construct(tmp + i, _value_data[i]);			// create a copy in _value_data without calling the constructor
				_allocator.destroy(&_value_data[i]);					// call destructor but don't clean the memory
			}
			_allocator.deallocate(_value_data, _value_count);			// free up _value_data's memory space
			_value_data = tmp;
		}

		size_type				capacity() const	{ return ( _value_count * _value_size );}

		/// Modifiers __________________________________________________________

		void					clear()
		{
			for (ptrdiff_t i = 0; i < _value_count; ++i)
				_allocator.destroy(&_value_data[i]);
			_value_count = 0;
		}

		// insert single element
		iterator				insert(iterator position, const value_type & val)
		{
			bool			at_the_end;
			const size_type	_n = position - begin();

			at_the_end = (position == end()) ? true : false;

			if (_value_count >= _value_chunk_size)
				reserve(_value_chunk_size * 2);
			if (at_the_end)
			{
				_allocator.construct(_value_data + _value_count, val);
				++_value_count;
			}
			else
			{
				for (size_type i = _value_count; i > _n; --i)
					_value_data[i] = _value_data[i - 1];
				_value_data[_n] = val;
				++_value_count;
			}
			return (_value_data + _n);
		}

		// insert n time
		void					insert(iterator position, size_type nfill, const value_type &val)
		{
			bool		at_the_end;
			long		pbeg = position - begin();

			if (nfill < 1)
				return ;

			at_the_end = (position == end()) ? true : false;

			if (_value_count + nfill >= _value_chunk_size)
			{
				do
				{
					_value_chunk_size *= 2;
				} while (_value_count + nfill >= _value_chunk_size);
				reserve(_value_chunk_size);
			}
			
			if (at_the_end)
			{
				for (size_type i = 0; i < nfill; ++i)
				{
					_allocator.construct(_value_data + _value_count, val);
					++_value_count;
				}
			}
			else
			{
				for (long j = _value_count; j >= pbeg; --j)
					_value_data[j + nfill] = _value_data[j];
				_value_count += nfill;
				for (long i = 0; i < nfill; ++i)
					_value_data[pbeg + i] = val;
			}
		}

		// insert by range
		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last)
		{
			bool		at_the_end;
			long		pbeg = position - begin();
			size_type	__n = last - first;

			if (__n < 1)
				return ;

			at_the_end = (position == end()) ? true : false;

			if (_value_count + __n >= _value_chunk_size)
			{
				do
				{
					_value_chunk_size *= 2;
				} while (_value_count + __n >= _value_chunk_size);
				reserve(_value_chunk_size);
			}

			if (at_the_end)
			{
				// std::cout << "end" << std::endl;
				for (size_type i = 0; i < __n; ++i)
				{
					// _allocator.construct(_value_data + _value_count, *first);
					_value_data[_value_count + i] = *first;
					++first;
					++position;
				}
				_value_count += __n;
			}
			else
			{
				for (long j = _value_count; j >= pbeg; --j)
					_value_data[j + __n] = _value_data[j];
				_value_count += __n;
				for (size_type i = 0; i < __n; ++i)
				{
					// _allocator.construct(_value_data + _value_count, *first);
					_value_data[_value_count + i] = *first;
					++first;
					++position;
				}
			}

		}

		void					push_back(const T & rhs)
		{
			static bool		first_push_back = true;
			pointer			data;

			if (_value_count >= _value_chunk_size)
				reserve(_value_chunk_size * 2);
			_allocator.construct(_value_data + _value_count, rhs);		// create a copy in _value_data without calling the constructor
			++_value_count;
		}

		void					pop_back()
		{
			if (_value_count > 0)
			{
				_allocator.destroy(&_value_data[_value_count - 1]);		// call destructor but don't clean the memory (deprecated since c++17)
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

	/// Non-member functions ___________________________________________________
	//   https://en.cppreference.com/w/cpp/container/vector/operator_cmp
	template< class T, class Alloc >
	bool operator==( const ft::vector<T, Alloc>& lhs,
					const ft::vector<T, Alloc>& rhs )
	{
		typename ft::vector<T, Alloc>::const_iterator il;
		typename ft::vector<T, Alloc>::const_iterator ir;

		if (lhs.size() != rhs.size())
			return (false);
		il = lhs.begin();
		ir = rhs.begin();
		while (il != lhs.end())
		{
			if (ir == rhs.end() || *il != *ir)
				return (false);
			++il;
			++ir;
		}
		return (true);
	}

	template< class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
	{
		return ( !(lhs == rhs) );
	}

	template< class T, class Alloc >
	bool operator< ( const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
	{
		return ( ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) );
	}

	template< class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
	{
		if ( lhs < rhs || lhs == rhs )
			return (true);
		return (false);
	}

	template< class T, class Alloc >
	bool operator> ( const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
	{
		return ( ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) );
	}

	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
	{
		if ( lhs > rhs || lhs == rhs )
			return (true);
		return (false);
	}

} // namespace ft ______________________________________________________________


#endif
