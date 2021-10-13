/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/13 05:21:37 by dait-atm         ###   ########.fr       */
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
#include "../utils/enable_if.hpp"

#define __DEB(s) std::cerr<<s<<std::endl;

/*
must be reimplemented :
	iterator_traits,					// ok
	reverse_iterator,					// ok
	enable_if,							// ok
	is_integral,						// ok
	equal/lexicographical com-pare, 	// ok
	std::pair,							//
	std::make_pair						//
*/

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector /// * ___________________________________________________________
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
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		/// * Constructors & Destructors _________________________________________
		// ? https://cplusplus.com/reference/vector/vector/vector/

		// ? default (1)
		explicit vector(const allocator_type& alloc = allocator_type()) : _value_data(NULL), _value_count(0), _value_chunk_size(0), _allocator(alloc) {}

		// ? fill (2)
		explicit vector(difference_type nb, const T & elem = value_type(), const allocator_type& alloc = allocator_type()) : _value_data(NULL), _value_count(0), _value_chunk_size(0), _allocator(alloc) // : vector() // c++11
		{
			for (int i = 0; i < nb; ++i)
				this->push_back(elem);
		}

		// ? range (3)
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if< ! ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) : _value_data(NULL), _value_count(0), _value_chunk_size(0), _allocator(alloc)
		{
			assign(first, last);
		}

		// ? copy (4)
		vector(const vector<T> & copy)
		{
			_allocator = copy.get_allocator();
			_value_data = _allocator.allocate(copy.capacity());
			std::copy(&copy._value_data[0], &copy._value_data[copy._value_count], _value_data);
			_value_count = copy._value_count;
			_value_chunk_size = copy._value_chunk_size;
		}

		// initializer list (6)
		// vector(std::initializer_list<T> list) : vector()				// c++11
		// {
		// 	for (auto l : list) {
		// 		this->push_back(l);
		// 	}
		// }

		virtual ~vector()
		{
			// std::cout <<RED<< "vector destructor" <<RST<< std::endl;
			this->clear();
			_allocator.deallocate(_value_data, _value_chunk_size);
		}

		vector					&operator=(vector<T> const &copy)
		{
			if (_value_chunk_size < copy.capacity())
			{
				_allocator.deallocate(_value_data, _value_chunk_size);
				_value_data = _allocator.allocate(_value_chunk_size = copy.size());
			}
			for (size_type i = 0; i < copy.size(); ++i)
				_allocator.construct(_value_data + i, copy._value_data[i]);
			_value_count = copy.size();
			return (*this);
		}

		/// * assign() & get_allocator() _________________________________________
		
		void					assign(size_type count, const T& value)
		{
			if (count > this->max_size())
				throw std::length_error("cannot create ft::vector larger than max_size()");
			// if (this->capacity() < count)
			// {
				_allocator.deallocate(_value_data, _value_count);
				_value_data = _allocator.allocate(count);
				_value_chunk_size = count;
			// }
			// else
			// {
			// 	for (size_type i = 0; i < this->size(); ++i)
			// 		_allocator.destroy(_value_data + i);
			// }
			for (size_type i = 0; i < count; ++i)
				_value_data[i] = value;

			_value_count = count;

		}

		template<class InputIterator>
		void					assign(InputIterator first, InputIterator last,
									typename ft::enable_if< ! ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		{
			size_type	i;
			pointer		tmp;
			long		count = ft::distance(first, last);
			// std::cout << "count : " << count << std::endl;

			if (count > this->max_size())
				throw std::length_error("cannot create ft::vector larger than max_size()");
			
			tmp = _allocator.allocate(count);
			i = 0;
			for (InputIterator start = first; start != last; ++start, ++i)
				_allocator.construct(tmp + i, *start);

			_allocator.deallocate(_value_data, _value_count);
			_value_data = tmp;
			_value_count = count;
			_value_chunk_size = count;

		}
		
		allocator_type			get_allocator() const { return this->_allocator; }

		/// * Element access _____________________________________________________

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

		reference				operator[]( size_type pos )			{	return (_value_data[pos]);	}

		const_reference			operator[]( size_type pos ) const	{	return (_value_data[pos]);	}

		reference				front() 		{	return (*begin());		}

		const_reference			front() const	{	return (*begin());		}

		reference				back()			{	return (_value_data[_value_count -1]);		}

		const_reference			back() const	{	return (_value_data[_value_count -1]);		}

		pointer					data()			{	return (_value_data);	}	// c++11
		
		const_pointer			data() const	{	return (_value_data);	}	// c++11

		/// * Iterators __________________________________________________________

		iterator				begin() 		{ return ( _value_data );					}

		iterator				end() 			{ return ( _value_data + _value_count );	}

		const_iterator			begin() const	{ return ( _value_data );					}

		const_iterator			end() const		{ return ( _value_data + _value_count );	}

		reverse_iterator		rbegin() 		{ return reverse_iterator( _value_data + _value_count - 1 );}

		reverse_iterator		rend() 			{ return reverse_iterator( _value_data - 1 );				}

		const_reverse_iterator	rbegin() const	{ return const_reverse_iterator( _value_data + _value_count - 1 );	}

		const_reverse_iterator	rend() const	{ return const_reverse_iterator( _value_data - 1 );			}

		/// * Capacity ___________________________________________________________

		bool					empty() const		{ return ( _value_count == 0 );			}

		size_type				size() const		{ return ( _value_count );				}

		size_type				max_size() const	{ return this->_allocator.max_size();	}	// ? deprecated in C++17

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
				_allocator.destroy(_value_data + i);					// call destructor but don't clean the memory
			}
			_allocator.deallocate(_value_data, _value_count);			// free up _value_data's memory space
			_value_data = tmp;
		}

		size_type				capacity() const	{ return ( _value_count * sizeof(T) );}

		/// * Modifiers __________________________________________________________

		void					clear()
		{
			for (difference_type i = 0; i < _value_count; ++i)
				_allocator.destroy(&_value_data[i]);
			_value_count = 0;
		}

		// ? insert single element (1)
		iterator				insert(iterator position, const value_type & val)
		{
			bool			at_the_end;
			const size_type	elem_position = position - begin();

			at_the_end = (position == end()) ? true : false;

			// * checking vector's capacity
			if (_value_count >= _value_chunk_size)
				reserve(_value_chunk_size * 2);
			if (at_the_end)
			{
				_allocator.construct(_value_data + _value_count, val);
				++_value_count;
			}
			else
			{
				// * move every elemets by 1 to the right from the end to elem_position
				for (size_type i = _value_count; i > elem_position; --i)
					_value_data[i] = _value_data[i - 1];
				// * add the value at position
				_value_data[elem_position] = val;
				++_value_count;
			}
			return (_value_data + elem_position);
		}

		// ? insert n times (2)
		void					insert(iterator position, size_type nb_elem, const value_type &val)
		{
			bool		at_the_end;
			long		pbeg = position - begin();

			if (nb_elem < 1)
				return ;

			at_the_end = (position == end()) ? true : false;

			// * check if the vector needs to be resized
			if (_value_count + nb_elem > _value_chunk_size)
			{
				do
				{
					_value_chunk_size = _value_chunk_size ? _value_chunk_size * 2 : 1;
				} while (_value_count + nb_elem > _value_chunk_size);
				reserve(_value_chunk_size);
			}
			
			if (at_the_end)
			{
				for (size_type i = 0; i < nb_elem; ++i)
				{
					_allocator.construct(_value_data + _value_count, val);
					++_value_count;
				}
			}
			else
			{
				// * straff the content from position to nb_elem backward
				for (long j = _value_count; j >= pbeg; --j)
					_value_data[j + nb_elem] = _value_data[j];
				_value_count += nb_elem;
				// * add nb_elem time val, starting from pbeg
				for (long i = 0; i < nb_elem; ++i)
					_value_data[pbeg + i] = val;
			}
		}

		// ? insert by range (3)
		template <class InputIterator>
		void					insert(iterator position, InputIterator first,
									typename ft::enable_if< ! ft::is_integral<InputIterator>::value, InputIterator>::type last)
		{
			long			nb_elem;
			long			new_size = _value_count;
			long			pbeg = position - begin();
			size_type		i;
			pointer			tmp;						// this will replace _value_data
			
			// * get nb_elem
			nb_elem = ft::distance(first, last);

			// * get new size (can be the same)
			if (new_size < _value_count + nb_elem)
			{
				do
				{
					new_size = new_size ? new_size * 2 : 1;
				} while (new_size < _value_count + nb_elem);
			}

			tmp = _allocator.allocate(new_size);
			
			// * copy _value_data from begin() to position
			i = 0;
			for (; i < pbeg; ++i)
				_allocator.construct(tmp + i, _value_data[i]);

			// * copy the asked content (nb_elem will be copied)
			for (InputIterator start = first; start != last; ++start, ++i)
				_allocator.construct(tmp + i, *start);

			// * copy from position to _value_count
			for (; i - nb_elem < _value_count; ++i)
				_allocator.construct(tmp + i, _value_data[i - nb_elem]);

			// * _value_data becomes tmp
			_allocator.deallocate(_value_data, _value_count);
			_value_data = tmp;
			_value_count = i;

		}

		iterator				erase(iterator position)
		{
			value_type	pos = position - begin();

			for (int i = pos; i < _value_count - 1; ++i)
			{
				_allocator.destroy(_value_data + i);
				_allocator.construct(_value_data + i, _value_data[i + 1]);
			}
			_allocator.destroy(_value_data + _value_count - 1);
			--_value_count;
			return (position);
		}
		
		// ! Error here. see the lasts tests in test_vector
		iterator				erase(iterator first, iterator last)
		{
			long	dist = ft::distance(first, last);
			long	pos = first - begin();
			long	end_pos = end() - last;

			// __DEB("erase (2)")
			if (dist == 0)
				return (last);


			// __DEB("delete from first to last")
			for (long i = pos; i < pos + dist; ++i)
				_allocator.destroy(_value_data + i);

			// __DEB("move last element at first position recurcively")
			if (last != end())
			{
				// int d = 0;
				while (last != end() - 1)
				{
					// d = end() - last - 1;
					// __DEB(d)
					*first = *last;	
					++first;
					++last;
				}
			}
			
			// __DEB("destroy last part of the vector")
			for (long j = end_pos; j < _value_count; ++j)
			{
				// std::cout << "j : " << j << std::endl;
				_allocator.destroy(_value_data + j);
			}
			_value_count -= dist;
			
			// __DEB("return new first position")
			return (first);
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

		void resize (size_type n, value_type val = value_type())
		{
			// __DEB("resize()")
			if (n == _value_count)
				return ;
			else if (n < _value_count)
			{
				// __DEB("n < capacity")
				size_type bpos = (begin() + n) - begin();
				// __DEB("destroying elements from n to end() position")
				for (size_type i = n; i != _value_count; ++i)
					_allocator.destroy(_value_data + i);
			}
			else
			{
				if (n > _value_chunk_size)
				{
					do
					{
						_value_chunk_size = _value_chunk_size ? _value_chunk_size * 2 : 1;
					} while (n > _value_chunk_size);
					this->reserve(_value_chunk_size);
				}
				// ? in c++11 resize call each time the constructor
				for (size_type i = _value_count; i < n; ++i)
					_allocator.construct(_value_data + i, val);
			}
			_value_count = n;
		}

		void					swap (vector& x)
		{
			pointer		tmp_data;
			size_type	tmp_count;
			size_type	tmp_chunk_size;

			tmp_data = x._value_data;
			x._value_data = _value_data;
			_value_data = tmp_data;

			tmp_count = x._value_count;
			x._value_count = _value_count;
			_value_count = tmp_count;

			tmp_chunk_size = x._value_chunk_size;
			x._value_chunk_size = _value_chunk_size;
			_value_chunk_size = tmp_chunk_size;
		}

		/// * Variables __________________________________________________________
	private:
		pointer			_value_data;
		size_type		_value_size;
		size_type		_value_count;
		size_type		_value_chunk_size;
		Allocator		_allocator;

	}; /// * vector ______________________________________________________________

	/// * Non-member functions ___________________________________________________
	//  ? https://en.cppreference.com/w/cpp/container/vector/operator_cmp

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

} /// * namespace ft _____________________________________________________________

#endif
