#ifndef BST_BST_BIDIRECTIONAL_ITERATOR
# define BST_BST_BIDIRECTIONAL_ITERATOR

#include "iterator.h"
#include "../utils/enable_if.hpp"

namespace ft
{
	/// * BST_bidirectional_iterator ____________________________________________________________
	//  ? http://www.cplusplus.com/reference/iterator/
	template <typename Tn>
	class BST_bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, Tn>
	{
	public:
		/// * Type definition _______________________________________________________________
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::value_type		value_type;
		typedef value_type *								pointer;
		typedef const value_type 							const_pointer;
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::difference_type       difference_type;
		typedef ft::BST_bidirectional_iterator<Tn>			iterator;
		typedef ft::BST_bidirectional_iterator<Tn>			vector_iterator;
		typedef ft::BST_bidirectional_iterator<Tn>			iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::iterator_category	iterator_category;

		/// * Constructors / Destructor _____________________________________________________
		// ? not using explicit key word to make it easier to create
		BST_bidirectional_iterator () {}
		BST_bidirectional_iterator (pointer node) : _ptr(node) {}
		BST_bidirectional_iterator (const ft::BST_bidirectional_iterator<Tn> &rhs) { *this = rhs; }

		// ? allows conversion between iterator of T to const T
		operator BST_bidirectional_iterator<const Tn>() const { return BST_bidirectional_iterator<const Tn>(_ptr); }

		~BST_bidirectional_iterator () {}

		/// * Member Operators _______________________________________________________________
		template <typename U>
		BST_bidirectional_iterator&	operator= (const BST_bidirectional_iterator<U> &rhs) { _ptr = rhs.base(); return (*this); }

		/// * Equality Operators _____________________________________________________________
		bool						operator==(const BST_bidirectional_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool						operator!=(const BST_bidirectional_iterator &rhs) const	{ return (_ptr != rhs._ptr); }

		/// *    Pre
		BST_bidirectional_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		BST_bidirectional_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		/// *    Post
		BST_bidirectional_iterator	operator++(int)	{ BST_bidirectional_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		BST_bidirectional_iterator	operator--(int) { BST_bidirectional_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		reference					operator* ()	{ return (*_ptr);	}
		pointer						operator->()	{ return (_ptr);	}

		pointer						base() const	{ return (_ptr); 	}

	protected:
		pointer _ptr;

	};	/// * BST_bidirectional_iterator ____________________________________________________

}

#endif
