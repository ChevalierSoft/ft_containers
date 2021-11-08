/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/08 16:08:36 by dait-atm         ###   ########.fr       */
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
	template<	class Key,
				class T,
				class Compare = std::less<Key>,
				class Allocator = std::allocator< ft::pair<Key, T> >
			>
	class map /// * ___________________________________________________________  map
	{
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<Key, T>								value_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef typename std::ptrdiff_t							difference_type;
		typedef size_t											size_type;
		typedef	value_type&										reference;
		typedef	const value_type&								const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef ft::BST_bidirectional_iterator<ft::pair<Key, T> > iterator;
		typedef const iterator									const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	
	protected:
		typedef	BinarySearchTree<Key, T, key_compare, allocator_type>	Tree_Type;
		typedef	typename Tree_Type::Node								Node_Type;
		typedef	typename Tree_Type::Node*								Node_pointer;
	
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

		iterator	begin() const
		{
			Node_pointer node = _bst.find_min();

			if (node)
			{
				iterator it(node->content);
				return (it);
			}
			return (iterator(NULL));
		}

		iterator	end()		// ? could use a sentinel here and in begin
		{
			if (!_size)
				return (iterator(NULL));
			// std::cout << sizeof(std::string) << std::endl;
			return ( iterator(_bst.find_max()->content) );	// + sizeof(value_type)
			// return (iterator(NULL));
		};

// ft::BST_Node<int, std::__cxx11::basic_string<char>, std::less<int>, std::allocator<ft::pair<int, std::__cxx11::basic_string<char> > > > *
// BST_bidirectional_iterator<int, std::__cxx11::basic_string<char> >


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

		// DEBUG
	public:
		void	print_bst()
		{
			_bst.print_bst();
		}

		void		display()	// ? debug
		{
			_bst.display();
			// _bst.print_bst();
		}
		
		/// * Observers  ______________________________________________________

		/// * Variables _______________________________________________________
	 	// ? Maps are typically implemented as balanced binary trees.
	// protected:
		Tree_Type													_bst;
		size_type													_size;
		allocator_type												_allocator;
		key_compare													_comp;

	}; /// * map ______________________________________________________________

	/// * Non-member functions ________________________________________________
	
} /// * namespace ft __________________________________________________________

#endif