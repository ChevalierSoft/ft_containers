/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/20 07:20:26 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>		// std::cout
#include <stdexcept>	// std::exception
#include <functional>	// std::less
#include <memory>		// std::allocator
#include "iterator/iterator.h"
// #include "iterator/random_access_iterator.hpp"
#include "iterator/bidirectional_iterator.hpp"
#include "iterator/reverse_iterator.hpp"
#include "utils/color.h"
#include "utils/ft_print_memory.h"
#include "utils/utility.hpp"
#include "utils/enable_if.hpp"

#define __DEB(s) std::cerr<<s<<std::endl;

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>,
				class Allocator = std::allocator<std::pair<const Key, T> > >
	class map /// * ___________________________________________________________  map
	{
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef std::pair<const Key, T>					value_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef ft::bidirectional_iterator<T>			iterator;
		typedef ft::bidirectional_iterator<const T>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	
	// protected:
		class BinarySearchTree // ? ___________________________________________  BinarySearchTree
		{
		// protected:
			// ? BST_Node is a node used in BinarySearchTree
			struct BST_Node // ! _______________________________________________  BST_Node
			{
				// ! Constructors & Destructors _______________________________

				// ! default (1)
				BST_Node() : content(), parent(NULL), left(NULL), right(NULL) {}

				// ! default with initialisation (2)
				BST_Node(const_reference val, BST_Node* p = NULL, BST_Node* l = NULL, BST_Node* r = NULL) : content(val), parent(p), left(l), right(r) {}

				// ! copy (3)
				BST_Node(const BST_Node & copy) : content(copy.content), parent(copy.parent), left(copy.left), right(copy.right) {}

				~BST_Node() {}

				// ! Operators ________________________________________________
				BST_Node &		operator= (const BST_Node & rhs)
				{
					if (this != &rhs)
					{
						content = rhs.content;
						parent = rhs.parent;
						left = rhs.left;
						right = rhs.right;
					}
					return (*this);
				}

				bool			operator==(const BST_Node & rhs)
				{
					return (content == rhs.content);
				}

				// ! Variables ________________________________________________
				value_type		content;
				BST_Node*		parent;		// parent node
				BST_Node*		left;		// left node
				BST_Node*		right;		// right node

			};  // ! BST_Node _________________________________________________  

			// ? Constructors & Destructors ___________________________________
		public:
			BinarySearchTree() : _root() {}

			BinarySearchTree(const_reference val) : _root(val) {}
			
			~BinarySearchTree() {}

			// ? Modifiers ____________________________________________________

			void			insert(const_reference val)
			{
				// BST_Node	n(val);
				// BST_Node*	pos = get_closest_preorder();

				// if (pos->parent->right == pos)
				// 	pos->parent->right = &n

			}

			// ? Variables ____________________________________________________
		protected:
			BST_Node		_root;		// node data
			allocator_type	_allocator;
			
		}; // ? BinarySearchTree ______________________________________________

		/// * Constructors & Destructors ______________________________________

	public:
		// ? empty (1)
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _allocator(alloc) {}

		// ? range (2)
		// template <class InputIterator>
		// explicit map (InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type());

		// ? copy (3)
		// map (const map& x);

		~map(void) {}

		map &	operator=(const map &	copy);

		/// * Element access __________________________________________________

		/// * Iterators _______________________________________________________
		
		/// * Capacity ________________________________________________________

		/// * Modifiers _______________________________________________________

		/// * Lookup  _________________________________________________________

		/// * Observers  ______________________________________________________

		/// * Variables _______________________________________________________
	 	// ? Maps are typically implemented as balanced binary trees.
	private:
		BinarySearchTree	_bst;
		key_compare			_comp;
		allocator_type		_allocator;

	}; /// * map ______________________________________________________________

	/// * Non-member functions ________________________________________________
	
} /// * namespace ft __________________________________________________________

#endif