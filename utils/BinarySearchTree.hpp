/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:44:33 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/21 03:55:50 by dait-atm         ###   ########.fr       */
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
		
		~BinarySearchTree() {	erase(_root);	}

		// * Modifiers ________________________________________________________

		void			erase(Node_pointer node)
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

		Node_pointer	insert(Node_pointer node, const_reference val)
		{
			// __DEB("insert");
			if(node == NULL)
			{
				// __DEB("position found")
				node = _node_allocator.allocate(1);
				_node_allocator.construct(node, Node(val));
				node->parent = NULL;
				node->left = NULL;
				node->right = NULL;
			}
			else if (val == node->content)
				node->content = val;
			else if(val < node->content)
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
			
			return (node);
		}

		size_type		get_max_floor(Node_pointer node)
		{
			int l = 0;
			int r = 0;

			if (node->left)
				l = 1 + get_max_floor(node->left);

			if (node->right)
				r = 1 + get_max_floor(node->right);

			return (l > r) ? l : r;
		}

		// ? (1) default
		void			display(Node_pointer node)
		{
			size_type	len = get_max_floor(node);
			// std::cout << "get_max_floor : " << len << std::endl;

			if (node->left)
				display(node->left);
			if (node)
			{
				std::cout << std::string( ((len * 6) / 2) + 1, ' ' );
				std::cout << node->content;
				std::cout << std::string( ((len * 6) / 2) + 1, ' ' );
			}
			else
				std::cout << std::string( len * 6 + 1 + 6, ' ' );
			
			if (node->right)
				display(node->right);

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
