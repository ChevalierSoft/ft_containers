/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/05 02:55:25 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>									// std::cout
#include <stdexcept>								// std::exception
#include <functional>								// std::less
#include <memory>									// std::allocator
#include "iterator/iterator.h"
#include "iterator/BST_bidirectional_iterator.hpp"
#include "iterator/reverse_iterator.hpp"
#include "utils/color.h"
#include "utils/ft_print_memory.h"
#include "utils/utility.hpp"
#include "utils/enable_if.hpp"

#include "utils/BinarySearchTree.hpp"

#define __DEB(s)	std::cerr<<s<<std::endl;

namespace ft
{
	template<	class Key,
				class T,
				class Compare = std::less<Key>,
				class Allocator = std::allocator< ft::pair<Key, T> >
			>
	class map /// * ____________________________________________________________ ft::map
	{
	private:
		typedef
			typename std::allocator_traits<Allocator>::template 
			rebind_alloc<BST_Node<Key, T>>						Node_Allocator;

	protected:
		typedef	BinarySearchTree<Key, T, Compare, Node_Allocator>	Tree_Type;
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
		typedef ft::BST_bidirectional_iterator<Node_Type>		iterator;
		typedef const iterator									const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	

		class value_compare;


		/// * Constructors & Destructors _______________________________________

	public:
		// ? (1) default empty map
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _comp(comp), _allocator(alloc), _size(0)
		{}

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

		mapped_type&				operator[](const key_type& k)
		{
			Node_pointer	node;
			
			node = _bst.search(k);
			// if the key doesn't exist, create a new node with it
			if (!node)
				return ((insert(ft::make_pair<Key, mapped_type>(k, mapped_type())).first)->second);
			return (node->content.second);
		}

		/// * Iterators ________________________________________________________

		iterator					begin () 			{ return ( iterator(_bst._cardinal->left, _bst._cardinal) );		}

		const_iterator				begin () const		{ return ( const_iterator(_bst._cardinal->left, _bst._cardinal) );	}

		iterator					end () 				{ return ( iterator(_bst._cardinal, _bst._cardinal, 1) );			}

		const_iterator				end () const		{ return ( const_iterator(_bst._cardinal, _bst._cardinal, 1) );		}

		reverse_iterator			rbegin()			{ return ( reverse_iterator(const_iterator(end())) );				}

		const_reverse_iterator		rbegin() const		{ return ( const_reverse_iterator(const_iterator(end())) );			}

		reverse_iterator			rend()				{ return ( reverse_iterator(begin()) );								}

		const_reverse_iterator		rend() const		{ return ( const_reverse_iterator(begin()) );						}

		/// * Capacity _________________________________________________________

		bool						empty () const		{ return (_size == 0);					}

		size_type					size () const		{ return (_size);						}

		size_type					max_size () const	{ return (_node_allocator.max_size());	}

		/// * Modifiers ________________________________________________________
		// ? (1) default

		ft::pair<iterator, bool>	insert (const value_type& val)
		{
			ft::pair<iterator, bool> p(_bst.insert(val));
			_size += p.second;
			return (p);
		}

		void						erase (iterator position)
		{
			if (_size)
				_size -= _bst.remove(position->first);
		}

		void						swap (map & x)
		{
			Node_pointer	ptr;
			Compare			cmp;
			Node_Allocator	na;
			size_type		num;

			if (this == &x)
				return;

			// _cardinal
			ptr = x._bst.get_cardinal();
			x._bst.set_cardinal(this->_bst.get_cardinal());
			this->_bst.set_cardinal(ptr);

			// _root
			ptr = x._bst.get_root();
			x._bst.set_root(this->_bst.get_root());
			this->_bst.set_root(ptr);

			// _comp
			cmp = x._bst.get_comp();
			x._bst.set_comp(this->_bst.get_comp());
			this->_bst.set_comp(cmp);

			// _node_allocator
			na = x._bst.get_allocator();
			x._bst.set_allocator(this->_bst.get_allocator());
			this->_bst.set_allocator(na);

			// size
			num = x._size;
			x._size = this->_size;
			this->_size = num;
		}

		void 						clear ()
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
		}
		
		/// * Observers  _______________________________________________________

		key_compare					key_comp () const	{ return (key_compare(_comp));				}

		value_compare				value_comp() const	{ return (value_compare(key_compare()));	}


		/// * Variables ________________________________________________________
		
	 	// ? Maps are typically implemented as balanced binary trees.
	// protected:
		Tree_Type					_bst;				// binary search tree where data is stored
		size_type					_size;				// how many nodes there is in the tree
		allocator_type				_allocator;			// not used here but in _bst
		Node_Allocator				_node_allocator;	// used in max_size
		key_compare					_comp;				// not used here but is used in _bst

	}; /// * map _______________________________________________________________

	/// * Non-member functions _________________________________________________
	
	// template<	class Key,
	// 			class T,
	// 			class Compare = std::less<Key>,
	// 			class Allocator = std::allocator< ft::pair<Key, T> >
	// 		>
	// bool	operator==(ft::map<Key, T, Compare, Allocator)


	template <class Key, class T, class Compare, class Alloc>
	class ft::map<Key,T,Compare,Alloc>::value_compare
	{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

} /// * namespace ft ___________________________________________________________

#endif