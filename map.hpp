/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/22 07:59:13 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>									// std::cout
#include <stdexcept>								// std::exception
#include <functional>								// std::less
#include <memory>									// std::allocator
#include "iterator/BST_bidirectional_iterator.hpp"
#include "iterator/reverse_iterator.hpp"
#include "utils/utility.hpp"
#include "utils/BinarySearchTree.hpp"

namespace ft
{
	template<	class Key,
				class T,
				class Compare = std::less<Key>,
				class Allocator = std::allocator< ft::pair<Key, T> >
			>
	class map /// * ____________________________________________________________ ft::map
	{
		/// * Friend class _____________________________________________________
	public:
		class value_compare;

	private:
		typedef
			typename Allocator::template
			rebind<ft::BST_Node<Key, T> >::other						Node_Allocator;

	protected:
		typedef	BinarySearchTree<Key, T, Compare, Node_Allocator>		Tree_Type;
		typedef	typename Tree_Type::Node								Node_Type;
		typedef	typename Tree_Type::Node*								Node_pointer;

	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<Key, T>										value_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef typename std::ptrdiff_t									difference_type;
		typedef size_t													size_type;
		typedef	value_type&												reference;
		typedef	const value_type&										const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;

		typedef ft::BST_bidirectional_iterator<BST_Node<Key, T> >									iterator;
		typedef ft::BST_const_bidirectional_iterator<BST_Node<Key, T> >								const_iterator;
		typedef ft::reverse_iterator<ft::BST_bidirectional_iterator<BST_Node<Key, T> > >			reverse_iterator;
		typedef ft::reverse_iterator<ft::BST_const_bidirectional_iterator<BST_Node<Key, T> > >		const_reverse_iterator;

		// template <class Key, class T, class Compare, class Alloc>
		class value_compare
		: ft::binary_function<value_type, value_type, bool>
		{
			// friend should be used to make constructor private/protected
			// friend class map;

			// * Constructor / Destructor __________________________________________

		// private:
		public:
			value_compare () : comp(Compare()) {}
		// protected:
			value_compare (Compare c) : comp(c) {}
		public:
			~value_compare () {}

			value_compare (const value_compare& copy)	{ *this = copy;	}

			value_compare&	operator= (const value_compare& copy)
			{
				if (this != &copy)
					comp = copy.comp;
				return (*this);
			}

			// * Member functions __________________________________________________
			
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
			
			// * Variables _________________________________________________________

		protected:
			Compare comp;
		};


		/// * Constructors & Destructors _______________________________________

	public:
		// ? (1) default empty map
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _size(0), _allocator(alloc), _comp(comp)
		{}

		// ? (2) range
		template <class InputIterator>
		explicit map (	InputIterator first,
						InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
		: _bst(), _size(0), _allocator(alloc), _comp(comp)
		{
			this->insert(first, last);
		}

		// ? (3) copy
		map (const map & copy)
		: _bst(), _allocator(copy._allocator),
			_node_allocator(copy._node_allocator), _comp(copy._comp)
		{
			for (const_iterator it = copy.begin(); it != copy.end(); ++it)
				this->insert(*it);
			_size = copy._size;
		}

		~map(void)
		{
			clear();
		}

		map &						operator=(const map& rhs)
		{
			if (this != &rhs)
			{
				this->clear();
				for (const_iterator it = rhs.begin(); it != rhs.end(); ++it)
					this->insert(*it);
				_size = rhs._size;
				_allocator = rhs._allocator;
				_node_allocator = rhs._node_allocator;
				_comp = rhs._comp;
			}
			return (*this);
		}

		allocator_type				get_allocator() const
		{
			return (allocator_type());
		}

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

		iterator					end () 				{ return ( iterator(_bst._cardinal, _bst._cardinal) );			}

		const_iterator				end () const		{ return ( const_iterator(_bst._cardinal, _bst._cardinal) );		}

		reverse_iterator			rbegin()			{ return ( reverse_iterator(iterator(end())) );						}

		const_reverse_iterator		rbegin() const		{ return ( const_reverse_iterator(const_iterator(end())) );			}

		reverse_iterator			rend()				{ return ( reverse_iterator(begin()) );								}

		const_reverse_iterator		rend() const		{ return ( const_reverse_iterator(begin()) );						}

		/// * Capacity _________________________________________________________

		bool						empty () const		{ return (_size == 0);					}

		size_type					size () const		{ return (_size);						}

		// ? https://www.cplusplus.com/reference/map/map/max_size/
		size_type					max_size () const	{ return (_node_allocator.max_size());	}

		/// * Modifiers ________________________________________________________
		
		// ? (1) inserting a single element
		ft::pair<iterator, bool>	insert (const value_type& val)
		{
			ft::pair<iterator, bool>	p(_bst.insert(val));
			_size += p.second;
			return (p);
		}

		// ? (2) inserting with hint
		iterator					insert (iterator position, const value_type& val)
		{
			(void)position;
			return (insert(val).first);
		}

		// ? (3) inserting by range
		template <class InputIterator>
		void						insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		// ? (1) default
		void						erase (iterator position)
		{
			if (_size)
			{
				_size -= _bst.remove(position->first);
				if (!_size)
					_bst.clear();
			}
		}

		// ? (2) erase by key
		size_type					erase (const key_type& k)
		{
			size_type	ret = _bst.remove(k);
			_size -= ret;
			if (!_size)
				_bst.clear();
			return (ret);
		}

		// ? (3) erase by range
		void						erase (iterator first, iterator last)
		{
			key_type	key = first->first;
			key_type	next_key;

			while (first != end() && (_comp(key, last->first) || _comp(last->first, key)))
			{
				next_key = (++first)->first;
				_size -= _bst.remove(key);
				key = next_key;
				first = iterator(_bst.search(next_key), _bst.get_cardinal());
			}
			if (!_size)
				_bst.clear();
		}

		void						swap (map& x)
		{
			Node_pointer	ptr;
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

		size_type					count (const Key& key) const	{ return (_bst.search(key) ? true : false);	}

		iterator					find (const Key& key)
		{
			Node_pointer node = _bst.search(key);
			if (!node)
				return (end());
			return (iterator(node, _bst._cardinal));
		}

		const_iterator				find (const Key& key) const
		{
			Node_pointer node = _bst.search(key);
			if (!node)
				return (end());
			return (const_iterator(node, _bst._cardinal));
		}

		ft::pair<iterator, iterator>				equal_range(const Key& key)
		{
			return (ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const Key& key) const
		{
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		iterator					lower_bound(const Key& key)
		{
			iterator	it;

			it = begin();
			while (it != end())
			{
				if (!_comp(it->first, key))
					break ;
				++it;
			}
			return (it);
		}

		const_iterator				lower_bound(const Key& key) const
		{
			const_iterator	it;

			it = begin();
			while (it != end())
			{
				if (!_comp(it->first, key))
					break ;
				++it;
			}
			return (it);
		}

		iterator					upper_bound (const key_type& key)
		{
			iterator	it;

			it = begin();
			while (it != end())
			{
				if (_comp(key, it->first))
					break ;
				++it;
			}
			return (it);
		}

		const_iterator				upper_bound(const Key& key) const
		{
			const_iterator	it;

			it = begin();
			while (it != end())
			{
				if (_comp(key, it->first))
					break ;
				++it;
			}
			return (it);
		}

		/// * Observers  _______________________________________________________
	public:
		key_compare					key_comp () const	{ return (key_compare(_comp));				}

		value_compare				value_comp() const	{ return (value_compare(key_compare()));	}

		/// * Variables ________________________________________________________
	// public:
	 	// ? Maps are typically implemented as balanced binary trees.
	protected:
		Tree_Type					_bst;				// binary search tree where data is stored
		size_type					_size;				// how many nodes there is in the tree
		allocator_type				_allocator;			// not used here but in _bst
		Node_Allocator				_node_allocator;	// used in max_size
		key_compare					_comp;				// not used here but is used in _bst

	}; /// * map _______________________________________________________________

	/// * Non-member functions _________________________________________________
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator==(	const ft::map<Key, T, Compare, Alloc>& lhs,
						const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		typename ft::map<Key, T, Compare, Alloc>::value_compare		mycompare = lhs.value_comp();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator	lit(lhs.begin());
		typename ft::map<Key, T, Compare, Alloc>::const_iterator	rit(rhs.begin());

		if (lhs.size() != rhs.size())
			return (false);

		while (lit != lhs.end())
		{
			if (rit == rhs.end())
				return (false);
			if (mycompare(*lit, *rit) || mycompare(*rit, *lit))
				return (false);
			++lit;
			++rit;
		}
		return (true);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=(	const ft::map<Key, T, Compare, Alloc>& lhs,
						const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator< (	const ft::map<Key, T, Compare, Alloc>& lhs,
						const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator> (	const ft::map<Key, T, Compare, Alloc>& lhs,
						const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return (lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=(	const ft::map<Key, T, Compare, Alloc>& lhs,
						const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return !(lhs > rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=(	const ft::map<Key, T, Compare, Alloc>& lhs,
						const ft::map<Key, T, Compare, Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

} /// * namespace ft ___________________________________________________________

#endif