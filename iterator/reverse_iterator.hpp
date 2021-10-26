#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.h"

namespace ft
{
	/// * reverse_iterator ___________________________________________________________________
	/// ? https://en.cppreference.com/w/cpp/iterator/reverse_iterator
	template <typename Iter>
	class reverse_iterator // _______________________________________________________________
	{
	public:
		/// * Type definition ________________________________________________________________
		
		typedef Iter		iterator_type;
		typedef typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename	ft::iterator_traits<Iter>::reference			reference;
		typedef				ft::reverse_iterator<Iter>						iterator;
		typedef				ft::reverse_iterator<Iter>						vector_iterator;

		/// * Constructors / Destructor _______________________________________________________
		reverse_iterator() {}
		reverse_iterator(typename Iter::value_type * x_t) : _it(x_t) {}
		reverse_iterator(iterator_type rhs) : _it(rhs) {}
		template <class I>
		reverse_iterator (const reverse_iterator<I>& rhs) { *this = rhs; }

		~reverse_iterator() {}

		/// * Member Operators ________________________________________________________________

		template <class I>
		reverse_iterator	&operator= (const reverse_iterator<I> &rhs)		{ _it = rhs.base(); return (*this);	}

		/// * Equality Operators _____________________________________________________________

		bool				operator==(const reverse_iterator &rhs) const	{ return (_it == rhs.base()); }
		bool				operator!=(const reverse_iterator &rhs) const	{ return (_it != rhs.base()); }
		bool				operator<=(const reverse_iterator &rhs) const	{ return (_it >= rhs.base()); }
		bool				operator>=(const reverse_iterator &rhs) const	{ return (_it <= rhs.base()); }
		bool				operator< (const reverse_iterator &rhs) const	{ return (_it > rhs.base());  }
		bool				operator> (const reverse_iterator &rhs) const	{ return (_it < rhs.base());  }

		/// * Dereferense ____________________________________________________________________

		reference			operator[](difference_type rhs)					{ return ( _it[- rhs] ); }
		reference			operator* ()									{ return (*_it); }
		reference			operator->()									{ return &(*_it.operator->()); }
		iterator_type		base() const									{ return (_it); }

		/// *  Random access vvv _____________________________________________________________

		reverse_iterator	operator+ (difference_type rhs)					{ reverse_iterator	rit(_it - rhs); return (rit);	}
		reverse_iterator	operator- (difference_type rhs)					{ reverse_iterator	rit(_it + rhs); return (rit);	}
		// difference_type		operator- (reverse_iterator rhs)				{ difference_type	df(_it - rhs._it); return (df);		}

		reverse_iterator&	operator+=(const difference_type rhs)			{ _it -= rhs; return ( *this );	}
		reverse_iterator&	operator-=(const difference_type rhs)			{ _it += rhs; return ( *this );	}

		/// *   Pre
		reverse_iterator	&operator++()									{ --_it; return (*this);	}
		reverse_iterator	&operator--()									{ ++_it; return (*this);	}
		/// *   Post
		reverse_iterator	operator++(int)									{ reverse_iterator tmp = _it; --_it; return (tmp);	}
		reverse_iterator	operator--(int)									{ reverse_iterator tmp = _it; ++_it; return (tmp);	}

		// operator	reverse_iterator<const Iter> {	return reverse_iterator<const Iter>(_it.base*());	}	// conversion from const iterator to iterator

		/// * Variables ______________________________________________________________________
	protected:
		iterator_type		_it;

	};	/// * reverse_iterator _______________________________________________________________

	// ? if using explicit we need those

	// template <class Iter_L, class Iter_R>
	// 	bool operator!= (const reverse_iterator<Iter_L>& lhs,
	// 					const reverse_iterator<Iter_R>& rhs) { return (lhs.base() != rhs.base()); }

	// template <class Iter_L, class Iter_R>
	// bool operator== (const reverse_iterator<Iter_L>& lhs,
	// 					const reverse_iterator<Iter_R>& rhs) { return (lhs.base() == rhs.base()); }

}

#endif
