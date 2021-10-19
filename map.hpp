/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:23 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/20 00:58:05 by dait-atm         ###   ########.fr       */
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
	class map /// * ___________________________________________________________
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

		/// * Constructors & Destructors ______________________________________

		map(void);
		// map(/* args */);
		~map(void);

		// Copy constructor
		map(const map & copy);

		// Operation overload =
		map &	operator=(const map &	copy);
		
		/// * Variables __________________________________________________________

	}; /// * map ______________________________________________________________
}

#endif