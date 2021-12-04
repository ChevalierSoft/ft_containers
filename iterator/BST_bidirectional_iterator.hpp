#ifndef BST_BST_BIDIRECTIONAL_ITERATOR
# define BST_BST_BIDIRECTIONAL_ITERATOR

#include "iterator.h"
#include "../utils/enable_if.hpp"

#define END_POSITION 1
#define	OTHER_POSITION 0

namespace ft
{
	/// * BST_bidirectional_iterator ___________________________________________ ft::BST_bidirectional_iterator
	//  ? http://www.cplusplus.com/reference/iterator/
	// Tn is a Node
	template <class Tn>
	class BST_bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, Tn>
	{
		/// * Type definition __________________________________________________

	protected:
		typedef	Tn						Node;
		typedef	Node*					Node_pointer;

	public:
		typedef typename Tn::value_type															value_type;
		typedef value_type*																		pointer;
		typedef const pointer 																	const_pointer;
		typedef value_type &																	reference;
		typedef const value_type &																const_reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::difference_type		difference_type;
		typedef ft::BST_bidirectional_iterator<Tn>										iterator;
		typedef const iterator																	const_iterator;
		typedef iterator																		iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::iterator_category	iterator_category;

		/// * Constructors / Destructor _______________________________________

		BST_bidirectional_iterator ()
		: _ptr(NULL), _cardinal(NULL), _side(OTHER_POSITION)
		{}

		BST_bidirectional_iterator (Node_pointer node_ptr, Node_pointer card_ptr, bool side = OTHER_POSITION)
		: _ptr(node_ptr), _cardinal(card_ptr), _side(side)
		{}

		BST_bidirectional_iterator (const_iterator &rhs) { *this = rhs; }

		~BST_bidirectional_iterator () {}

		/// * Member Operators _________________________________________________

		BST_bidirectional_iterator&	operator= (const_reference &rhs)
		{
			if (this != &rhs)
			{
				_ptr = rhs._ptr;
				_cardinal = rhs._cardinal;
				_side = rhs._side;
			}
			return (*this);
		}

		/// * Equality Operators _______________________________________________

		// ? allows conversion between iterator of T to const T
		operator BST_bidirectional_iterator<Tn>() const	{ return BST_bidirectional_iterator<const Tn>(_ptr); }

		bool						operator==(const BST_bidirectional_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool						operator!=(const BST_bidirectional_iterator &rhs) const	{ return (_ptr != rhs._ptr); }

		/// *    Pre

		iterator					&operator++()
		{
			if (!_ptr)
				;
			else if (_ptr == _cardinal)
			{
				if (_side != END_POSITION)
					_ptr = _cardinal->left;
			}
			else if (_ptr->right && _ptr->right != _cardinal)
			{
				_ptr = _ptr->right;
				while (_ptr->left)
					_ptr = _ptr->left;
			}
			else if (_ptr->right && _ptr->right == _cardinal)
			{
				_ptr = _cardinal;
				_side = OTHER_POSITION;
			}
			else if (!_ptr->right)
			{
				while (_ptr->parent && _ptr->parent->right == _ptr)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
			return (*this);
		}

		iterator					&operator--()
		{
			if (!_ptr)
				;
			else if (_ptr == _cardinal)
			{
				if (_side == END_POSITION)
				{
					_ptr = _cardinal->right;
					_side = OTHER_POSITION;
				}
			}
			else if (_ptr->left && _ptr->left != _cardinal)
			{
				_ptr = _ptr->left;
				while (_ptr->right)
					_ptr = _ptr->right;
			}
			else if (_ptr->left && _ptr->left == _cardinal)
			{
				_ptr = _cardinal;
			}
			else if (!_ptr->left)
			{
				while (_ptr->parent && _ptr->parent->left == _ptr)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
			return (*this);

		}

		/// *    Post

		iterator					operator++(int)
		{
			iterator	tmp(*this);
			this->operator++();
			return (tmp);
		}

		iterator					operator--(int)
		{
			iterator tmp(*this);
			this->operator--();
			return (tmp);
		}

		reference					operator* () const	{ return (_ptr->content);	}
		pointer						operator->() const	{ return (&_ptr->content);	}

		// ! DEBUG
		Node_pointer				base() const		{ return (_ptr); 				}

	protected:
		Node_pointer 				_ptr;		// actual node
		Node_pointer				_cardinal;	// cardinal of the BST checking the boundaries
		bool						_side;		// will give from which side _ptr went to _cardinal. (1 = at end(), 0 the rest)

	};	/// * BST_bidirectional_iterator _______________________________________

}

#endif
