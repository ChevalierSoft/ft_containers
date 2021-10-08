#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	// https://www.cplusplus.com/reference/type_traits/is_integral/
	
	template <typename T, T __v>
	struct integral_constant	//______________________________
	{
		static T							value = __v;
		typedef T							value_type;
		typedef integral_constant<T, __v>	type;
		operator value_type() const 		{ return value; }
	};	//______________________________________________________

	template<typename T, T __v>
		T integral_constant<T, __v>::value;

	/// The type used as a compile-time boolean with true value.
	typedef integral_constant<bool, true>	true_type;

	/// The type used as a compile-time boolean with false value.
	typedef integral_constant<bool, false>	false_type;

	template<bool __v>
		using __bool_constant = integral_constant<bool, __v>;

	
	
	template <class T>
	struct is_integral : public ft::false_type {};
}

#endif