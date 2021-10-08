/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:22:04 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/08 13:33:43 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <typename T, T __v>
	struct integral_constant	// *______________________________________________________
	{
		static const T						value = __v;
		typedef T							value_type;
		typedef integral_constant<T, __v>	type;
		operator const value_type() const 	{ return value; }
	};
	
	template<typename T, T __v>
		const T integral_constant<T, __v>::value;
	/// The type used as a compile-time boolean with true value.
	typedef integral_constant<bool, true>	true_type;
	/// The type used as a compile-time boolean with false value.
	typedef integral_constant<bool, false>	false_type;
	
	template<bool __v>
		using __bool_constant = integral_constant<bool, __v>;
	// * integral_constant ______________________________________________________________
	
	// ? https://www.cplusplus.com/reference/type_traits/is_integral/
	template <class T>
	struct is_integral : public ft::false_type {};
}

#endif