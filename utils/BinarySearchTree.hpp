/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:44:33 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/22 09:24:22 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

#include <functional>										// std::less
#include <memory>											// std::allocator
#include "BST_Node.hpp"
#include "../iterator/BST_bidirectional_iterator.hpp"

namespace ft
{
	template<	class Key,
				class T,
				class Compare = std::less<Key>,
				class Node_Allocator = std::allocator< ft::pair<Key, T> >
			>
	class BinarySearchTree // * ________________________________________________ BinarySearchTree
	{
	public:
		typedef ft::pair<Key, T>							value_type;
		typedef	T											data_type;
		typedef  ft::BST_Node<Key, T>						Node;
		typedef Compare										type_compare;
		typedef typename std::ptrdiff_t						difference_type;
		typedef size_t										size_type;
		typedef	value_type&									reference;
		typedef	const value_type&							const_reference;
		typedef T*											pointer;
		typedef const T*									const_pointer;
		typedef Node*										Node_pointer;
		typedef Node_pointer&								Node_const_pointer;
	
		typedef ft::BST_bidirectional_iterator<Node>		iterator;
		typedef ft::BST_const_bidirectional_iterator<Node>	const_iterator;

		// * Constructors & Destructors ________________________________________
	public:
		BinarySearchTree ()
			:	_root(NULL),
				_comp(Compare()),
				_node_allocator(Node_Allocator())
		{
			_cardinal = _node_allocator.allocate(1);
			_cardinal->parent = _cardinal;
			_cardinal->left = _cardinal;
			_cardinal->right = _cardinal;
		}

		BinarySearchTree (
							const_reference val,
							Compare cmp = Compare(),
							Node_Allocator na = Node_Allocator()
						) :		_comp(cmp),
								_node_allocator(na)
		{
			_root = _node_allocator.allocate(1);
			_node_allocator.construct(_root, Node(val));
			_root->content->v = val;
			_cardinal = _node_allocator.allocate(1);
			_cardinal->parent = _root;
			_cardinal->left = _root;
			_cardinal->right = _root;
		}

		BinarySearchTree (const BinarySearchTree &copy)
		: _root(NULL), _comp(copy._comp), _node_allocator(copy._node_allocator)
		{
			*this = copy;
		}

		~BinarySearchTree (void)
		{
			clear(_root);
			_node_allocator.deallocate(_cardinal, 1);
		}

		BinarySearchTree&	operator= (const BinarySearchTree &rhs)
		{
			if (this != &rhs)
			{
				this->clear();
				_comp = rhs._comp;
				_node_allocator = rhs._node_allocator;
				BinarySearchTree::iterator it = iterator(rhs._cardinal->left, rhs._cardinal);
				BinarySearchTree::iterator et = iterator(rhs._cardinal, rhs._cardinal, 1);
				for (; it != et; ++it)
					this->insert(*et);
			}
			return (*this);
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

		//     ,1.              ,2.
		//   ,2.	becomes   ,1. ,3.
		// ,3.
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
			tmp->parent = node->parent;
			node->parent = tmp;
			update(node);
			return (tmp);
		}

		// ,1.                  ,2.
		//   ,2.	becomes   ,1. ,3.
		//     ,3.
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

			if (node->right && node->right != _cardinal)
				node->right->parent = node;
			if (node->left && node->left != _cardinal)
				node->left->parent = node;

			// node is already balanced
			return (node);
		}

		// Update a node's height and balance factor.
		void			update (Node_pointer node)
		{
			int left_depth = -1;
			int right_depth = -1;

			if (!node || node == _cardinal)
				return ;

			if (node->left && node->left != _cardinal)
			{
				left_depth = node->left->height;
				node->left->parent = node;				// updating parent link
			}
			if (node->right && node->right != _cardinal)
			{
				right_depth = node->right->height;
				node->right->parent = node;				// updating parent link
			}

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
				_node_allocator.destroy(node);
				_node_allocator.deallocate(node, 1);
			}
		}
	public:
		// ? (1) default: public
		bool			remove (const Key key)
		{
			bool	found = false;

			// if key is from the lowest node
			if ( _cardinal->left != _cardinal &&
				(!_comp(key, _cardinal->left->content.first) &&
				!_comp(_cardinal->left->content.first, key)) )
			{
				// if the lowest node has a right leaf
				if (_cardinal->left->right != NULL && _cardinal->left->right != _cardinal)
					_cardinal->left = find_min(_cardinal->left->right);
				// if the lowest node has a parent _cardinal->left will point on it
				else if (_cardinal->left->parent)
					_cardinal->left = _cardinal->left->parent;
				// default
				else
					_cardinal->left = _cardinal;
			}

			else if (_cardinal->right != _cardinal &&
				(!_comp(key, _cardinal->right->content.first) &&
				!_comp(_cardinal->right->content.first, key)) )
			{
				if (_cardinal->right->left != NULL && _cardinal->right->left != _cardinal)
					_cardinal->right = find_max(_cardinal->right->left);
				else if (_cardinal->right->parent)
					_cardinal->right = _cardinal->right->parent;
				else
					_cardinal->right = _cardinal;
			}

			_root = remove(_root, key, &found);
			_cardinal->parent = _root;

			if (_root == NULL || _root == _cardinal)
			{
				_cardinal->left = _cardinal;
				_cardinal->right = _cardinal;
			}
			else
			{
				_cardinal->left->left = _cardinal;
				_cardinal->right->right = _cardinal;
			}

			return (found);
		}

	private:
		// ? (2) remove a specific 'node' identified by key
		Node_pointer	remove (Node_pointer node, const Key key, bool *found)
		{
			Node_pointer	successor;
			Node_pointer	successor_parent;

			if (!node || node == _cardinal)
				return (NULL);
			// search for the key in the tree
			if (_comp(key, node->content.first))
			{
				node->left = this->remove(node->left, key, found);
				if (node->left && node->left != _cardinal)
					node->left->parent = node;
			}
			else if (_comp(node->content.first, key))
			{
				node->right = this->remove(node->right, key, found);
				if (node->right && node->right != _cardinal)
					node->right->parent = node;
			}
			// found the node with the same key
			else
			{
				*found = true;
				// the node have no branch at all
				if ((!node->left || node->left == _cardinal)
					&& (!node->right || node->right == _cardinal))
				{
					successor = NULL;
					if (node->left == _cardinal)
						successor = _cardinal;
					else if (node->right == _cardinal)
						successor = _cardinal;
					_node_allocator.destroy(node);
					_node_allocator.deallocate(node, 1);
					return (successor);
				}
				// the node have only one branch
				else if ((!node->right || node->right == _cardinal)
						^ (!node->left || node->left == _cardinal))
				{
					// successor points on the only branch
					successor = (node->left && node->left != _cardinal) ? node->left : node->right;
					// update parent
					if (successor)
						successor->parent = node->parent;
					// delete the node
					_node_allocator.destroy(node);
					_node_allocator.deallocate(node, 1);
					return (successor);
				}
				// the node have both left and right branches
				else
				{
					// if the left branch is the biggest one: pick the node
					// that is just before in term of content (not the position)
					// and replace the actual node with it, then balance
					if (node->left->height > node->right->height)
					{
						
						successor = find_max(node->left);
						// check if the successor is a leaf of node
						if (remove_if_successor_is_close(node, successor))
							return (successor);
						// (1) relink everything successor's previous parent
						successor_parent = successor->parent;
						successor_parent->right = successor->left;
						if (successor_parent->right && successor_parent->right != _cardinal)
							successor_parent->right->parent = successor_parent;
					}
					// the same that the previous but with the node just after
					else
					{
						successor = find_min(node->right);
						if (remove_if_successor_is_close(node, successor))
							return (successor);
						// (1) relink everything successor's previous parent
						successor_parent = successor->parent;
						successor_parent->left = successor->right;
						if (successor_parent->left && successor_parent->left != _cardinal)
							successor_parent->left->parent = successor_parent;
					}

					// (2) relink successor at node position
					successor->right = node->right;
					if (successor->right && successor->right != _cardinal)
					{
						successor->right->parent = successor;
					}
					successor->left = node->left;
					if (successor->left != NULL && successor->left != _cardinal)
					{
						successor->left->parent = successor;
					}
					// (3) delete node
					_node_allocator.destroy(node);
					_node_allocator.deallocate(node, 1);

					// (4) recurcively update + balance from the old position of
					// successor to it's new one
					while (successor_parent->parent != successor)
					{
						update(successor_parent);
						this->balance(successor_parent);
						successor_parent = successor_parent->parent;
					}

					return (successor);
				}
			}

			update(node);

			return (this->balance(node));
		}

	// ? this is used to remove a node that is just before two leaves
	bool				remove_if_successor_is_close(Node_pointer &node, Node_pointer &successor)
	{
		if (successor == node->right)
		{
			successor->parent = node->parent;
			successor->left = node->left;
			if (node->left != NULL && node->left != _cardinal)
				node->left->parent = successor;
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
			return (true);
		}
		else if (successor == node->left)
		{
			successor->parent = node->parent;
			successor->right = node->right;
			if (node->right != NULL && node->right != _cardinal)
				node->right->parent = successor;
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
			return (true);
		}
		return (false);
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
			while (node->right != NULL && node->right != _cardinal)
				node = node->right;
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
			else if (_comp(val.first, _cardinal->left->content.first))
			{
				_cardinal->left = created_node;
				created_node->left = _cardinal;
			}

			if (_cardinal->right == _cardinal)
			{
				_cardinal->right = find_max(_cardinal->parent);
				_cardinal->right->right = _cardinal;
			}											
			else if (_comp(_cardinal->right->content.first, val.first))
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
				node = create_node(val);
				*created_node = node;
			}
			else if (node == _cardinal)
				return (_cardinal);
			// ? Key already exists
			else if (!_comp(val.first, node->content.first) &&
						!_comp(node->content.first, val.first))
			{
				*created_node = node;
				*already_exists = true;
			}
			else if (_comp(val.first, node->content.first))
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
			_node_allocator.construct(node, Node(val));
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
			else if (!_comp(node->content.first, key) && !_comp(key, node->content.first))
				return (node);
			if (_comp(key, node->content.first))
				res = search(node->left, key);
			else if (_comp(node->content.first, key))
				res = search(node->right, key);
			return (res);
		}

		Node_pointer	base ()	const 			{ return (_root);			}

		// * Getters ___________________________________________________________

	public:
		Node_pointer	get_cardinal() const	{ return (_cardinal);		}
		Node_pointer	get_root() const		{ return (_root);			}
		Compare			get_comp() const		{ return (_comp);			}
		Node_Allocator	get_allocator() const	{ return (_node_allocator);	}

		// * Setters ___________________________________________________________
	public:
		void			set_cardinal(const Node_pointer& rhs)		{ _cardinal = rhs;			}
		void			set_root(const Node_pointer& rhs)			{ _root = rhs;				}

		// * Variables _________________________________________________________

	public:
		Node_pointer	_root;
		Node_pointer	_cardinal;
	protected:
		Compare			_comp;
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
		o << bn.content.first;
		if (bn.right)
			o << " .";
		else
			o << "  ";
		return (o);
	}

	template<class Key, class T>
	std::ostream&	operator<<(std::ostream & o, ft::BST_Node<Key, T> * bn)
	{
		o << ", " << bn->content.first << " .";
		return (o);
	}

}

#endif
