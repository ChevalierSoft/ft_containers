#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.h"

namespace ft
{
	/// * random_access_iterator ____________________________________________________________
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
		random_access_iterator() {}
		random_access_iterator(pointer x_t) : _ptr(x_t) {}
		random_access_iterator(const iterator_type &rhs) { *this = rhs; }
		// template <class I>
		// random_access_iterator(const I &rhs, typename std::enable_if<!std::is_integral<random_access_iterator>::value, random_access_iterator>::type* = 0) { _ptr = rhs; }
		// random_access_iterator(const difference_type rhs) : ft::iterator<T>(rhs) {}

		~random_access_iterator() {}

		/// * Member Operators _______________________________________________________________
		template <typename Iter>
		random_access_iterator	&operator= (const random_access_iterator<Iter> &rhs)	{	_ptr = rhs.base(); return (*this);	}
		// random_access_iterator	&operator= (const random_access_iterator &rhs)	{	_ptr = rhs._ptr; return (*this);	}


		/// * Equality Operators _____________________________________________________________
		bool					operator==(const random_access_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool					operator!=(const random_access_iterator &rhs) const	{ return (_ptr != rhs._ptr); }
		bool					operator<=(const random_access_iterator &rhs) const	{ return (_ptr <= rhs._ptr); }
		bool					operator>=(const random_access_iterator &rhs) const	{ return (_ptr >= rhs._ptr); }
		bool					operator< (const random_access_iterator &rhs) const	{ return (_ptr < rhs._ptr);  }
		bool					operator> (const random_access_iterator &rhs) const	{ return (_ptr > rhs._ptr);  }

		/// *  Dereferense ___________________________________________________________________
		reference				operator[](difference_type rhs)			{ return (*(_ptr + rhs)); }
		const_reference			operator[](difference_type rhs) const	{ return (*(_ptr + rhs)); }

		/// *   Random access vvv ____________________________________________________________
		random_access_iterator	operator+ (difference_type rhs)			{ random_access_iterator	it(_ptr + rhs); return (it);		}
		random_access_iterator	operator- (difference_type rhs)			{ random_access_iterator	it(_ptr - rhs); return (it);		}
		difference_type			operator- (random_access_iterator rhs)	{ difference_type			df(_ptr - rhs._ptr); return (df);	}

		random_access_iterator&	operator+=(const difference_type rhs)	{ _ptr += rhs; return ( *this );	}
		random_access_iterator&	operator-=(const difference_type rhs)	{ _ptr -= rhs; return ( *this );	}

		/// *    Pre
		random_access_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		random_access_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		/// *    Post
		random_access_iterator	operator++(int)	{ random_access_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		random_access_iterator	operator--(int) { random_access_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		// operator	random_access_iterator<const T> {	return random_access_iterator<const T>(_ptr);	}	// conversion from const iterator to iterator

		reference				operator* ()	{ return (*_ptr);	}
		pointer					operator->()	{ return (_ptr);	}

		pointer					base() const	{ return _ptr; 	}

	// private:
	protected:
		pointer _ptr;

	};	/// * random_access_iterator ____________________________________________________
}

#endif
