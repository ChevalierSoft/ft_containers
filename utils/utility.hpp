/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:21:14 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/05 03:43:01 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

# include <string>
# include <iostream>
# include <sstream>
# include "is_integral.hpp"
# include "../iterator/iterator.h"
# include "enable_if.hpp"
# include "pair.hpp"

namespace ft
{
	template <typename T>
	std::string		to_string(T __n)
	{
		std::ostringstream oss;

		oss << __n;
		return (oss.str());
	}

	// ? http://www.cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (
			InputIterator1 first1,
			InputIterator1 last1,
			InputIterator2 first2,
			InputIterator2 last2,
			typename ft::enable_if< ! ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL,
			typename ft::enable_if< ! ft::is_integral<InputIterator2>::value, InputIterator2>::type* = NULL
		)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return (false);
			else if (*first1<*first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (
			InputIterator1 first1,
			InputIterator1 last1,
			InputIterator2 first2,
			InputIterator2 last2,
			Compare comp,
			typename ft::enable_if< ! ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL,
			typename ft::enable_if< ! ft::is_integral<InputIterator2>::value, InputIterator2>::type* = NULL
		)
	{
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
 	bool equal (
			InputIterator1 first1,
			InputIterator1 last1,
			InputIterator2 first2,
			typename ft::enable_if< ! ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL,
			typename ft::enable_if< ! ft::is_integral<InputIterator2>::value, InputIterator2>::type* = NULL
		)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (
			InputIterator1 first1,
			InputIterator1 last1,
			InputIterator2 first2,
			BinaryPredicate pred,
			typename ft::enable_if< ! ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL,
			typename ft::enable_if< ! ft::is_integral<InputIterator2>::value, InputIterator2>::type* = NULL
		)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type	distance (
			InputIterator first,
			InputIterator last,
			typename ft::enable_if< ! ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL
		)
	{
		typename iterator_traits<InputIterator>::difference_type	d;

		d = 0;
		for (InputIterator start = first; start != last; ++start)
			++d;
		return (d);
	}

	template<class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

}

#endif