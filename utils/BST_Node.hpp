/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_Node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:43:00 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/10 14:22:01 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP
# define BST_NODE_HPP

#include <ostream>
#include "pair.hpp"

namespace ft
{
	// ? BST_Node is a node used in BinarySearchTree
	// template <typename T, class Type_Allocator = std::allocator<T> >
	template<	class Key,
				class T,
				class Compare = std::less<Key>,
				class Type_Allocator = std::allocator< ft::pair<Key, T> >
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
		// typedef Compare									key_compare;

			// ? Node_content will allow the use of references on v
			struct Node_content // ? _______________________________________________ Node_content
			{
				// ? Constructor
				Node_content() : v(value_type()) {}
				Node_content(const_reference val) : v(val) {}
				Node_content(const Node_content & copy) {	*this = copy;	}
				~Node_content() {}
				// ? Non Member functions
				Node_content&	operator= (const Node_content & rhs)
				{
					if (this != &rhs)
						v = rhs.v;
					return (*this);
				}
				// ? Variables
				value_type	v;
			}; // ? ________________________________________________________________
			typedef std::allocator<Node_content>			Content_Allocator;

		// * Constructors & Destructors ________________________________________

		// * (1) default
		BST_Node()
		{
			// content = _content_allocator.allocate(1);
			content = new Node_content();
			// content->v = value_type();
			left = NULL;
			right = NULL;
			parent = NULL;
		}

		// * (2) default with initialisation
		BST_Node(const_reference val, BST_Node* p = NULL, BST_Node* l = NULL, BST_Node* r = NULL)
		{
			// _content_allocator = std::allocator<Node_content>();
			// content = _content_allocator.allocate(1);
			// // this->content->v = val;

			content = new Node_content();
			content->v = val;
			parent = p;
			left = l;
			right = r;
		}

		// * (3) copy by duplicating data
		BST_Node(const BST_Node & copy) : parent(copy.parent), left(copy.left), right(copy.right)
		{
			// _content_allocator = std::allocator<Node_content>();
			// content = _content_allocator.allocate(1);
			// // _type_allocator.construct(this->content->v, copy.content->v);
			// this->content->v = copy.content->v;
			
			content = new Node_content();
			content = copy.content;
		}

		~BST_Node()
		{
			// // if (this->content)
			// // {
			// 	// _content_allocator.destroy(this->content);
				// _content_allocator.deallocate(this->content, 1);
			// // }
			
			delete content;
		}

		// * Operators _________________________________________________________
		
		BST_Node &		operator= (const BST_Node & rhs)
		{
			if (this != &rhs)
			{
				// // if (content)
				// // {
				// 	// _type_allocator.destroy(this->content);
				// 	_type_allocator.construct(this->content, rhs.content);
				// 	this->content->v = rhs.content->v;
				// // }
				this->content = rhs->content;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
			}
			return (*this);
		}

		// ? makes the creation of nodes easier
		BST_Node*		insert(const value_type &val)
		{
			// content = _content_allocator.allocate(1);
			// content->v = val;
			content = new Node_content(val);
			left = NULL;
			right = NULL;
			parent = NULL;
			return (this);
		}

		// * Variables _________________________________________________________
		// pointer			content;
		Node_content*		content;			// pointer on Node_content
		BST_Node*			left;				// left node
		BST_Node*			right;				// right node
		BST_Node*			parent;				// parent node
		Type_Allocator		_type_allocator;	// allocator for value_type
		Content_Allocator	_content_allocator;	// allocator for Content
		// std::allocator<Node_content>	_content_allocator;

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
