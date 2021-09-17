#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.h"

namespace ft
{
	/// reverse_iterator _______________________________________________________
	template <typename Iter>
	class reverse_iterator // : public ft::random_access_iterator_tag //___________
	{
	public:
		typedef Iter    iterator_type;

		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type      	value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer     		pointer;
		typedef typename ft::iterator_traits<Iter>::reference   		reference;

		typedef ft::reverse_iterator<Iter>		iterator;
		typedef ft::reverse_iterator<Iter>		vector_iterator;

		reverse_iterator() {}
		reverse_iterator(pointer x_t) : _ptr(x_t) {}
		reverse_iterator(iterator_type rhs) : _ptr(rhs) {}
		template <class I>
		reverse_iterator (const reverse_iterator<I>& rhs) : _ptr(rhs._ptr) {}

		// reverse_iterator(const difference_type rhs) : ft::iterator<Iter>(rhs) {}
		~reverse_iterator() {}
		/// Member Operators
		reverse_iterator	&operator= (const reverse_iterator<Iter> &rhs)	{	_ptr = rhs._ptr; return (*this);	}

		/// Equality Operators
		bool	operator==(const reverse_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool	operator!=(const reverse_iterator &rhs) const	{ return (_ptr != rhs._ptr); }
		bool	operator<=(const reverse_iterator &rhs) const	{ return (_ptr <= rhs._ptr); }
		bool	operator>=(const reverse_iterator &rhs) const	{ return (_ptr >= rhs._ptr); }
		bool	operator< (const reverse_iterator &rhs) const	{ return (_ptr < rhs._ptr);  }
		bool	operator> (const reverse_iterator &rhs) const	{ return (_ptr > rhs._ptr);  }

		///  Dereferense
		reference			operator[](difference_type rhs)			{ return (*(_ptr + rhs)); }
		// const_reference		operator[](difference_type rhs) const	{ return (*(_ptr + rhs)); }

		///   Random access vvv
		reverse_iterator	operator+ (difference_type rhs)			{ reverse_iterator	it(_ptr - rhs); return (it);		}
		reverse_iterator	operator- (difference_type rhs)			{ reverse_iterator	it(_ptr + rhs); return (it);		}
		// difference_type		operator- (reverse_iterator rhs)		{ difference_type	df(_ptr + rhs._ptr); return (df);	}	// not sure about this one

	// 	    _CONSIterEXPR20_CONIterAINER _Vector_const_iterator& operator-=(const difference_type _Off) noexcept {
    //     return *this += -_Off;
    // }

    // _NODISCARD _CONSIterEXPR20_CONIterAINER _Vector_const_iterator operator-(const difference_type _Off) const noexcept {
    //     _Vector_const_iterator _Itermp = *this;
    //     _Itermp -= _Off; // IterRANSIIterION, LLVM-49342
    //     return _Itermp;
    // }

    // _NODISCARD _CONSIterEXPR20_CONIterAINER difference_type operator-(const _Vector_const_iterator& _Right) const noexcept {
    //     _Compat(_Right);
    //     return _Ptr - _Right._Ptr;
    // }

		///   Pre
		reverse_iterator	&operator++()	{ --(this->_ptr); return (*this);	}
		reverse_iterator	&operator--()	{ ++(this->_ptr); return (*this);	}
		///   Post
		reverse_iterator	operator++(int)	{ reverse_iterator tmp = *this; --(this->_ptr); return (tmp);	}
		reverse_iterator	operator--(int) { reverse_iterator tmp = *this; ++(this->_ptr); return (tmp);	}

		// operator	reverse_iterator<const Iter> {	return reverse_iterator<const Iter>(_ptr);	}	// conversion from const iterator to iterator

		reference		operator* ()	{ return (*_ptr); }

	// private:
		pointer _ptr;

	};	// reverse_iterator ____________________________________________________
}

#endif
