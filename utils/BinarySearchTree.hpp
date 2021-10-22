/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:44:33 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/22 08:11:05 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

#include <functional>	// std::less
#include <memory>		// std::allocator
#include "BST_Node.hpp"
#include "../iterator/iterator.h"
#include "../iterator/BST_bidirectional_iterator.hpp"
#include "BST_Node.hpp"

#define __DEB(s) std::cerr<<s<<std::endl;

namespace ft
{
	template< class T, class Compare = std::less<T>, class N = ft::BST_Node<T>, 
				class Type_Allocator = std::allocator< T >, class Node_Allocator = std::allocator< ft::BST_Node<T> > >
	class BinarySearchTree // * _______________________________________________  BinarySearchTree
	{
	public:
		typedef T										value_type;
		typedef N										Node;
		typedef Compare									type_compare;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef typename Node_Allocator::pointer		Node_pointer;
		typedef typename Node_Allocator::const_pointer	Node_const_pointer;
		typedef ft::BST_bidirectional_iterator<Node>	iterator;
		typedef ft::BST_bidirectional_iterator<const Node>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// * Constructors & Destructors _______________________________________
	public:
		BinarySearchTree (void) : _root(NULL) {}

		BinarySearchTree (const_reference val)
		{
			_root = _node_allocator.allocate(1);
			_node_allocator.construct(_root, val);
		}
		
		~BinarySearchTree (void) {	erase(_root);	}

	// protected:
		size_type		get_last_floor (Node_pointer node)
		{
			int l = -1;
			int r = -1;

			if (!node)
				return (0);

			// if (node->left)
				l = get_last_floor(node->left);
			// if (node->right)
				r = get_last_floor(node->right);

			return (l > r) ? l + 1 : r + 1;
		}

		long			get_balance (Node_pointer node)
		{
			if (node)
				return(get_last_floor(node->right) - get_last_floor(node->left));
			return (0);
		}

		// * Rotations

		Node_pointer	right_rotation(Node_pointer node)
		{
			Node_pointer	tmp;

			tmp = node->left;
			node->left = tmp->right;
			tmp->right = node;
			return (tmp);
		}

		Node_pointer	left_rotation(Node_pointer node)
		{
			Node_pointer	tmp;

			// __DEB("left_rotation")
			tmp = node->right;
			node->right = tmp->left;
			tmp->left = node;
			return (tmp);
		}

		//	    ,o.
		//    ,o.
		//  ,o.
		Node_pointer	left_left_rotation(Node_pointer node)
		{
			return (right_rotation(node));
		}

		//	    ,o.
		//    ,o.
		//      ,o.
		Node_pointer	left_right_rotation(Node_pointer node)
		{
			node->left = left_rotation(node->left);
			return (right_rotation(node));
		}

		//	    ,o.
		//        ,o.
		//          ,o.
		Node_pointer	right_right_rotation(Node_pointer node)
		{
			// __DEB("right_right_rotation")
			return (left_rotation(node));
		}

		//	    ,o.
		//        ,o.
		//      ,o.
		Node_pointer	right_left_rotation(Node_pointer node)
		{
			node->right = right_rotation(node->right);
			return (left_rotation(node));
		}

		Node_pointer	balance (Node_pointer node)
		{
			long	b;

			if (!node)
				return (NULL);

			b = get_balance(node);

			// too much nodes left
			if (b == -2)
			{
				if (get_balance(node->left) <= 0)
					return (left_left_rotation(node));
				else
					return (left_right_rotation(node));
			}
			// too much nodes right
			else if (b == 2)
			{
				if (get_balance(node->right) <= 0)
					return (right_left_rotation(node));
				else
					return (right_right_rotation(node));
			}
			// node is already balanced
			return (node);
		}

	// public:
		// * Modifiers ________________________________________________________

		void			erase (Node_pointer node)
		{
			if(node != NULL)
			{
				if (node->left)
					erase(node->left);
				if (node->right)
					erase(node->right);
				_node_allocator.destroy(node);
				_node_allocator.deallocate(node, 1);
			}
		}

		// ? (1) default inserting from _root
		Node_pointer	insert (const_reference val)
		{
			_root = insert(_root, val);
			return (_root);
		}

		// ? (2) using a specific node (this might be private)
		Node_pointer	insert (Node_pointer node, const_reference val)
		{
			// __DEB("insert");
			if(node == NULL)
			{
				// __DEB("position found")
				node = _node_allocator.allocate(1);
				_node_allocator.construct(node, Node(val));
			}
			else if (val.first == node->content.first)
				node->content.second = val.second;
			else if(val.first < node->content.first)
			{
				// __DEB("going left")
				node->left = insert(node->left, val);
				node->left->parent = node;
			}
			else
			{
				// __DEB("going right")
				node->right = insert(node->right, val);
				node->right->parent = node;
			}
			
			// __DEB("balance")
			return (balance(node));
		}

		Node_pointer	search (typename T::first_type key)
		{
			return (search(_root, key));
		}

		Node_pointer	search (Node_pointer node, typename T::first_type key)
		{
			Node_pointer	res = NULL;

			if (node == NULL)
				return (NULL);
			else if (node->content.first == key)
				return (node);

			if (key < node->content.first)
				res = search(node->left, key);
			else if (key > node->content.first)
				res = search(node->right, key);
			return (res);
		}

		void			display (Node_pointer node)
		{
			size_type	len = get_last_floor(node);

			if (node)
			{
				if (node->left)
					display(node->left);
				std::cout << std::string( ((len * 6) / 2), ' ' );
				std::cout << node->content;
				std::cout << std::string( ((len * 6) / 2), ' ' );
				if (node->right)
					display(node->right);
			}
			else
				std::cout << std::string( len * 6 + 6, ' ' );
		}

		// * Variables ________________________________________________________
	// protected:
		Node_pointer	_root;				// node data
		Type_Allocator	_type_allocator;
		Node_Allocator	_node_allocator;
		
	}; // * BinarySearchTree __________________________________________________

	// ? DEBUG

	std::ostream&	operator<<(std::ostream & o, ft::pair<int, std::string> & pr)
	{
		o << pr.first << pr.second ;
		return (o);
	}

	template< class T, class Type_Allocator = std::allocator< T > >
	std::ostream&	operator<<(std::ostream & o, ft::BST_Node<T, Type_Allocator> & bn)
	{
		o << ", " << bn.content << " .";
		return (o);
	}

	template< class T, class Type_Allocator = std::allocator< T > >
	std::ostream&	operator<<(std::ostream & o, ft::BST_Node<T, Type_Allocator> * bn)
	{
		o << ", " << bn->content << " .";
		return (o);
	}

}

#endif
