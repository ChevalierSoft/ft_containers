/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:44:33 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/21 00:19:44 by dait-atm         ###   ########.fr       */
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
		typedef ft::bidirectional_iterator<Node>		iterator;
		typedef ft::bidirectional_iterator<const Node>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


		// * Constructors & Destructors _______________________________________
	public:
		BinarySearchTree() : _root() {}

		BinarySearchTree(const_reference val) : _root(val) {}
		
		~BinarySearchTree() {}

		// * Modifiers ________________________________________________________

		Node_pointer*	get_closest_preorder(Node_pointer r)
		{
			if (r == NULL)
				return (r);
			
			while (1)
			{

			}
		}

		void			insert(const_reference val)
		{
			// BST_Node	n(val);
			// BST_Node*	pos = get_closest_preorder();

			// if (pos->parent->right == pos)
			// 	pos->parent->right = &n

			// if ()

		}


		// * Variables ________________________________________________________
	protected:
		Node_pointer*	_root;		// node data
		Type_Allocator	_type_allocator;
		Node_Allocator	_node_allocator;
		
	}; // * BinarySearchTree __________________________________________________
}

#endif
