/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_Node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:43:00 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/26 06:23:35 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP
# define BST_NODE_HPP

#include <ostream>
#include "pair.hpp"

namespace ft
{
	// ? BST_Node is a node used in BinarySearchTree
	template< class T, class Compare = std::less<T>, class Type_Allocator = std::allocator< T > >
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
		BST_Node() : content(NULL), left(NULL), right(NULL), parent(NULL) {}

		// * default with initialisation (2)
		BST_Node(const_reference val, BST_Node* p = NULL, BST_Node* l = NULL, BST_Node* r = NULL)
		{
			this->content = _allocator.allocate(1);
			_allocator.construct(this->content, val);
			parent = p;
			left = l;
			right = r;

		}

		// * (3) copy by duplicating data
		BST_Node(const BST_Node & copy) : parent(copy.parent), left(copy.left), right(copy.right)
		{
			content = _allocator.allocate(1);
			_allocator.construct(&this->content, copy.content);
		}

		~BST_Node()
		{
			if (this->content)
			{
				_allocator.destroy(this->content);
				_allocator.deallocate(this->content, 1);
			}
		}

		// * Operators ________________________________________________
		BST_Node &		operator= (const BST_Node & rhs)
		{
			if (this != &rhs)
			{
				//content = rhs.content;
				if (content)
				{
					_allocator.destroy(this->content);
					_allocator.construct(this->content, rhs.content);
				}

				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
			}
			return (*this);
		}


		// * Variables ________________________________________________
		value_type*		content;
		BST_Node*		left;		// left node
		BST_Node*		right;		// right node
		BST_Node*		parent;		// parent node
		Type_Allocator	_allocator;

	};  // * BST_Node _________________________________________________  

	// // * Comparisons specific to BST so we will be comparing only the key
	// template< class T, class Compare = std::less<T>, class Type_Allocator = std::allocator< T > >
	// bool			operator==(const ft::BST_Node<T, Compare, Type_Allocator> & lhs, const ft::BST_Node<T, Compare, Type_Allocator> & rhs)
	// {
	// 	return (!Compare(lhs.content->first, rhs.content->first) && !Compare(rhs.content->first, lhs.content->first));
	// }


}

#endif
