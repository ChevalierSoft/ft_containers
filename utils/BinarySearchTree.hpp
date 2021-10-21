/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:44:33 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/21 02:29:31 by dait-atm         ###   ########.fr       */
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
		BinarySearchTree() : _root(NULL) {}

		BinarySearchTree(const_reference val)
		{
			_root = _node_allocator.allocate(1);
			_node_allocator.construct(_root, val);
		}
		
		~BinarySearchTree() {	_node_allocator.deallocate(_root, 1);	}

		// * Modifiers ________________________________________________________

		Node_pointer			insert(Node_pointer node, const_reference val)
		{
			// _recursive_insert(node, val);
			__DEB("_recursive_insert");
			if(node == NULL)
			{
				__DEB("position found")
				node = _node_allocator.allocate(1);
				_node_allocator.construct(node, Node(val));
				node->parent = NULL;
				node->left = NULL;
				node->right = NULL;
			}
			else if (val == node->content)
				node->content = val;
			else if(val > node->content)
			{
				__DEB("going right")
				node->right = insert(node->right, val);
				node->right->parent = node;
			}
			else
			{
				__DEB("going left")
				node->left = insert(node->left, val);
				node->left->parent = node;
			}
			return (node);
		}

		// * Variables ________________________________________________________
	// protected:
		Node_pointer	_root;		// node data
		Type_Allocator	_type_allocator;
		Node_Allocator	_node_allocator;
		
	}; // * BinarySearchTree __________________________________________________
}

#endif
