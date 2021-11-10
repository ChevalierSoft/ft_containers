/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_Node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:43:00 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/09 09:45:11 by dait-atm         ###   ########.fr       */
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
				class T,
				class Compare = std::less<Key>,
				class Type_Allocator = std::allocator< ft::pair<Key, T> >
			>
	// template <typename T, class Type_Allocator = std::allocator<T> >
	struct BST_Node // * _______________________________________________  BST_Node
	{
		typedef	typename Type_Allocator::value_type		value_type;
		// typedef ft::pair<Key, T>						value_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef typename Type_Allocator::pointer		pointer;
		typedef const pointer							const_pointer;
		// typedef Compare									key_compare;

		// * Constructors & Destructors _______________________________

		// ? (1) default
		BST_Node() : content(value_type()), left(NULL), right(NULL), parent(NULL) {}

		// ? (2) default with initialisation
		BST_Node(const_reference val, BST_Node* p = NULL, BST_Node* l = NULL, BST_Node* r = NULL)// : content(val)
		{
			// this->content = _type_allocator.allocate(1);
			// _type_allocator.construct(this->content, val);
			content = val;
			parent = p;
			left = l;
			right = r;
		}

		// ? (3) copy by duplicating data
		BST_Node(const BST_Node & copy)
		{
			// content = _type_allocator.allocate(1);
			// _type_allocator.construct(this->content, copy.content);
			*this = copy;
		}

		~BST_Node()
		{
			// if (this->content)
			// {
			// 	_type_allocator.destroy(this->content);
			// 	_type_allocator.deallocate(this->content, 1);
			// }
		}

		// * Operators ________________________________________________
		
		BST_Node &		operator= (const BST_Node & rhs)
		{
			if (this != &rhs)
			{
				// if (content)
				// {
					// _type_allocator.destroy(this->content);
				// 	_type_allocator.construct(this->content, rhs.content);
				// }
				// content = rhs.content;
				// _type_allocator.construct(this->content, rhs.content);
				content = rhs.content;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
			}
			return (*this);
		}

		// * non member functions

		BST_Node*		insert(const value_type &val)
		{
			// content = _type_allocator.allocate(1);
			// _type_allocator.construct(content, val);
			content = val;
			left = NULL;
			right = NULL;
			parent = NULL;
			return (this);
		}

		// * Variables ________________________________________________

		// pointer			content;
		value_type		content;
		BST_Node*		left;				// left node
		BST_Node*		right;				// right node
		BST_Node*		parent;				// parent node
		Type_Allocator	_type_allocator;

	};  // * BST_Node _________________________________________________  

	// * Comparisons specific to BST so we will be comparing only the key

	// template< class Key, class T, class Compare = std::less<Key>, class Type_Allocator = std::allocator< T > >
	// bool			operator==(const ft::BST_Node<Key, T, Compare, Type_Allocator> & lhs, const ft::BST_Node<Key, T, Compare, Type_Allocator> & rhs)
	// {
	// 	return (!Compare(lhs.content->first, rhs.content->first) && !Compare(rhs.content->first, lhs.content->first));
	// }

	// template< class Key, class T, class Compare = std::less<Key>, class Type_Allocator = std::allocator< T > >
	// bool			operator!=(const ft::BST_Node<Key, T, Compare, Type_Allocator> & lhs, const ft::BST_Node<Key, T, Compare, Type_Allocator> & rhs)
	// {
	// 	return !(lhs == rhs);
	// }

	// template< class Key, class T, class Compare = std::less<Key>, class Type_Allocator = std::allocator< T > >
	// bool			operator< (const ft::BST_Node<Key, T, Compare, Type_Allocator> & lhs, const ft::BST_Node<Key, T, Compare, Type_Allocator> & rhs)
	// {
	// 	return (Compare(lhs.content->first, rhs.content->first));
	// }

	// template< class Key, class T, class Compare = std::less<Key>, class Type_Allocator = std::allocator< T > >
	// bool			operator> (const ft::BST_Node<Key, T, Compare, Type_Allocator> & lhs, const ft::BST_Node<Key, T, Compare, Type_Allocator> & rhs)
	// {
	// 	return !(Compare(rhs.content->first, lhs.content->first));
	// }

	// template< class Key, class T, class Compare = std::less<Key>, class Type_Allocator = std::allocator< T > >
	// bool			operator<=(const ft::BST_Node<Key, T, Compare, Type_Allocator> & lhs, const ft::BST_Node<Key, T, Compare, Type_Allocator> & rhs)
	// {
	// 	return !(Compare(rhs.content->first, lhs.content->first));
	// }

	// template< class Key, class T, class Compare = std::less<Key>, class Type_Allocator = std::allocator< T > >
	// bool			operator>=(const ft::BST_Node<Key, T, Compare, Type_Allocator> & lhs, const ft::BST_Node<Key, T, Compare, Type_Allocator> & rhs)
	// {
	// 	return !(Compare(lhs.content->first, rhs.content->first));
	// }


}

#endif
