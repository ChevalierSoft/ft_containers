/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:21:14 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/14 16:14:00 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <sstream>
# include "is_integral.hpp"
# include "../iterator/iterator.h"

namespace ft
{
	template <typename T>
	std::string		to_string(T __n)
	{
		std::ostringstream oss;

		oss << __n;
		return (oss.str());
	}

	// http://www.cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type	d;

		d = 0;
		for (InputIterator start = first; start != last; ++start)
			++d;
		return (d);
	}

}

#endif