#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.h"

namespace ft
{
	/// * reverse_iterator _____________________________________________________
	/// ? https://en.cppreference.com/w/cpp/iterator/reverse_iterator
	template <typename Iter>
	class reverse_iterator // __________________________________________________
	{
	public:
		/// * Type definition __________________________________________________
		
		typedef				Iter											iterator_type;
		typedef typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iter>::pointer				pointer;
		typedef 	const pointer									const_pointer;
		typedef typename	ft::iterator_traits<Iter>::reference			reference;
		typedef 	const reference									const_reference;
		typedef				ft::reverse_iterator<Iter>						iterator;
		typedef				ft::reverse_iterator<Iter>						vector_iterator;

		/// * Constructors / Destructor ________________________________________

		reverse_iterator () : _it(){}

		// reverse_iterator (typename Iter::value_type * x_t) : _it(x_t) {}

		reverse_iterator (iterator_type rhs) : _it(rhs) {}

		template <class I>
		reverse_iterator (const reverse_iterator<I>& rhs) : _it(rhs.base()) {}
		// reverse_iterator (const reverse_iterator<I>& rhs) { *this = rhs; }

		~reverse_iterator () {}

		/// * Member Operators _________________________________________________

		// template <class I>
		// reverse_iterator	&operator= (const reverse_iterator<I> &rhs)		{ _it = rhs.base(); return (*this);	}

		/// * Equality Operators _______________________________________________

		// bool				operator==(const reverse_iterator &rhs) const	{ return (_it == rhs.base()); }
		// bool				operator!=(const reverse_iterator &rhs) const	{ return (_it != rhs.base()); }
		// bool				operator<=(const reverse_iterator &rhs) const	{ return (_it >= rhs.base()); }
		// bool				operator>=(const reverse_iterator &rhs) const	{ return (_it <= rhs.base()); }
		// bool				operator< (const reverse_iterator &rhs) const	{ return (_it > rhs.base());  }
		// bool				operator> (const reverse_iterator &rhs) const	{ return (_it < rhs.base());  }

		/// * Dereferense ______________________________________________________

		reference			operator[](difference_type rhs)					{ return ( _it[- rhs - 1] );					}
		const_reference		operator[](difference_type rhs)	const			{ return ( _it[- rhs - 1] );					}
		reference			operator*() const								{ iterator_type tmp(_it); return (*(--tmp));	}
		pointer				operator->() const								{ return &(operator*());						}
		iterator_type		base() const									{ return (_it);									}

		/// *  Random access vvv _____________________________________________________________

		reverse_iterator	operator+ (difference_type rhs)					{ reverse_iterator	rit(_it - rhs); return (rit);	}
		reverse_iterator	operator- (difference_type rhs)					{ reverse_iterator	rit(_it + rhs); return (rit);	}

		reverse_iterator&	operator+=(const difference_type rhs)			{ _it -= rhs; return ( *this );	}
		reverse_iterator&	operator-=(const difference_type rhs)			{ _it += rhs; return ( *this );	}

		/// *   Pre
		reverse_iterator	&operator++()									{ --_it; return (*this);	}
		reverse_iterator	&operator--()									{ ++_it; return (*this);	}
		/// *   Post
		reverse_iterator	operator++(int)									{ reverse_iterator tmp = _it; --_it; return (tmp);	}
		reverse_iterator	operator--(int)									{ reverse_iterator tmp = _it; ++_it; return (tmp);	}

		// operator	reverse_iterator<const Iter> {	return reverse_iterator<const Iter>(_it.base*());	}	// conversion from const iterator to iterator

		/// * Variables ________________________________________________________

	protected:
		iterator_type		_it;

	};	/// * reverse_iterator _________________________________________________

	template <typename Iter>
	ft::reverse_iterator<Iter>
	operator+ (typename ft::reverse_iterator<Iter>::difference_type lhs,
				typename ft::reverse_iterator<Iter> &rhs)
	{
		return (ft::reverse_iterator<Iter>(rhs + lhs));
	}

	template <typename Iter>
	ft::reverse_iterator<Iter>
	operator- (typename ft::reverse_iterator<Iter>::difference_type lhs,
				typename ft::reverse_iterator<Iter> &rhs)
	{
		return (ft::reverse_iterator<Iter>(rhs - lhs));
	}

	template <typename Iter_L, typename Iter_R>
	typename ft::reverse_iterator<Iter_L>::difference_type
	operator- (const ft::reverse_iterator<Iter_L> &lhs,
				const ft::reverse_iterator<Iter_R> &rhs)
	{
		// ! need to double check
		return (-(lhs.base().base() - rhs.base().base()));
	}

	/// * Equality Operators ___________________________________________________
	// ? two iterator in template are used when comparing const and non const

	template <class Iter_L, class Iter_R>
	bool operator==(const reverse_iterator<Iter_L>& lhs,
						const reverse_iterator<Iter_R>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iter>
	bool operator==(const reverse_iterator<Iter>& lhs,
						const reverse_iterator<Iter>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename Iter>
	bool	operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename Iter_L, typename Iter_R>
	bool	operator!=(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename Iter>
	bool	operator< (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Iter_L, typename Iter_R>
	bool	operator< (const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Iter>
	bool	operator> (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename Iter_L, typename Iter_R>
	bool	operator>(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename Iter>
	bool	operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Iter_L, typename Iter_R>
	bool	operator<=(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Iter>
	bool	operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename Iter_L, typename Iter_R>
	bool	operator>=(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

}

#endif
