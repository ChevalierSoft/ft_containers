/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:44:33 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/07 08:39:10 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

#include <functional>										// std::less
#include <memory>											// std::allocator
#include "BST_Node.hpp"
#include "../iterator/iterator.h"
#include "../iterator/BST_bidirectional_iterator.hpp"
#include "BST_Node.hpp"

#define __DEB(s) std::cerr<<s<<std::endl;

namespace ft
{
	template<	class Key,
				class T,
				class Compare = std::less<Key>, 
				class Type_Allocator = std::allocator< ft::pair<Key, T> >,
				class N = ft::BST_Node<Key, T, Compare, Type_Allocator>,
				class Node_Allocator = std::allocator< N >
			>
	class BinarySearchTree // * _______________________________________________  BinarySearchTree
	{
	public:
		typedef ft::pair<Key, T>						value_type;
		typedef	T										data_type;
		typedef N										Node;
		typedef Compare									type_compare;
		typedef typename std::ptrdiff_t					difference_type;
		typedef size_t									size_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef typename Node_Allocator::pointer		Node_pointer;
		typedef typename Node_Allocator::const_pointer	Node_const_pointer;
		// typedef ft::BST_bidirectional_iterator<Node>	iterator;
		// typedef ft::BST_bidirectional_iterator<const Node>	const_iterator;
		// typedef ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// * Constructors & Destructors _______________________________________
	public:
		BinarySearchTree () : _root(NULL), _type_allocator(Type_Allocator()), _node_allocator(Node_Allocator()) 
		{
			_cardinal = _node_allocator.allocate(1);
			_cardinal->content = NULL;
			_cardinal->parent = NULL;
			_cardinal->left = NULL;
			_cardinal->right = NULL;
		}

		BinarySearchTree (const_reference val, Type_Allocator ta = Type_Allocator(), Node_Allocator na = Node_Allocator()) : _type_allocator(ta), _node_allocator(na)
		{
			_root = _node_allocator.allocate(1);
			_node_allocator.construct(_root, val);

			_cardinal = _node_allocator.allocate(1);
			_cardinal->content = NULL;
			_cardinal->parent = _root;
			_cardinal->left = _root;
			_cardinal->right = _root;
		}
		
		~BinarySearchTree (void)
		{
			_node_allocator.deallocate(_cardinal, 1);
			clear(_root);
		}

		// * Modifiers ________________________________________________________

	protected:
		size_type		get_last_floor (Node_pointer node) const
		{
			int l = -1;
			int r = -1;

			if (!node)
				return (0);

			if (node->left)
				l = get_last_floor(node->left);
			if (node->right)
				r = get_last_floor(node->right);

			return (l > r) ? l + 1 : r + 1;
		}

		long			get_balance (Node_pointer node)
		{
			if (node)
				return(get_last_floor(node->right) - get_last_floor(node->left));
			return (0);
		}

		// * Rotations ________________________________________________________

		Node_pointer	right_rotation(Node_pointer node)
		{
			Node_pointer	tmp;

			tmp = node->left;
			node->left = tmp->right;
			tmp->right = node;
			// update parent
			tmp->parent = node->parent;
			node->parent = tmp;
			return (tmp);
		}

		Node_pointer	left_rotation(Node_pointer node)
		{
			Node_pointer	tmp;

			tmp = node->right;
			node->right = tmp->left;
			tmp->left = node;
			// update parent
			tmp->parent = node->parent;
			node->parent = tmp;
			return (tmp);
		}

		//	    ,o.
		//    ,o.
		//  ,o.
		Node_pointer	left_left_rotation(Node_pointer node)
		{
			return (right_rotation(node));
		}

		//	    ,o.
		//    ,o.
		//      ,o.
		Node_pointer	left_right_rotation(Node_pointer node)
		{
			node->left = left_rotation(node->left);
			return (right_rotation(node));
		}

		//	    ,o.
		//        ,o.
		//          ,o.
		Node_pointer	right_right_rotation(Node_pointer node)
		{
			return (left_rotation(node));
		}

		//	    ,o.
		//        ,o.
		//      ,o.
		Node_pointer	right_left_rotation(Node_pointer node)
		{
			node->right = right_rotation(node->right);
			return (left_rotation(node));
		}

		Node_pointer	balance (Node_pointer node)
		{
			long	b;

			if (!node)
				return (NULL);

			b = get_balance(node);

			// too much nodes left
			if (b == -2)
			{
				if (get_balance(node->left) <= 0)
					return (left_left_rotation(node));
				else
					return (left_right_rotation(node));
			}
			// too much nodes right
			else if (b == 2)
			{
				if (get_balance(node->right) <= 0)
					return (right_left_rotation(node));
				else
					return (right_right_rotation(node));
			}
			// node is already balanced
			return (node);
		}

	public:
		// ? (1) default: public
		void			clear ()
		{
			clear(_root);
			_root = NULL;
			_cardinal->parent = NULL;
			_cardinal->left = NULL;
			_cardinal->right = NULL;
		}

	private:
		// ? (2) clear from a specific node
		void			clear (Node_pointer node)
		{
			if(node != NULL && node != _cardinal)
			{
				clear(node->left);
				clear(node->right);
				_node_allocator.destroy(node);
				_node_allocator.deallocate(node, 1);
				// node = NULL;	// * it may be faster without
			}
		}
	public:
		// ? (1) default: public
		bool			remove (const Key key)
		{
			bool	found = false;
			// this can be inproved for performences
			// if (this->search(key))
			// {

				if (_cardinal->left && key == _cardinal->left->content->first)
					_cardinal->left = _cardinal->left->parent;
				else if (_cardinal->right && key == _cardinal->right->content->first)
					_cardinal->right = _cardinal->right->parent;					

				_root = remove(_root, key, &found);
				_cardinal->parent = _root;
				// return (true);
			// }
			// return (false);
			return (found);
		}

	private:
		// ? (2) remove a specific 'node' identified by key
		Node_pointer	remove (Node_pointer node, const Key key, bool *found)
		{
			Node_pointer	successor;
			Node_pointer	ret;

			if (!node)
				return (node);
				
			// search for the key in the tree
			if (key < node->content->first)
			{
				node->left = this->remove(node->left, key, found);
			}
			else if (key > node->content->first)
			{
				node->right = this->remove(node->right, key, found);
			}
			// got the key
			else
			{
				*found = true;
				if (!node->left && !node->right)
				{
					// __DEB("no child")
					_node_allocator.destroy(node);
					_node_allocator.deallocate(node, 1);
					return (NULL);
				}
				// the node have no right branch
				if (!node->right)
				{
					// __DEB("(!node->right)")
					ret = node->left;
					// update parent
					if (ret)
						ret->parent = node->parent;
					// delete the node
					_node_allocator.destroy(node);
					_node_allocator.deallocate(node, 1);

					// return the left branch (can be NULL)
					return (ret);
				}
				// the node have no left branch
				else if (!node->left)
				{
					// __DEB("(!node->left)")
					ret = node->right;
					// update parent
					if (ret)
						ret->parent = node->parent;
					// delete the node
					_node_allocator.destroy(node);
					_node_allocator.deallocate(node, 1);
					// return the right branch (can be NULL)
					return (ret);
				}

				// replace node with the biggest sub tree
				if (get_last_floor(node->left) > get_last_floor(node->right))
				{
					// __DEB("(balance left)")
					successor = find_max(node->left);
					*node->content = *successor->content;
					node->left = remove(node->left, successor->content->first, found);
				}
				else
				{
					// __DEB("(other balances)")
					successor = find_min(node->right);
					*node->content = *successor->content;
					node->right = remove(node->right, successor->content->first, found);
				}

			}
				
			return (this->balance(node));

		}

	public:

		// ? (1) default
		Node_pointer	find_max (void) const
		{
			return (find_max(_root));
		}

		// ? (2) get to the maximum key from node
		Node_pointer	find_max (Node_pointer node) const
		{
			if (!node)
				return (NULL);
			while (node->left != NULL)
				node = node->left;
			return (node);
		}

		// ? (1) default
		Node_pointer	find_min (void) const
		{
			return (find_min(_root));
		}

		// ? (2) get to the minimum key from node
		Node_pointer	find_min (Node_pointer node) const
		{
			if (!node)
				return (NULL);
			while (node->left != NULL)
				node = node->left;
			return (node);
		}

		// ? (1) default: insert from _root
		Node_pointer	insert (const_reference val)
		{
			// std::cout << "insert()" << std::endl;
			Node_pointer	created_node = NULL;

			_root = insert(_root, val, &created_node);	// _root is not useful anymore, it will be deleted in future version
			_cardinal->parent = _root;

			if (!_cardinal->left)
				_cardinal->left = created_node;			// ! ALERT
			else if (val.first < _cardinal->left->content->first)
				_cardinal->left = created_node;

			if (!_cardinal->right)
				_cardinal->right = created_node;
			else if (val.first > _cardinal->right->content->first)
				_cardinal->right = created_node;
			return (_root);
		}

	protected:
		// ? (2) using a specific node
		Node_pointer	insert (Node_pointer node, const_reference val, Node_pointer *created_node)
		{
			if(node == NULL)
			{
				node = _node_allocator.allocate(1);
				// ? should create a insert function in Node
				node->content = _type_allocator.allocate(1);
				_type_allocator.construct(node->content, val);
				node->left = NULL;
				node->right = NULL;
				node->parent = NULL;
				*created_node = node;
				// std::cout << "found node : " << (void *)*created_node << std::endl;
			}
			else if (val.first == node->content->first)					// ! comparisons should be done using map's Comp
			{
				node->content->second = val.second;
				*created_node = node;
			}
			else if(val.first < node->content->first)					// ! comparisons should be done using map's Comp
			{
				node->left = insert(node->left, val, created_node);		
				node->left->parent = node;
			}
			else
			{
				node->right = insert(node->right, val, created_node);
				node->right->parent = node;
			}
			
			return (balance(node));
		}

	public:
		// ? (1) default: search from root
		Node_pointer	search (const Key key) const
		{
			return (search(_root, key));
		}

		// ? (2) search from a given node
		Node_pointer	search (Node_pointer node, const Key key) const
		{
			Node_pointer	res = NULL;

			if (node == NULL)
				return (NULL);
			else if (node->content->first == key)
				return (node);

			if (key < node->content->first)
				res = search(node->left, key);
			else if (key > node->content->first)
				res = search(node->right, key);
			return (res);
		}

		Node_pointer	base ()	const { return (_root);	}

		// !  DEBUG

		void			print_bst() const
		{
			print_bst(_root, 0);
			std::cout << "_cardinal [" ;
			if (_cardinal->left)
				std::cout << _cardinal->left->content->second ;
			else
				std::cout << " ";

			if (_cardinal->parent)
				std::cout << _cardinal->parent->content->second ;
			else
				std::cout << " ";
			
			if (_cardinal->right)
				std::cout << _cardinal->right->content->second ;
			else
				std::cout << " ";

			std::cout << "]" << std::endl<< std::endl;

		}

		void			print_bst(Node_pointer current, int space = 0) const
		{
			if (current)
			{
				space += 11;
				print_bst(current->right, space);

				std::cout << std::endl;
				std::cout << std::string(space, ' ');

				std::cout << "( " << current->content->first << " : " << current->content->second  << " )" << std::endl;

				print_bst(current->left, space);
			}
		}

		// ? (1) default: public
		void			display () const
		{
			if (_root)
			{
				// this->display(_root);
				// std::cout << std::endl;
				this->print_bst();
			}
		}
		
		// ? (2) protected
	protected:
		void			display (Node_pointer node) const
		{
			size_type	len = get_last_floor(node);

			if (node)
			{
				if (node->left)
					display(node->left);
				std::cout << std::string( ((len * 6) / 2), ' ' );
				std::cout << node->content->first << node->content->second;
				std::cout << std::string( ((len * 6) / 2), ' ' );
				if (node->right)
					display(node->right);
			}
			else
				std::cout << std::string( len * 6 + 6, ' ' );
		}

		// * Variables ________________________________________________________

	protected:
		Node_pointer	_root;
		Node_pointer	_cardinal;			// ? parent will be root, left will be first node, last will be last node
		Type_Allocator	_type_allocator;
		Node_Allocator	_node_allocator;
		
	}; // * BinarySearchTree __________________________________________________

	// ? DEBUG

	std::ostream&	operator<<(std::ostream & o, ft::pair<int, std::string> & pr)
	{
		o << pr.first << pr.second ;
		return (o);
	}

	template< class Key, class T, class Type_Allocator = std::allocator< T > >
	std::ostream&	operator<<(std::ostream & o, ft::BST_Node<Key, T, Type_Allocator> & bn)
	{
		if (bn->left)
			o << ", ";
		else
			o << "  ";
		o << bn->content->first;
		if (bn->right)
			o << " .";
		else
			o << "  ";
		return (o);
	}

	template< class Key, class T, class Type_Allocator = std::allocator< T > >
	std::ostream&	operator<<(std::ostream & o, ft::BST_Node<Key, T, Type_Allocator> * bn)
	{
		o << ", " << bn->content->first << " .";
		return (o);
	}

}

#endif
