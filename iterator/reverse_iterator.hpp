#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.h"

namespace ft
{
	/// reverse_iterator _______________________________________________________
	template <typename T>
	class reverse_iterator : public ft::random_access_iterator_tag //___________
	{
	public:
		typedef T											value_type;
		typedef value_type *								pointer;
		typedef const value_type 							const_pointer;
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef typename std::ptrdiff_t						difference_type;

		typedef ft::reverse_iterator<T>						iterator;
		typedef ft::reverse_iterator<T>						vector_iterator;

		typedef typename ft::random_access_iterator_tag 		iterator_category;

		reverse_iterator() {}
		reverse_iterator(pointer x_t) : _ptr(x_t) {}
		// reverse_iterator(const difference_type rhs) : ft::iterator<T>(rhs) {}
		~reverse_iterator() {}
		/// Member Operators
		reverse_iterator	&operator= (const reverse_iterator<T> &rhs)	{	_ptr = rhs._ptr; return (*this);	}

		/// Equality Operators
		bool	operator==(const reverse_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool	operator!=(const reverse_iterator &rhs) const	{ return (_ptr != rhs._ptr); }
		bool	operator<=(const reverse_iterator &rhs) const	{ return (_ptr <= rhs._ptr); }
		bool	operator>=(const reverse_iterator &rhs) const	{ return (_ptr >= rhs._ptr); }
		bool	operator< (const reverse_iterator &rhs) const	{ return (_ptr < rhs._ptr);  }
		bool	operator> (const reverse_iterator &rhs) const	{ return (_ptr > rhs._ptr);  }

		///  Dereferense
		reference			operator[](difference_type rhs)			{ return (*(_ptr + rhs)); }
		const_reference		operator[](difference_type rhs) const	{ return (*(_ptr + rhs)); }

		///   Random access vvv
		reverse_iterator	operator+ (difference_type rhs)			{ reverse_iterator	it(_ptr + rhs); return (it);		}
		reverse_iterator	operator- (difference_type rhs)			{ reverse_iterator	it(_ptr - rhs); return (it);		}
		difference_type		operator- (reverse_iterator rhs)		{ difference_type	df(_ptr - rhs._ptr); return (df);	}

		///   Pre
		reverse_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		reverse_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		///   Post
		reverse_iterator	operator++(int)	{ reverse_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		reverse_iterator	operator--(int) { reverse_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		// operator	reverse_iterator<const T> {	return reverse_iterator<const T>(_ptr);	}	// conversion from const iterator to iterator

		reference		operator* ()	{ return (*_ptr); }

	// private:
		pointer _ptr;

	};	// reverse_iterator ______________________________________________
}

#endif
