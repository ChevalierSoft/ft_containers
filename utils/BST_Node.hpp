/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_Node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:43:00 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/15 18:36:32 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP
# define BST_NODE_HPP

#include <ostream>
#include "pair.hpp"

namespace ft
{
	// ? BST_Node is a node used in BinarySearchTree
	template<	class Key,
				class T
			>
	struct BST_Node // * _______________________________________________________ BST_Node
	{
		typedef ft::pair<Key, T>						value_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const pointer							const_pointer;

		// * Constructors & Destructors ________________________________________

		// * (1) default
		BST_Node ()
		: content(), left(NULL), right(NULL), parent(NULL), height(0), bf(0)
		{}

		// * (2) default with initialisation
		BST_Node (const_reference val, BST_Node* p = NULL, BST_Node* l = NULL, BST_Node* r = NULL)
		: content(val), left(l), right(r), parent(p), height(0), bf(0)
		{}

		// * (3) copy by duplicating data
		BST_Node (const BST_Node & copy)
		{
			*this = copy; 
		}

		~BST_Node () {}

		// * Operators _________________________________________________________
		
		BST_Node &		operator= (const BST_Node & rhs)
		{
			if (this != &rhs)
			{
				content = rhs.content;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				height = rhs.height;
				bf = rhs.bf;
			}
			return (*this);
		}

		// * Variables _________________________________________________________

		value_type		content;	// the pair
		BST_Node*		left;		// left node
		BST_Node*		right;		// right node
		BST_Node*		parent;		// parent node
		size_t			height;		// height from leaf to root
		size_t			bf;			// balance = right length - left length

	};  // * BST_Node __________________________________________________________

}

#endif
