/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/19 00:41:44 by dait-atm         ###   ########.fr       */
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
	class map /// * ____________________________________________________________ ft::map
	{

	protected:
		typedef	BinarySearchTree<Key, T, Compare, Allocator>	Tree_Type;
		typedef	typename Tree_Type::Node						Node_Type;
		typedef	typename Tree_Type::Node*						Node_pointer;

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
		typedef ft::BST_bidirectional_iterator<Node_Type, Compare> iterator;
		typedef const iterator									const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	
	
		/// * Constructors & Destructors _______________________________________

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

		/// * Element access ___________________________________________________

		/// * Iterators ________________________________________________________

		iterator	begin () const
		{
			if (_bst._cardinal->left)
			{
				return (iterator(_bst._cardinal->left, _bst._cardinal));
			}
			return (iterator());
		}

		iterator	end ()		// ? could use a sentinel here and in begin
		{
			return (iterator(_bst._cardinal, _bst._cardinal, 1));
		};

// ft::BST_Node<int, std::__cxx11::basic_string<char>, std::less<int>, std::allocator<ft::pair<int, std::__cxx11::basic_string<char> > > > *
// BST_bidirectional_iterator<int, std::__cxx11::basic_string<char> >


		/// * Capacity _________________________________________________________

		bool						empty () const		{ return (_size > 0);	}

		size_type					size () const		{ return (_size);		}

		size_type					max_size () const	{ return (_allocator.max_size());	}

		/// * Modifiers ________________________________________________________
		// ? (1) default

		ft::pair<iterator, bool>	insert (const value_type& val)
		{
			return (_bst.insert(val));
		}

		// void					erase (iterator position);

		void 					clear ()
		{
			_bst.clear();
			_size = 0;
		}

		/// * Lookup  __________________________________________________________

		size_type					count (const Key & key) const	{ return (_bst.search(key) ? true : false);	}

		// ! DEBUG
	public:
		void						print_bst ()
		{
			_bst.print_bst();
		}

		void						display ()	// ? debug
		{
			_bst.display();
			// _bst.print_bst();
		}
		
		/// * Observers  _______________________________________________________

		/// * Variables ________________________________________________________
		
	 	// ? Maps are typically implemented as balanced binary trees.
	// protected:
		Tree_Type					_bst;
		size_type					_size;
		allocator_type				_allocator;
		key_compare					_comp;

	}; /// * map _______________________________________________________________

	/// * Non-member functions _________________________________________________
	
} /// * namespace ft ___________________________________________________________

#endif