/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:36:08 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/18 03:03:28 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITERATOR_H
# define ITERATOR_H

# include <iostream>
# include <type_traits>

namespace ft
{
	//// TO DO after iterator_traits :
	//// class __normal_iterator;

	/// iterator_tags: empty types, used to distinguish different iterators.
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	// makes creation of iterator faster
	template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
	typename _Pointer = _Tp*, typename _Reference = _Tp&>
	struct iterator
	{
		typedef _Category	iterator_category;
		typedef _Tp			value_type;
		typedef _Distance	difference_type;
		typedef _Pointer	pointer;
		typedef _Reference	reference;
	};


	template<typename _Iterator>
	struct iterator_traits
	{
		typedef typename _Iterator::iterator_category	iterator_category;
		typedef typename _Iterator::value_type			value_type;
		typedef typename _Iterator::difference_type		difference_type;
		typedef typename _Iterator::pointer				pointer;
		typedef typename _Iterator::reference			reference;
	};

  /// Partial specialization for pointer types.
  template<typename _Tp>
	struct iterator_traits<_Tp*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef _Tp							value_type;
		typedef ptrdiff_t					difference_type;
		typedef _Tp*						pointer;
		typedef _Tp&						reference;
	};

  /// Partial specialization for const pointer types.
  template<typename _Tp>
	struct iterator_traits<const _Tp*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef _Tp							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const _Tp*					pointer;
		typedef const _Tp&					reference;
	};


	// template< class Iter >
	// struct iterator_traits< Iter * >
	// {
	// public:
	// 	typedef typename Iter::value_type			value_type;
	// 	typedef typename Iter::pointer				pointer;
	// 	typedef typename Iter::reference			reference;
	// 	typedef typename Iter::difference_type		difference_type;
	// 	typedef typename Iter::iterator_category 	iterator_category;

	// 	// iterator_traits() : iterator_traits<Iter>() {}
	// 	// iterator_traits(const iterator_traits & copy) : iterator_traits<Iter>(copy) {}
	// 	// virtual ~iterator_traits() { ~iterator_traits<Iter>(); }
	// 	// iterator_traits & operator= (const Iter& rhs) { return Iter::operator=(rhs); }
	// };


	// template< class T >
	// struct iterator_traits
	// {
	// public:
	// 	typedef T								value_type;
	// 	typedef value_type *					pointer;
	// 	typedef value_type &					reference;
	// 	typedef typename std::ptrdiff_t			difference_type;
	// 	typedef std::random_access_iterator_tag	iterator_category;

	// 	// typedef iterator<const T>		const_iterator;

	// 	/// Member functions
	// 	iterator_traits() {}
	// 	// iterator(const_reference x_ptr) : _ptr(x_ptr._ptr) {}	// cpp11 : = default;
	// 	// iterator(pointer x_t) : _ptr(x_t) {}

	// 	// template <bool WasConst, class = std::enable_if<IsConst && !WasConst>>
	// 	// iterator(const iterator<T, WasConst> &rhs) : _ptr(rhs._ptr) {}

	// 	virtual	~iterator_traits() {}

	// 	/// Member Operators
	// 	iterator_traits &operator=(const iterator_traits &rhs) { _ptr = rhs._ptr; return (*this);	}

	// 	/// Non Member Operators

	// 	///   Random access vvv
	// 	// vector_iterator operator+(difference_type rhs)	{ vector_iterator	it(_ptr + rhs); return (it);		}	// optional
	// 	// vector_iterator operator-(difference_type rhs)	{ vector_iterator	it(_ptr - rhs); return (it);		}	// optional
	// 	// difference_type operator-(vector_iterator rhs)	{ difference_type	df(_ptr - rhs._ptr); return (df);	}	// optional

	// 	///  Dereference
	// 	// reference		operator* () { return (*_ptr); }
	// 	// const_reference	operator* () const { return (*_ptr); }	// const_iterator
	// 	// pointer			operator->() { return (_ptr); }
	// 	// const_pointer	operator->() const { return (_ptr); }	// const_iterator
	// 	// reference		operator[](difference_type rhs) { return (*(_ptr + rhs)); }			// optional
	// 	// const_reference	operator[](difference_type rhs) const { return (*(_ptr + rhs)); }	// const_iterator // optional

	// 	/// Equality Operators
	// 	// bool	operator==(const iterator &rhs) const	{ return (_ptr == rhs._ptr); }
	// 	// bool	operator!=(const iterator &rhs) const	{ return (_ptr != rhs._ptr); }
	// 	// bool	operator<=(const iterator &rhs) const	{ return (_ptr <= rhs._ptr); }	// optional
	// 	// bool	operator>=(const iterator &rhs) const	{ return (_ptr >= rhs._ptr); }	// optional
	// 	// bool	operator< (const iterator &rhs)	const	{ return (_ptr < rhs._ptr);  }	// optional
	// 	// bool	operator> (const iterator &rhs)	const	{ return (_ptr > rhs._ptr);  }	// optional

	// 	///  Arithmetic Operators

	// 	///   Pre
	// 	// iterator	&operator++() { ++(this->_ptr); return (*this);	}
	// 	// iterator	&operator--() { --(this->_ptr); return (*this);	}	// optional
	// 	///   Post
	// 	// iterator	operator++(int){ iterator tmp = *this; ++(this->_ptr); return (tmp);	}	// optional
	// 	// iterator	operator--(int){ iterator tmp = *this; --(this->_ptr); return (tmp);	}	// optional
	// 	///   Assignation
	// 	// void		operator+=(difference_type rhs) { _ptr += rhs; }	// optional
	// 	// void		operator-=(difference_type rhs) { _ptr -= rhs; }	// optional

	// private:
	// 	pointer _ptr;
	// };

};


#endif

// R & D

	// template <bool IsConst>
	// class MyIterator
	// {
	// 	int *d_;

	// public:
	// 	MyIterator(const MyIterator &) = default;				// c++11
	// 	MyIterator &operator=(const MyIterator &) = default;	// c++11

	// 	template <bool WasConst, class = std::enable_if_t<IsConst && !WasConst>>
	// 	MyIterator(const MyIterator<WasConst> &rhs) : d_(rhs.d_) {}

	// 	template <bool WasConst, class = std::enable_if_t<IsConst && !WasConst>>
	// 	MyIterator &operator=(const MyIterator<WasConst> &rhs)
	// 	{
	// 		d_ = rhs.d_;
	// 		return *this;
	// 	}
	// };

	// template <bool B, class T = void>
	// struct enable_if
	// {
	// };

	// template <class T>
	// struct enable_if<true, T>
	// {
	// 	typedef T type;
	// };

	// template <typename T, bool IsConst>