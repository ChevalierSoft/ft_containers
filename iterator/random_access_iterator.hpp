#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.h"

namespace ft
{
	/// random_access_iterator _________________________________________________
	template <typename T>
	class random_access_iterator : public ft::random_access_iterator_tag //_____
	{
	public:
		typedef T											value_type;
		typedef value_type *								pointer;
		typedef const value_type 							const_pointer;
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef typename std::ptrdiff_t						difference_type;

		typedef ft::random_access_iterator<T>				iterator;
		typedef ft::random_access_iterator<T>				vector_iterator;

		typedef typename ft::random_access_iterator_tag 	iterator_category;

		random_access_iterator() {}
		random_access_iterator(pointer x_t) : _ptr(x_t) {}
		// random_access_iterator(const difference_type rhs) : ft::iterator<T>(rhs) {}
		~random_access_iterator() {}
		/// Member Operators
		random_access_iterator	&operator= (const random_access_iterator &rhs)	{	_ptr = rhs._ptr; return (*this);	}

		/// Equality Operators
		bool	operator==(const random_access_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool	operator!=(const random_access_iterator &rhs) const	{ return (_ptr != rhs._ptr); }
		bool	operator<=(const random_access_iterator &rhs) const	{ return (_ptr <= rhs._ptr); }
		bool	operator>=(const random_access_iterator &rhs) const	{ return (_ptr >= rhs._ptr); }
		bool	operator< (const random_access_iterator &rhs) const	{ return (_ptr < rhs._ptr);  }
		bool	operator> (const random_access_iterator &rhs) const	{ return (_ptr > rhs._ptr);  }

		///  Dereferense
		reference		operator[](difference_type rhs)			{ return (*(_ptr + rhs)); }
		const_reference	operator[](difference_type rhs) const	{ return (*(_ptr + rhs)); }

		///   Random access vvv
		random_access_iterator	operator+ (difference_type rhs)	{ random_access_iterator	it(_ptr + rhs); return (it);		}
		random_access_iterator	operator- (difference_type rhs)	{ random_access_iterator	it(_ptr - rhs); return (it);		}
		difference_type	operator- (random_access_iterator rhs)	{ difference_type	df(_ptr - rhs._ptr); return (df);	}

		///   Pre
		random_access_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		random_access_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		///   Post
		random_access_iterator	operator++(int)	{ random_access_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		random_access_iterator	operator--(int) { random_access_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		// operator	random_access_iterator<const T> {	return random_access_iterator<const T>(_ptr);	}	// conversion from const iterator to iterator

		reference		operator* ()	{ return (*_ptr); }

	// private:
		pointer _ptr;

	};	// random_access_iterator ______________________________________________
}

#endif
