#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.h"

namespace ft
{
	/// reverse_iterator _______________________________________________________
	/// https://en.cppreference.com/w/cpp/iterator/reverse_iterator
	template <typename Iter>
	class reverse_iterator // : public ft::random_access_iterator_tag //___________
	{
	public:
		typedef Iter	iterator_type;

		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type	  	value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type	 difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer	 		pointer;
		typedef typename ft::iterator_traits<Iter>::reference   		reference;

		typedef ft::reverse_iterator<Iter>		iterator;
		typedef ft::reverse_iterator<Iter>		vector_iterator;

		reverse_iterator() {}
		reverse_iterator(typename Iter::value_type * x_t) : _it(x_t) {}
		reverse_iterator(iterator_type rhs) : _it(rhs) {}
		template <class I>
		// reverse_iterator (const reverse_iterator<I>& rhs) : _it(rhs._it) {}	// old
		reverse_iterator (const reverse_iterator<I>& rhs) { *this = rhs; }		// new

		// reverse_iterator (const reverse_iterator<Iter>& rhs) : _ptr(rhs._ptr) {}

		// reverse_iterator(const difference_type rhs) : ft::iterator<Iter>(rhs) {}
		~reverse_iterator() {}
		/// Member Operators
		// reverse_iterator	&operator= (const reverse_iterator<Iter> &rhs)	{	_ptr = rhs._ptr; return (*this);	}
		template <class I>
		reverse_iterator	&operator= (const reverse_iterator<I> &rhs)	{	_it = rhs.get_it(); return (*this);	}


		Iter get_it() const {return _it;}


		// /// Equality Operators
		bool	operator==(const reverse_iterator &rhs) const	{ return (_it == rhs.get_it()); }
		bool	operator!=(const reverse_iterator &rhs) const	{ return (_it != rhs.get_it()); }
		bool	operator<=(const reverse_iterator &rhs) const	{ return (_it <= rhs.get_it()); }
		bool	operator>=(const reverse_iterator &rhs) const	{ return (_it >= rhs.get_it()); }
		bool	operator< (const reverse_iterator &rhs) const	{ return (_it < rhs.get_it());  }
		bool	operator> (const reverse_iterator &rhs) const	{ return (_it > rhs.get_it());  }

		// ///  Dereferense
		// reference			operator[](difference_type rhs)			{ return (*(_ptr + rhs)); }
		// // const_reference		operator[](difference_type rhs) const	{ return (*(_ptr + rhs)); }

		// ///   Random access vvv
		// reverse_iterator	operator+ (difference_type rhs)			{ reverse_iterator	it(_ptr - rhs); return (it);		}
		// reverse_iterator	operator- (difference_type rhs)			{ reverse_iterator	it(_ptr + rhs); return (it);		}
		// difference_type		operator- (reverse_iterator rhs)		{ difference_type	df(_ptr + rhs._ptr); return (df);	}	// not sure about this one

		reverse_iterator&	operator+=(const difference_type rhs)	{ _it -= rhs; return ( *this );	}
		reverse_iterator&	operator-=(const difference_type rhs)	{ _it += rhs; return ( *this );	}

		// ///   Pre
		// reverse_iterator	&operator++()	{ --(this->_ptr); return (*this);	}
		reverse_iterator	&operator++()	{ --_it; return (*this);	}
		// reverse_iterator	&operator--()	{ ++(this->_ptr); return (*this);	}
		// ///   Post
		// reverse_iterator	operator++(int)	{ reverse_iterator tmp = *this; --(this->_ptr); return (tmp);	}
		// reverse_iterator	operator--(int) { reverse_iterator tmp = *this; ++(this->_ptr); return (tmp);	}

		// // operator	reverse_iterator<const Iter> {	return reverse_iterator<const Iter>(_ptr);	}	// conversion from const iterator to iterator

		// reference			operator* ()	{ return (*_ptr); }
		reference			operator* ()	{ return (*_it); }

		// iterator_type		base() const	{ return (*this); }
		iterator_type		base() const	{ return (_it); }

	// protected:
		iterator_type	_it;

	};	// reverse_iterator ____________________________________________________

	/* For reverser_iterator != const_reverse_iterator */
	// template <class Iter_L, class Iter_R>
	// 	bool operator!= (const reverse_iterator<Iter_L>& lhs,
	// 					const reverse_iterator<Iter_R>& rhs) { return (lhs.base() != rhs.base()); }

	// /* For reverser_iterator == const_reverse_iterator */
	// template <class Iter_L, class Iter_R>
	// bool operator== (const reverse_iterator<Iter_L>& lhs,
	// 					const reverse_iterator<Iter_R>& rhs) { return (lhs.base() == rhs.base()); }


}

#endif
