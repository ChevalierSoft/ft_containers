#ifndef BST_BST_BIDIRECTIONAL_ITERATOR
# define BST_BST_BIDIRECTIONAL_ITERATOR

#include "iterator.h"
#include "../utils/enable_if.hpp"

namespace ft
{
	/// * BST_bidirectional_iterator ____________________________________________________________
	//  ? http://www.cplusplus.com/reference/iterator/
	// Tn is a Node
	template <class Tn, class Compare>
	class BST_bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, Tn>
	{
		/// * Type definition _______________________________________________________________

	protected:
		typedef	Tn						Node;
		typedef	Node*					Node_pointer;

	public:
		// typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::value_type			value_type;
		// typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::pointer				pointer;
		typedef typename Tn::value_type															value_type;
		typedef value_type*																		pointer;
		typedef const pointer 																	const_pointer;
		typedef value_type &																	reference;
		typedef const value_type &																const_reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::difference_type		difference_type;
		typedef ft::BST_bidirectional_iterator<Tn, Compare>										iterator;
		typedef const iterator																	const_iterator;
		typedef iterator																		iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::iterator_category	iterator_category;

		/// * Constructors / Destructor _____________________________________________________

		BST_bidirectional_iterator (const Compare & comp = Compare()) : _ptr(NULL), _cardinal(NULL), _comp(comp) {}

		BST_bidirectional_iterator (Node_pointer node_ptr, Node_pointer card_ptr, const Compare & comp = Compare()) : _ptr(node_ptr), _cardinal(card_ptr), _comp(comp) {}

		BST_bidirectional_iterator (const_iterator &rhs) { *this = rhs; }

		~BST_bidirectional_iterator () {}

		/// * Member Operators _______________________________________________________________

		// template <typename M>
		BST_bidirectional_iterator&	operator= (const_reference &rhs)
		{
			if (this != &rhs)
			{
				_ptr = rhs._ptr;
				_cardinal = rhs._cardinal;
				_comp = rhs._comp;
			}
			return (*this);
		}

		/// * Equality Operators _____________________________________________________________

		// ? allows conversion between iterator of T to const T
		operator BST_bidirectional_iterator<Tn, Compare>() const	{ return BST_bidirectional_iterator<Tn, Compare>(_ptr); }

		bool						operator==(const BST_bidirectional_iterator &rhs) const	{ return (_ptr->content == rhs._ptr->content); }
		bool						operator!=(const BST_bidirectional_iterator &rhs) const	{ return (_ptr->content != rhs._ptr->content); }

		// ? vvv needs to be redone vvv
		// /// *    Pre
		// BST_bidirectional_iterator	&operator++()	{ ++(this->_ptr); return (*this);	}
		// BST_bidirectional_iterator	&operator--()	{ --(this->_ptr); return (*this);	}
		// /// *    Post
		// BST_bidirectional_iterator	operator++(int)	{ BST_bidirectional_iterator tmp = *this; ++(this->_ptr); return (tmp);	}
		// BST_bidirectional_iterator	operator--(int) { BST_bidirectional_iterator tmp = *this; --(this->_ptr); return (tmp);	}

		// typename Tn::reference		operator* () const	{ return (_ptr->content);	}
		reference					operator* () const
		{
			const_pointer oui = _ptr->content;
			return (oui);
		}
		pointer						operator->() const	{ return (_ptr->content);		}

		Node_pointer				base() const		{ return (_ptr); 	}

	// protected:
		Node_pointer 				_ptr;		// actual node
		Node_pointer				_cardinal;	// cardinal of the BST checking the boundaries
		Compare						_comp;		// will be faster than using the one of the nodes

	};	/// * BST_bidirectional_iterator ____________________________________________________

}

#endif



// 'ft::BST_Node<int, std::__cxx11::basic_string<char>, std::less<int>, std::allocator<ft::pair<int, std::__cxx11::basic_string<char> > > >'
// 'ft::pair<int, std::__cxx11::basic_string<char> > *'
