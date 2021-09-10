#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <sstream>

namespace ft
{

	template <typename T>
	std::string		to_string(T __n)
	{
		std::ostringstream oss;

		oss << __n;
		return (oss.str());
	}

}

#endif