/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_Node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:43:00 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/23 08:44:21 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP
# define BST_NODE_HPP

#include <ostream>
#include "pair.hpp"

namespace ft
{
	// ? BST_Node is a node used in BinarySearchTree
	template< class T, class Type_Allocator = std::allocator< T > >
	struct BST_Node // * _______________________________________________  BST_Node
	{
		typedef T										value_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef typename Type_Allocator::pointer		pointer;
		typedef typename Type_Allocator::const_pointer	const_pointer;

		// * Constructors & Destructors _______________________________

		// * default (1)
		BST_Node() : content(), left(NULL), right(NULL), parent(NULL) {}

		// * default with initialisation (2)
		BST_Node(const_reference val, BST_Node* p = NULL, BST_Node* l = NULL, BST_Node* r = NULL) : content(val), left(l), right(r), parent(p) {}

		// * copy (3)
		BST_Node(const BST_Node & copy) : content(copy.content), left(copy.left), right(copy.right), parent(copy.parent) {}

		~BST_Node() {}

		// * Operators ________________________________________________
		BST_Node &		operator= (const BST_Node & rhs)
		{
			if (this != &rhs)
			{
				content = rhs.content;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
			}
			return (*this);
		}

		bool			operator==(const BST_Node & rhs)
		{
			return (content == rhs.content);
		}

		// * Variables ________________________________________________
		value_type		content;
		BST_Node*		left;		// left node
		BST_Node*		right;		// right node
		BST_Node*		parent;		// parent node

	};  // * BST_Node _________________________________________________  

}

#endif