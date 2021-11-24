/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_Node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:43:00 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/24 03:28:16 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP
# define BST_NODE_HPP

#include <ostream>
#include "pair.hpp"

namespace ft
{
	// ? Node_content will allow the use of references on v
	// ! need to add Compare for operator== of bst's iterator
	template<class value_type>
	struct Node_content // * ___________________________________________________ Node_content
	{
		// * Constructor
		Node_content() : v(value_type()) {}
		Node_content(const value_type & val) : v(val) {}
		Node_content(const Node_content & copy) {	*this = copy;	}
		~Node_content() {}
		// * Non Member functions
		Node_content&	operator= (const Node_content & rhs)
		{
			if (this != &rhs)
				v = rhs.v;
			return (*this);
		}
		// * Variables
		value_type	v;
	}; // * ____________________________________________________________________

	// ? BST_Node is a node used in BinarySearchTree
	// template <typename T, class Type_Allocator = std::allocator<T> >
	template<	class Key,
				class T,
				class Compare = std::less<Key>,
				class Type_Allocator = std::allocator< ft::pair<Key, T> >,
				class Content_Allocator = std::allocator<Node_content< ft::pair<Key, T> > >
			>
	struct BST_Node // * _______________________________________________________ BST_Node
	{
		typedef ft::pair<Key, T>						value_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef typename Type_Allocator::pointer		pointer;
		typedef const pointer							const_pointer;

		// * Constructors & Destructors ________________________________________

		// * (1) default
		BST_Node ()
		{
			content = NULL;
			left = NULL;
			right = NULL;
			parent = NULL;
			height = 0;
			bf = 0;
		}

		// * (2) default with initialisation
		BST_Node (const_reference val, BST_Node* p = NULL, BST_Node* l = NULL, BST_Node* r = NULL)
		{
			content = new Node_content<value_type>();
			content->v = val;
			parent = p;
			left = l;
			right = r;
			height = 0;
			bf = 0;
		}

		// * (3) copy by duplicating data
		BST_Node (const BST_Node & copy)
		{
			content = new Node_content<value_type>();
			content = copy.content;
			parent = copy.parent;
			left = copy.left;
			right = copy.right;
			height = copy.height;
			bf = copy.bf;
		}

		~BST_Node ()
		{
			delete content;
		}

		// * Operators _________________________________________________________
		
		BST_Node &		operator= (const BST_Node & rhs)
		{
			if (this != &rhs)
			{
				if (!content)
					content = new Node_content<value_type>(rhs->content->val);
				else
					this->content = rhs->content;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				height = rhs.height;
				bf = rhs.bf;
			}
			return (*this);
		}

		// ? makes the creation of nodes easier
		BST_Node*		insert (const value_type &val)
		{
			content = new Node_content<value_type>(val);
			left = NULL;
			right = NULL;
			parent = NULL;
			height = 0;
			bf = 0;
			return (this);
		}

		// * Variables _________________________________________________________

		Node_content<value_type>*	content;		// pointer on Node_content
		BST_Node*					left;			// left node
		BST_Node*					right;			// right node
		BST_Node*					parent;			// parent node
		size_t						height = 0;			// height from leaf to root
		size_t						bf;				// balance factor

	};  // * BST_Node __________________________________________________________

	// ? comparing content of the nodes to make code writing easier ?
	// template <class value_type>
	// bool	operator==(Node_content n1, Node_content n2) {}

}

#endif
