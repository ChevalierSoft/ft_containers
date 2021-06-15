/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:36:08 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/15 15:31:55 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITERATOR_H
# define ITERATOR_H

#include <iostream>

namespace ft
{
	template <typename T>
	class iterator
	{
	public:
		typedef T value_type;
		typedef value_type *pointer;
		typedef const value_type const_pointer;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename std::ptrdiff_t difference_type;

		/// Member functions
		iterator() {}
		iterator(pointer x_t) : _ptr(x_t) {}
		virtual ~iterator() {}
		iterator(iterator &x_ptr) : _ptr(x_ptr._ptr) {}

		/// Member Operators
		iterator &operator=(const iterator &rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		}

		/// Non Member Operators
		///  Dereference
		reference operator*() { return (*_ptr); }
		const_reference operator*() const { return (*_ptr); }
		pointer operator->() { return (_ptr); }
		const_pointer operator->() const { return (_ptr); }
		reference operator[](difference_type rhs) { return (*(_ptr + rhs)); }
		const_reference operator[](difference_type rhs) const { return (*(_ptr + rhs)); }

		/// Equality Operators
		bool operator==(const iterator &rhs) const { return (_ptr == rhs._ptr); }
		bool operator!=(const iterator &rhs) const { return (_ptr != rhs._ptr); }
		bool operator<=(const iterator &rhs) const { return (_ptr <= rhs._ptr); }
		bool operator>=(const iterator &rhs) const { return (_ptr >= rhs._ptr); }
		bool operator<(const iterator &rhs) const { return (_ptr < rhs._ptr); }
		bool operator>(const iterator &rhs) const { return (_ptr > rhs._ptr); }

		///  Arithmetic Operators
		///   Random access vvv
		iterator operator+(difference_type rhs) { return iterator(_ptr + rhs); }
		iterator operator-(difference_type rhs) { return iterator(_ptr - rhs); }
		difference_type operator-(iterator rhs) { return iterator(_ptr - rhs._ptr); }

		///   Pre
		iterator &operator++()
		{
			++(this->_ptr);
			return (*this);
		}
		iterator &operator--()
		{
			--(this->_ptr);
			return (*this);
		}
		///   Post
		iterator operator++(int)
		{
			iterator tmp = *this;
			++(this->_ptr);
			return (tmp);
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			--(this->_ptr);
			return (tmp);
		}
		///   Assignation
		void operator+=(difference_type rhs) { _ptr += rhs; }
		void operator-=(difference_type rhs) { _ptr -= rhs; }

	private:
		pointer _ptr;
	};

	template <typename T>
	class const_iterator
	{
	public:
		typedef T value_type;
		typedef value_type *pointer;
		typedef const value_type const_pointer;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename std::ptrdiff_t difference_type;

		/// Member functions
		const_iterator() {}
		const_iterator(pointer x_t) : _ptr(x_t) {}
		const_iterator(const const_iterator &x_ptr) : _ptr(x_ptr._ptr) {}
		const_iterator(const iterator<T> &x_vit) : _ptr(x_vit) {}
		virtual ~const_iterator() {}

		/// Member Operators
		const_iterator &operator=(const const_iterator &rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		}

		/// Non Member Operators
		///  Dereference
		const_reference operator*() const { return (*_ptr); }
		const_pointer operator->() const { return (_ptr); }
		const_reference operator[](difference_type rhs) const { return (*(_ptr + rhs)); }

		/// Equality Operators
		bool operator==(const const_iterator &rhs) const { return (_ptr == rhs._ptr); }
		bool operator!=(const const_iterator &rhs) const { return (_ptr != rhs._ptr); }
		bool operator<=(const const_iterator &rhs) const { return (_ptr <= rhs._ptr); }
		bool operator>=(const const_iterator &rhs) const { return (_ptr >= rhs._ptr); }
		bool operator<(const const_iterator &rhs) const { return (_ptr < rhs._ptr); }
		bool operator>(const const_iterator &rhs) const { return (_ptr > rhs._ptr); }

		///  Arithmetic Operators
		const_iterator	operator+(difference_type rhs) { return const_iterator(_ptr + rhs); }
		const_iterator	operator-(difference_type rhs) { return const_iterator(_ptr - rhs); }
		difference_type	operator-(iterator<T> rhs) { return iterator<T>(_ptr - rhs._ptr); }

		///   Pre
		const_iterator &operator++()
		{
			++(this->_ptr);
			return (*this);
		}
		const_iterator &operator--()
		{
			--(this->_ptr);
			return (*this);
		}
		///   Post
		const_iterator operator++(int)
		{
			const_iterator tmp = *this;
			++(this->_ptr);
			return (tmp);
		}
		const_iterator operator--(int)
		{
			const_iterator tmp = *this;
			--(this->_ptr);
			return (tmp);
		}
		///   Assignation
		void operator+=(difference_type rhs) { _ptr += rhs; }
		void operator-=(difference_type rhs) { _ptr -= rhs; }

	private:
		pointer _ptr;
	};

};


#endif
