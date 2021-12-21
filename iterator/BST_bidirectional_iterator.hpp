/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_bidirectional_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:09:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/21 17:14:35 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_BST_BIDIRECTIONAL_ITERATOR
# define BST_BST_BIDIRECTIONAL_ITERATOR

#include "iterator.h"
#include "../utils/enable_if.hpp"

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
		typedef ft::BST_bidirectional_iterator<Tn>												iterator;

		typedef iterator																		iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::iterator_category	iterator_category;

		/// * Constructors / Destructor _______________________________________

		BST_bidirectional_iterator ()
		: _ptr(NULL), _cardinal(NULL)
		{}

		BST_bidirectional_iterator (const Node_pointer node_ptr, const Node_pointer card_ptr)
		: _ptr(node_ptr), _cardinal(card_ptr)
		{}

		BST_bidirectional_iterator (const iterator &rhs)
		: _ptr(rhs._ptr), _cardinal(rhs._cardinal)
		{}

		~BST_bidirectional_iterator () {}

		/// * Member Operators _________________________________________________

		BST_bidirectional_iterator&	operator= (const_reference &rhs)
		{
			if (this != &rhs)
			{
				_ptr = rhs._ptr;
				_cardinal = rhs._cardinal;
			}
			return (*this);
		}

		/// * Equality Operators _______________________________________________

		bool						operator==(const BST_bidirectional_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool						operator!=(const BST_bidirectional_iterator &rhs) const	{ return (_ptr != rhs._ptr); }

		/// *    Pre

		iterator					&operator++()
		{
			if (!_ptr)
				;
			else if (_ptr == _cardinal)
				_ptr = _cardinal->left;
			else if (_ptr->right && _ptr->right != _cardinal)
			{
				_ptr = _ptr->right;
				while (_ptr->left && _ptr->left != _cardinal)
					_ptr = _ptr->left;
			}
			else if (_ptr->right && _ptr->right == _cardinal)
			{
				_ptr = _cardinal;
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
				_ptr = _cardinal->right;
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

		reference					operator* () const		{ return (_ptr->content);	}
		pointer						operator->() const		{ return (&_ptr->content);	}

		// ! DEBUG ?
		Node_pointer				base() const			{ return (_ptr); 			}
		Node_pointer				get_base() const		{ return (base()); 			}
		Node_pointer				get_cardinal() const	{ return (_cardinal); 		}

	protected:
		Node_pointer 				_ptr;		// actual node
		Node_pointer				_cardinal;	// cardinal of the BST checking the boundaries
	};
	


	/// * BST_const_bidirectional_iterator _____________________________________
	template <class Tn>
	class BST_const_bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, Tn>
	{
		/// * Type definition __________________________________________________

	protected:
		typedef	Tn						Node;
		typedef	Node*					Node_pointer;

	public:
		typedef const typename Tn::value_type													value_type;
		typedef value_type*																		pointer;
		typedef const pointer 																	const_pointer;
		typedef value_type &																	reference;
		typedef const value_type &																const_reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::difference_type		difference_type;

		typedef ft::BST_bidirectional_iterator<Tn>												iterator;
		typedef ft::BST_const_bidirectional_iterator<Tn>				const_iterator;
		typedef const_iterator																	iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tn>::iterator_category	iterator_category;

		/// * Constructors / Destructor _______________________________________

		BST_const_bidirectional_iterator ()
		: _ptr(NULL), _cardinal(NULL)
		{}

		BST_const_bidirectional_iterator (const Node_pointer node_ptr, const Node_pointer card_ptr)
		: _ptr(node_ptr), _cardinal(card_ptr)
		{}

		BST_const_bidirectional_iterator (const const_iterator &rhs) { *this = rhs; }

		BST_const_bidirectional_iterator (const iterator &it)
		: _ptr(it.get_base()), _cardinal(it.get_cardinal())
		{}

		BST_const_bidirectional_iterator (const_iterator &rhs)
		: _ptr(rhs._ptr), _cardinal(rhs._cardinal)
		{}

		~BST_const_bidirectional_iterator () {}

		/// * Member Operators _________________________________________________

		BST_const_bidirectional_iterator&	operator= (const_reference &rhs)
		{
			if (this != &rhs)
			{
				_ptr = rhs._ptr;
				_cardinal = rhs._cardinal;
			}
			return (*this);
		}

		/// * Equality Operators _______________________________________________

		bool						operator==(const BST_const_bidirectional_iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool						operator!=(const BST_const_bidirectional_iterator &rhs) const	{ return (_ptr != rhs._ptr); }

		/// *    Pre

		const_iterator				&operator++()
		{
			if (!_ptr)
				;
			else if (_ptr == _cardinal)
			{
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
			}
			else if (!_ptr->right)
			{
				while (_ptr->parent && _ptr->parent->right == _ptr)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
			return (*this);
		}

		const_iterator				&operator--()
		{
			if (!_ptr)
				;
			else if (_ptr == _cardinal)
			{
				_ptr = _cardinal->right;
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

		const_iterator				operator++(int)
		{
			const_iterator	tmp(*this);
			this->operator++();
			return (tmp);
		}

		const_iterator				operator--(int)
		{
			const_iterator tmp(*this);
			this->operator--();
			return (tmp);
		}

		const_reference				operator* () const	{ return (_ptr->content);	}
		pointer						operator->() const	{ return (const_pointer(&_ptr->content));	}

		// ! DEBUG
		Node_pointer				base() const			{ return (_ptr); 			}
		Node_pointer				get_base() const		{ return (base()); 			}
		Node_pointer				get_cardinal() const	{ return (_cardinal); 		}

	protected:
		Node_pointer 				_ptr;		// actual node
		Node_pointer				_cardinal;	// cardinal of the BST checking the boundaries

	};	/// * BST_const_bidirectional_iterator _________________________________

}

#endif
