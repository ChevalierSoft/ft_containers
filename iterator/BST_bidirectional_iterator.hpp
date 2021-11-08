#ifndef BST_BST_BIDIRECTIONAL_ITERATOR
# define BST_BST_BIDIRECTIONAL_ITERATOR

#include "iterator.h"
#include "../utils/enable_if.hpp"

namespace ft
{
	/// * BST_bidirectional_iterator ____________________________________________________________
	//  ? http://www.cplusplus.com/reference/iterator/
	// Tn is a Node
	template <class Tn>
	class BST_bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, Tn>
	{
		/// * Type definition _______________________________________________________________

	public:
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::value_type						value_type;
		// typedef	Tn											value_type;

		// typedef value_type *																				pointer;
		// typedef Tn*	pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::pointer							pointer;
		typedef const pointer 																				const_pointer;
		typedef value_type &																				reference;
		typedef const value_type &																			const_reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::difference_type					difference_type;
		typedef ft::BST_bidirectional_iterator<Tn>															iterator;
		typedef const ft::BST_bidirectional_iterator<Tn>													const_iterator;
		typedef ft::BST_bidirectional_iterator<Tn>															iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::iterator_category				iterator_category;

		/// * Constructors / Destructor _____________________________________________________

		BST_bidirectional_iterator () {}
		BST_bidirectional_iterator (pointer node_ptr) : _ptr(node_ptr) {}
		BST_bidirectional_iterator (const_iterator &rhs) { *this = rhs; }

		// ? allows conversion between iterator of T to const T
		operator BST_bidirectional_iterator<Tn>() const { return BST_bidirectional_iterator<Tn>(_ptr); }

		~BST_bidirectional_iterator () {}

		/// * Member Operators _______________________________________________________________
		template <typename M>
		BST_bidirectional_iterator&	operator= (const BST_bidirectional_iterator<M> &rhs) { _ptr = rhs.base(); return (*this); }

		/// * Equality Operators _____________________________________________________________
		bool						operator==(const BST_bidirectional_iterator &rhs) const	{ return (_ptr->content == rhs._ptr->content); }
		bool						operator!=(const BST_bidirectional_iterator &rhs) const	{ return (_ptr->content != rhs._ptr->content); }

		// ? vvv needs to be redone vvv
		// /// *    Pre
		// BST_bidirectional_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		// BST_bidirectional_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		// /// *    Post
		// BST_bidirectional_iterator	operator++(int)	{ BST_bidirectional_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		// BST_bidirectional_iterator	operator--(int) { BST_bidirectional_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		reference					operator* ()	{ return (_ptr->content);	}
		pointer						operator->()	{ return (&_ptr->content);	}

		pointer						base() const	{ return (_ptr); 	}

	protected:
		pointer _ptr;

	};	/// * BST_bidirectional_iterator ____________________________________________________

}

#endif
