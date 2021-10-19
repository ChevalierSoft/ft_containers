#ifndef BIDIRECTIONAL_ITERATOR
# define BIDIRECTIONAL_ITERATOR

#include "iterator.h"
#include "../utils/enable_if.hpp"

namespace ft
{
	/// * bidirectional_iterator ____________________________________________________________
	//  ? http://www.cplusplus.com/reference/iterator/
	template <typename T>
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public:
		/// * Type definition _______________________________________________________________
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
		typedef value_type *								pointer;
		typedef const value_type 							const_pointer;
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
		typedef ft::bidirectional_iterator<T>				iterator;
		typedef ft::bidirectional_iterator<T>				vector_iterator;
		typedef ft::bidirectional_iterator<T>				iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;

		/// * Constructors / Destructor _____________________________________________________
		// ? not using explicit key word to make it easier to create
		bidirectional_iterator() {}
		bidirectional_iterator(pointer x_t) : _ptr(x_t) {}
		bidirectional_iterator(const ft::bidirectional_iterator<T> &rhs) { *this = rhs; }

		// ? allows conversion between iterator of T to const T
		operator bidirectional_iterator<const T>() const { return bidirectional_iterator<const T>(_ptr); }

		~bidirectional_iterator() {}

		/// * Member Operators _______________________________________________________________
		template <typename U>
		bidirectional_iterator&	operator= (const bidirectional_iterator<U> &rhs) { _ptr = rhs.base(); return (*this); }

		/// * Equality Operators _____________________________________________________________
		bool					operator==(const bidirectional_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool					operator!=(const bidirectional_iterator &rhs) const	{ return (_ptr != rhs._ptr); }

		/// *    Pre
		bidirectional_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		bidirectional_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		/// *    Post
		bidirectional_iterator	operator++(int)	{ bidirectional_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		bidirectional_iterator	operator--(int) { bidirectional_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		reference				operator* ()	{ return (*_ptr);	}
		pointer					operator->()	{ return (_ptr);	}

		pointer					base() const	{ return _ptr; 	}

	protected:
		pointer _ptr;

	};	/// * bidirectional_iterator ____________________________________________________

}

#endif
