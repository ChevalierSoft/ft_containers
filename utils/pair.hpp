/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 05:50:36 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/19 22:31:50 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <utility>

namespace ft // * ______________________________________________________________
{
	template< class T1, class T2 >
	struct pair
	{
		typedef	T1		first_type;
		typedef	T2		second_type;

		// * Constructor / Destrtuctor ___________________________________________

		// ? (1) default constructor
		pair ()	: first(T1()), second(T2()) {}

		// ? (2) copy / move constructor (and implicit conversion)
		template< class U, class V >
		pair (const pair< U, V > & pr) : first(pr.first), second(pr.second) {}

		// ? (3) initialization constructor
		pair (const first_type & a, const second_type & b) : first(a), second(b) {}

		virtual ~pair() {}

		// * Other Member functions ____________________________________________

		pair &		operator= (const pair & pr)
		{
			if (this != &pr)
			{
				first = pr.first;
				second = pr.second;
			}
			
			return (*this);
		}

		// bool operator==(const pair<T1 , T2> & lhs, const pair<T1, T2> & rhs);
		// bool operator!=(const pair<T1 , T2> & lhs, const pair<T1, T2> & rhs);
		// bool operator< (const pair<T1 , T2> & lhs, const pair<T1, T2> & rhs);
		// bool operator<=(const pair<T1 , T2> & lhs, const pair<T1, T2> & rhs);
		// bool operator> (const pair<T1 , T2> & lhs, const pair<T1, T2> & rhs);
		// bool operator>=(const pair<T1 , T2> & lhs, const pair<T1, T2> & rhs);

		// * Variables _________________________________________________________

		first_type	first;
		second_type	second;

	};

	template <class T1, class T2>
	bool				operator==(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool				operator!=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool				operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));	// making sure it work in both way
	}

	template <class T1, class T2>
	bool				operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);		// avoiding 2 function calls
	}

	template <class T1, class T2>
	bool				operator> (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool				operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2>		make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

} // * namespace ft ____________________________________________________________
