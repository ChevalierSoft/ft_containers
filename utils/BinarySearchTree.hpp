/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:44:33 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/24 03:45:14 by dait-atm         ###   ########.fr       */
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
	class BinarySearchTree // * ________________________________________________ BinarySearchTree
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
	
		typedef ft::BST_bidirectional_iterator<Node, Compare>	iterator;

		// * Constructors & Destructors ________________________________________
	public:
		BinarySearchTree ()
			:	_root(NULL),
				_comp(Compare()),
				_type_allocator(Type_Allocator()),
				_node_allocator(Node_Allocator())
		{
			_cardinal = _node_allocator.allocate(1);
			_cardinal->content = NULL;
			// _cardinal->content = new ft::Node_content<value_type>;
			// _cardinal->content->v = value_type();
			_cardinal->parent = _cardinal;
			_cardinal->left = _cardinal;
			_cardinal->right = _cardinal;
		}

		BinarySearchTree (
							const_reference val,
							Compare cmp = Compare(),
							Type_Allocator ta = Type_Allocator(),
							Node_Allocator na = Node_Allocator()
						) :		_comp(cmp),
								_type_allocator(ta),
								_node_allocator(na)
		{
			_root = _node_allocator.allocate(1);
			_node_allocator.construct(_root, val);
			_root->content->v = val;
			_cardinal = _node_allocator.allocate(1);
			_cardinal->content = NULL;
			_cardinal->parent = _root;
			_cardinal->left = _root;
			_cardinal->right = _root;
		}

		// ! Need to add copy and =
		
		~BinarySearchTree (void)
		{
			_node_allocator.deallocate(_cardinal, 1);
			clear(_root);
		}

		// * Modifiers _________________________________________________________

	protected:
		size_type		get_last_floor (Node_pointer node) const
		{
			int l = -1;
			int r = -1;

			if (!node || node == _cardinal)
				return (0);

			l = get_last_floor(node->left);
			r = get_last_floor(node->right);

			return (l > r) ? l + 1 : r + 1;
		}

		long			get_balance (Node_pointer node)
		{
			if (node)
				return (node->bf);
			return (0);
		}

		// * Rotations _________________________________________________________

		Node_pointer	right_rotation(Node_pointer node)
		{
			Node_pointer	tmp;

			if (!node)
				return (node);
			tmp = node->left;
			if (!tmp)
				return (node);
			node->left = tmp->right;
			tmp->right = node;
			// update parent
			tmp->parent = node->parent;
			node->parent = tmp;

			update(node);

			return (tmp);
		}

		Node_pointer	left_rotation(Node_pointer node)
		{
			Node_pointer	tmp;

			if (!node)
				return (node);
			tmp = node->right;
			if (!tmp)
				return (node);
			node->right = tmp->left;
			tmp->left = node;
			// update parent
			tmp->parent = node->parent;
			node->parent = tmp;
			
			update(node);

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
			long	b = 0;

			if (!node || node == _cardinal)
				return (node);

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

		 // Update a node's height and balance factor.
		void			update (Node_pointer node)
		{
			if (!node || node == _cardinal)
				return ;
			
			int left_depth = (node->left == NULL || node->left == _cardinal) ? -1 : node->left->height;
			int right_depth = (node->right == NULL || node->right == _cardinal) ? -1 : node->right->height;

			node->height = 1 + ((left_depth > right_depth) ? left_depth : right_depth);

			// Update balance factor.
			node->bf = right_depth - left_depth;
		}


	public:
		// ? (1) default: public
		void			clear ()
		{
			clear(_root);
			_root = NULL;
			_cardinal->parent = _root;
			_cardinal->left = _cardinal;
			_cardinal->right = _cardinal;
		}

	private:
		// ? (2) clear from a specific node
		void			clear (Node_pointer node)
		{
			if(node != NULL && node != _cardinal)
			{
				clear(node->left);
				clear(node->right);
				_node_allocator.destroy(node);						// need to test first
				_node_allocator.deallocate(node, 1);
				// node = NULL;	// * it may be faster without
			}
		}
	public:
		// ? (1) default: public
		bool			remove (const Key key)
		{
			bool	found = false;

			// this should never happen
			if (!_cardinal->left || !_cardinal->right)
				std::cout << "ALERT" << std::endl;

			// if key is from the lowest node
			if (_cardinal->left != _cardinal &&
				(!_comp(key, _cardinal->left->content->v.first) && !_comp(_cardinal->left->content->v.first, key)) )	// ! using _comp
				//key == _cardinal->left->content->v.first)
			{
				std::cout << "key is from the lowest node : " << key << " " << _cardinal->left->content->v.first << std::endl;
				// if the lowest node has a right leaf
				if (_cardinal->left->right != NULL && _cardinal->left->right != _cardinal)
					_cardinal->left = _cardinal->left->right;
				// if the lowest node has a parent _cardinal->left will point on it
				else if (_cardinal->left->parent)
					_cardinal->left = _cardinal->left->parent;
				// default
				else
					_cardinal->left = _cardinal;
			}

			else if (_cardinal->right != _cardinal &&
				(!_comp(key, _cardinal->right->content->v.first) && !_comp(_cardinal->right->content->v.first, key)) )	// ! using _comp
			{
				if (_cardinal->right->left != NULL && _cardinal->right->left != _cardinal)
					_cardinal->right = _cardinal->right->left;
				else if (_cardinal->right->parent)
					_cardinal->right = _cardinal->right->parent;
				else
					_cardinal->right = _cardinal;
			}

			_root = remove(_root, key, &found);
			_cardinal->parent = _root;

			return (found);
		}

	private:
		// ? (2) remove a specific 'node' identified by key
		Node_pointer	remove (Node_pointer node, const Key key, bool *found)
		{
			Node_pointer	successor;
			Node_pointer	ret;

			if (!node || node == _cardinal)
				return (NULL);

			std::cout << "key : " << key << std::endl;
				
			// search for the key in the tree
			 if (key < node->content->v.first)									// ! using _comp
			//if (_comp(key, node->content->v.first))
			{
				node->left = this->remove(node->left, key, found);
			}
			 else if (key > node->content->v.first)
			//else if (_comp(node->content->v.first, key))							// ! using _comp
			{
				node->right = this->remove(node->right, key, found);
			}
			// got the key
			else
			{
				__DEB("found");
				*found = true;
				if ((!node->left || node->left == _cardinal) && (!node->right || node->right == _cardinal))
				{
					_node_allocator.destroy(node);
					_node_allocator.deallocate(node, 1);
					return (NULL);
				}
				// the node have no right branch
				else if (!node->right || node->right == _cardinal)
				{
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
				// the node have no left branch either
				else if (!node->left || node->left == _cardinal)
				{
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

				std::cout << "apparently this node has 2 branches" << std::endl;

				// replace node with the biggest sub tree
				if (node->left->height > node->right->height)
				{
					// __DEB("(balance left)")
					successor = find_max(node->left);
					node->content->v = successor->content->v;
					node->left = remove(node->left, successor->content->v.first, found);
				}
				else
				{
					// __DEB("(other balances)")
					successor = find_min(node->right);
					//*node->content = *successor->content;
					node->content->v = successor->content->v;
					node->right = remove(node->right, successor->content->v.first, found);
				}

			}
			
			update(node);

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
			while (node->left != NULL && node->left != _cardinal)
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
			while (node->left != NULL && node->left != _cardinal)
				node = node->left;
			return (node);
		}

		// ? (1) default: insert from _root
		ft::pair<iterator, bool>	insert (const_reference val)
		{
			Node_pointer	created_node = NULL;
			bool			already_exists = false;

			_root = insert(_root, val, &created_node, &already_exists);
			_cardinal->parent = _root;
			_root->parent = _cardinal;

			if (already_exists == true)
				return ( ft::make_pair<iterator, bool>( iterator(created_node, _cardinal), false ) );

			if (_cardinal->left == _cardinal)
			{
				_cardinal->left = find_min(_cardinal->parent);
				_cardinal->left->left = _cardinal;
			}
			else if (_comp(val.first, _cardinal->left->content->v.first))
			{
				_cardinal->left = created_node;
				created_node->left = _cardinal;
			}

			if (_cardinal->right == _cardinal)
			{
				_cardinal->right = find_max(_cardinal->parent);
				_cardinal->right->right = _cardinal;
			}											
			else if (_comp(_cardinal->right->content->v.first, val.first))
			{
				_cardinal->right = created_node;
				created_node->right = _cardinal;
			}

			return (ft::make_pair<iterator, bool>(iterator(created_node, _cardinal), true));
		}

	protected:
		// ? (2) using a specific node
		Node_pointer	insert (
									Node_pointer node,
									const_reference val,
									Node_pointer *created_node,
									bool *already_exists
								)
		{
			if (node == NULL)
			{
				node = _node_allocator.allocate(1);
				node->insert(val);
				*created_node = node;
			}
			else if (node == _cardinal)
				return (_cardinal);
			else if (!_comp(val.first, node->content->v.first) && 	// ? Key already exists
						!_comp(node->content->v.first, val.first))
			{
				// node->content->v.second = val.second;
				*created_node = node;
				*already_exists = true;
			}
			else if (_comp(val.first, node->content->v.first))
			{
				node->left = insert(node->left, val, created_node, already_exists);
				if (node->left == _cardinal)
				{
					node->left = create_node(val);
					*created_node = node->left;
				}
				node->left->parent = node;
			}
			else
			{
				node->right = insert(node->right, val, created_node, already_exists);
				if (node->right == _cardinal)
				{
					node->right = create_node(val);
					*created_node = node->right;
				}
				node->right->parent = node;
			}

			update(node);

			return (balance(node));
		}

	private:
		Node_pointer	create_node(const value_type & val)
		{
			Node_pointer node = _node_allocator.allocate(1);
			node->insert(val);
			return (node);
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

			if (node == NULL || node == _cardinal)
				return (NULL);
			else if (!_comp(node->content->v.first, key) && !_comp(key, node->content->v.first))	// ! using _comp
				return (node);

			if (_comp(key, node->content->v.first))								// ! using _comp
				res = search(node->left, key);
			else if (_comp(node->content->v.first, key))							// ! using _comp
				res = search(node->right, key);
			return (res);
		}

		Node_pointer	base ()	const { return (_root);	}

		// !  DEBUG

		void			print_bst() const
		{
			if (!_root || _root == _cardinal)
				return ;
			print_bst(_root, 0);
			std::cout << "_cardinal [" ;
			if (_cardinal->left && _cardinal->left != _cardinal)
				std::cout << _cardinal->left->content->v.second ;
			else
				std::cout << " ";

			if (_cardinal->parent && _cardinal->parent != _cardinal)
				std::cout << _cardinal->parent->content->v.second ;
			else
				std::cout << " ";
			
			if (_cardinal->right && _cardinal->right != _cardinal)
				std::cout << _cardinal->right->content->v.second ;
			else
				std::cout << " ";

			std::cout << "]" << std::endl<< std::endl;

		}

		void			print_bst(Node_pointer current, int space = 0) const
		{
			if (current && current != _cardinal)
			{
				space += 11;
				print_bst(current->right, space);

				std::cout << std::endl;
				std::cout << std::string(space, ' ');

				std::cout << "( " << current->content->v.first << " : " << current->content->v.second  << " )" << std::endl;

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

			if (node && node != _cardinal)
			{
				if (node->left)
					display(node->left);
				std::cout << std::string( ((len * 6) / 2), ' ' );
				std::cout << node->content->v.first << node->content->v.second;
				std::cout << std::string( ((len * 6) / 2), ' ' );
				if (node->right)
					display(node->right);
			}
			else
				std::cout << std::string( len * 6 + 6, ' ' );
		}

		// * Variables _________________________________________________________

	public:
		Node_pointer	_cardinal;
	protected:
		Node_pointer	_root;
		Compare			_comp;
		Type_Allocator	_type_allocator;
		Node_Allocator	_node_allocator;
		
	}; // * BinarySearchTree ___________________________________________________

	// ? DEBUG

	std::ostream&	operator<<(std::ostream & o, ft::pair<int, std::string> & pr)
	{
		o << pr.first << pr.second ;
		return (o);
	}

	template<class Key, class T>
	std::ostream&	operator<<(std::ostream & o, ft::BST_Node<Key, T> & bn)
	{
		if (bn.left)
			o << ", ";
		else
			o << "  ";
		o << bn.content->v.first;
		if (bn.right)
			o << " .";
		else
			o << "  ";
		return (o);
	}

	template<class Key, class T>
	std::ostream&	operator<<(std::ostream & o, ft::BST_Node<Key, T> * bn)
	{
		o << ", " << bn->content->v.first << " .";
		return (o);
	}

}

#endif
