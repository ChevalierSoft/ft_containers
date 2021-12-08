#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.h"
#include "../utils/enable_if.hpp"

namespace ft
{
	/// * random_access_iterator ____________________________________________________________
	//  ? http://www.cplusplus.com/reference/iterator/
	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
	public:
		/// * Type definition _______________________________________________________________
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
		typedef value_type *								pointer;
		typedef const value_type 							const_pointer;
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
		typedef ft::random_access_iterator<T>				iterator;
		typedef ft::random_access_iterator<T>				vector_iterator;
		typedef ft::random_access_iterator<T>				iterator_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		/// * Constructors / Destructor _____________________________________________________

		explicit random_access_iterator() {}

		explicit random_access_iterator(pointer x_t) : _ptr(x_t) {}
		
		random_access_iterator(const ft::random_access_iterator<T> &rhs) { *this = rhs; }

		// ? allows conversion between iterator of T to const T
		operator random_access_iterator<const T>() const { return (random_access_iterator<const T>(_ptr)); }

		~random_access_iterator() {}

		/// * Member Operators _______________________________________________________________
		// template <typename U>
		// random_access_iterator&	operator= (const random_access_iterator<U> &rhs) { _ptr = rhs.base(); return (*this); }
		random_access_iterator&	operator= (const random_access_iterator<T> &rhs) { _ptr = rhs.base(); return (*this); }

		/// * Equality Operators _____________________________________________________________

		bool					operator==(const random_access_iterator<const T> &rhs) const	{ return (_ptr == rhs.base()); }
		bool					operator!=(const random_access_iterator<const T> &rhs) const	{ return (_ptr != rhs.base()); }
		bool					operator<=(const random_access_iterator<const T> &rhs) const	{ return (_ptr <= rhs.base()); }
		bool					operator>=(const random_access_iterator<const T> &rhs) const	{ return (_ptr >= rhs.base()); }
		bool					operator< (const random_access_iterator<const T> &rhs) const	{ return (_ptr < rhs.base());  }
		bool					operator> (const random_access_iterator<const T> &rhs) const	{ return (_ptr > rhs.base());  }

		/// *  Dereferense ___________________________________________________________________
		reference				operator[](difference_type rhs)			{ return (*(_ptr + rhs)); }
		const_reference			operator[](difference_type rhs) const	{ return (*(_ptr + rhs)); }

		/// *   Random access vvv ____________________________________________________________
		random_access_iterator	operator+ (difference_type rhs) const	{ return (random_access_iterator(_ptr + rhs));	}
		random_access_iterator	operator- (difference_type rhs)			{ return (random_access_iterator(_ptr - rhs));	}

		difference_type			operator- (const iterator &rhs)			{ return (difference_type(_ptr - rhs._ptr));	}
		difference_type			operator- (const iterator &rhs) const	{ return (difference_type(_ptr - rhs._ptr));	}


		random_access_iterator&	operator+=(const difference_type rhs)	{ _ptr += rhs; return ( *this );	}
		random_access_iterator&	operator-=(const difference_type rhs)	{ _ptr -= rhs; return ( *this );	}

		/// *    Pre
		random_access_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		random_access_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		/// *    Post
		random_access_iterator	operator++(int)	{ random_access_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		random_access_iterator	operator--(int) { random_access_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		reference				operator* () const	{ return (*_ptr);	}
		pointer					operator->() const	{ return (_ptr);	}

		pointer					base() const	{ return (_ptr); 	}

	protected:
		pointer _ptr;

	};	/// * random_access_iterator ____________________________________________________

	// ? this will be used when : it = 1 + it;
	template <typename T>
	ft::random_access_iterator<T>
	operator+ (typename ft::random_access_iterator<T>::difference_type lhs,
				typename ft::random_access_iterator<T> &rhs)
	{
		return (ft::random_access_iterator<T>((rhs + lhs)));
	}
	
}

#endif
