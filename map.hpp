/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/27 02:26:08 by dait-atm         ###   ########.fr       */
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
#include "iterator/BST_bidirectional_iterator.hpp"
#include "iterator/reverse_iterator.hpp"
#include "utils/color.h"
#include "utils/ft_print_memory.h"
#include "utils/utility.hpp"
#include "utils/enable_if.hpp"

#include "utils/BinarySearchTree.hpp"

#define __DEB(s) std::cerr<<s<<std::endl;

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map /// * ___________________________________________________________  map
	{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<Key, T>							value_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef typename std::ptrdiff_t						difference_type;
		typedef size_t										size_type;
		typedef	value_type&									reference;
		typedef	const value_type&							const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;

		// typedef ft::BST_bidirectional_iterator<typename BinarySearchTree<value_type>::Node>			iterator;
		// typedef ft::BST_bidirectional_iterator<typename BinarySearchTree<const value_type>::Node>	const_iterator;
		typedef ft::BST_bidirectional_iterator<value_type>	iterator;
		typedef ft::BST_bidirectional_iterator<value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
	
		/// * Constructors & Destructors ______________________________________

	public:
		// ? (1) default empty map
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _allocator(alloc), _size(0) {}

		// ? (2) range
		// template <class InputIterator>
		// explicit map (InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type());

		// ? (3) copy
		// map (const map& x);

		~map(void)
		{
			clear();
		}

		map &		operator=(const map &	copy);

		/// * Element access __________________________________________________

		/// * Iterators _______________________________________________________

		iterator	begin()
		{
			// BST_Node<value_type, Compare, Allocator>* node = _bst.find_min();

			// if (node)
			// 	return (iterator(node->content));
			return (iterator(NULL));
		};

		iterator	end()		// ? could use a sentinel here and in begin
		{
			// if (!_size)
			// 	return (iterator(NULL));
			// std::cout << sizeof(std::string) << std::endl;
			// return ( iterator(_bst.find_max()->content + sizeof(value_type)) );
			return (iterator(NULL));
		};




		/// * Capacity ________________________________________________________

		bool		empty() const		{ return (_size > 0);	}

		size_type	size() const		{ return (_size);		}

		size_type	max_size() const	{ return (_allocator.max_size());	}

		/// * Modifiers _______________________________________________________
		// ? (1) default
		// pair<iterator, bool> 
		void		insert (const value_type& val)
		{
			_bst.insert(val);
			++_size;
		}

		// void		erase (iterator position);

		void clear()
		{
			_bst.clear();
			_size = 0;
		}

		/// * Lookup  _________________________________________________________

		size_type	count(const Key & key) const	{ return (_bst.search(key) ? true : false);	}

		void		display()	// ? debug
		{
			_bst.display();
		}
		
		/// * Observers  ______________________________________________________

		/// * Variables _______________________________________________________
	 	// ? Maps are typically implemented as balanced binary trees.
	// protected:
		BinarySearchTree<Key, T, key_compare, allocator_type>		_bst;
		size_type													_size;
		allocator_type												_allocator;
		key_compare													_comp;

	}; /// * map ______________________________________________________________

	/// * Non-member functions ________________________________________________
	
} /// * namespace ft __________________________________________________________

#endif