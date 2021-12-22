/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/22 09:34:35 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <string>
#include <assert.h>
#include <time.h>		// rand()

#ifdef ORIGINAL
	namespace ft = std;
#else
	# include "vector.hpp"
	# include "map.hpp"
	# include "stack.hpp"
#endif

#include "./utils/color.h"
// #include "./utils/ft_print_memory.h"

#define ENDL		std::cout<<std::endl;
#define __GRN		std::cout<<GRN;
#define __RST		std::cout<<RST;

// _____________________________________________________________________________
class	menfou
{
private:
	static int	_nb;
public:
	int 		a;
	int			b;
	char		c;
	size_t		d;

	explicit menfou() : a(1), b(42), c('A' + _nb), d(-1) { ++_nb; }
	explicit menfou(char n_c) : a(1), b(42), c(n_c), d(-1) {}
	// ~menfou() { std::cout << "~menfou" << std::endl;	}
	~menfou(){}
};
int		menfou::_nb = 0;
std::ostream &	operator<< (std::ostream & o, const menfou & m)
{
	o << "obj : " << m.c << std::endl;
	return o;
}

template <typename T>
void	display(T v)
{
	for (typename T::iterator iv = v.begin(); iv != v.end(); ++iv)
		std::cout << *iv;
	std::cout << std::endl;
}
template <typename T>
void	display(T v, char c)
{
	for (typename T::iterator iv = v.begin(); iv != v.end(); ++iv)
		std::cout << *iv << c;
	std::cout << std::endl;
}

// ? ___________________________________________________________________________ ft::vector

// _____________________________________________________________________________
void	test_vector()
{
	ft::vector<int>				v;
	ft::vector<int>				w;
	ft::vector<char>			e;
	ft::vector<std::string>		st;
	std::string					strft;
	std::string					strstd;

	std::cout <<std::endl<<CYN<< "__________________ft::vector__________________" <<RST<< std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "push_back()" <<RST<< std::endl;

	v.push_back(0x4C);
	v.push_back(0x55);
	v.push_back(0x4C);
	v.push_back(0x5A);
	display(v, ' ');

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "contructor by copy" <<RST<< std::endl;
	{
		ft::vector<int>				ww(v);
		v.push_back(48);
		display(v, ' ');
		std::cout << std::endl;
		ft::vector<int>				c(ww);
		std::cout << "copied : " << c.size() << std::endl;
		v.pop_back();
	}

	std::cout <<std::endl<<CYN<< "contructor by range" <<RST<< std::endl;
	{
		ft::vector<menfou>	pif;
		pif.push_back(menfou('1'));
		pif.push_back(menfou('2'));
		pif.push_back(menfou('3'));
		pif.push_back(menfou('4'));
		pif.push_back(menfou('5'));

		ft::vector<menfou>	vrange(pif.begin() + 1, pif.end() - 1);
		display(vrange);
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator=" <<RST<< std::endl;
	{
		ft::vector<int>	ww(v);
		w.pop_back();
		ww = v;
		display(v, ' ');
		std::cout << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "pop_back()" <<RST<< std::endl;
	{
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		display(v, ' ');
		std::cout << "(nothing should be printed)" << std::endl;
		v.push_back(0x4C);
		v.push_back(0x55);
		v.push_back(0x4C);
		v.push_back(0x5A);
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator=" <<RST<< std::endl;
	{
		w = v;
		w.push_back('M');
		w.push_back('D');
		w.push_back('R');
		std::cout << std::endl << "mine             ";
		display(v, ' ');
		std::cout << std::endl <<GRN<< "should be        76 85 76 90 77 68 82"<<RST<< std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "empty()" <<RST<< std::endl;
	{
		std::cout << "e : " << e.empty() <<" (should be 1)"<< std::endl;
		e.push_back('v');
		std::cout << "e : " << e.empty() <<" (should be 0)"<< std::endl;
		e.pop_back();
		std::cout << "e : " << e.empty() <<" (should be 1)"<< std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "max_size()" <<RST<< std::endl;
	{
		std::vector<int>			maxv;
		std::vector<char>			maxc;
		std::vector<std::string>	maxs;
		std::vector<menfou>			mm;
		std::vector<short>			th;
		std::vector<long double>	ld;
		ft::vector<menfou>			mf;
		ft::vector<short>			sh;
		ft::vector<long double>		sd;

		std::cout << "char     : " << maxc.max_size()	<< "\tmine : " << e.max_size() << std::endl;
		std::cout << "short    : " << th.max_size()		<< "\tmine : " << sh.max_size() << std::endl;
		std::cout << "int      : " << maxv.max_size()	<< "\tmine : " << w.max_size() << std::endl;
		std::cout << "string   : " << maxs.max_size()	<< "\tmine : " << st.max_size() << std::endl;
		std::cout << "struct   : " << mm.max_size()		<< "\tmine : " << mf.max_size() << std::endl;
		std::cout << "l double : " << ld.max_size()		<< "\tmine : " << sd.max_size() << std::endl;
	}


	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "size()" <<RST<< std::endl;
	{
		std::cout << "v count : " << v.size() << std::endl;
		std::cout << "w count : " << w.size() << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "clear()" <<RST<< std::endl;
	{
		if (w.empty())
			std::cout << "empty" << std::endl;
		else
			std::cout << "full" << std::endl;
		w.clear();
		if (w.empty())
			std::cout << "empty" << std::endl;
		else
			std::cout << "full" << std::endl;
		std::cout << "size : " << w.size() << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "at()" <<RST<< std::endl;
	{
		const ft::vector<int> cc(v);

		try
		{
			int &qwe = v.at(16);
			std::cout << "v.at(16) : " << (char)qwe << std::endl;
		}
		catch(const std::exception& e) {	std::cout << e.what() << '\n';	}
		try
		{
			const int qwe = cc.at(1);
			std::cout << "cc.at(2) : " << (char)qwe << std::endl;
		}
		catch(const std::exception& e) {	std::cout << e.what() << '\n';	}
	}
	
	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "non member functions" <<RST<< std::endl;
	{
		v.clear();
		w.clear();
		v.push_back(0x4C); v.push_back(0x55); v.push_back(0x4C);
		w.push_back(0x4C); w.push_back(0x55); //w.push_back(0x4C);
		w = v;

		if (v == w)	std::cout << "== working"<< std::endl;
		else		std::cout<<RED<< "== NOT working" <<RST<<std::endl;
		if (v != w)	std::cout<<RED<< "!= NOT working" <<RST<<std::endl;
		else		std::cout << "!= working"<< std::endl;
		v.push_back('Z');
		if (v == w)	std::cout<<RED<< "== NOT working" <<RST<<std::endl;
		else		std::cout << "== working"<< std::endl;
		if (v != w)	std::cout << "!= working"<< std::endl;
		else		std::cout<<RED<< "!= NOT working" <<RST<<std::endl;

		if (w < v)	std::cout << "> working"<< std::endl;
		else		std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		if (v < w)	std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		else		std::cout << "> working"<< std::endl;

		if (v > w)	std::cout << "> working"<< std::endl;
		else		std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		if (w > v)	std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		else		std::cout << "> working"<< std::endl;

		if (w <= v)	std::cout << "<= working"<< std::endl;
		else		std::cout<<RED<< "<= NOT working" <<RST<<std::endl;
		if (v <= w)	std::cout<<RED<< "<= NOT working" <<RST<<std::endl;
		else		std::cout << "<= working"<< std::endl;
		if (v >= w)	std::cout << ">= working"<< std::endl;
		else		std::cout<<RED<< ">= NOT working" <<RST<<std::endl;
		if (w >= v)	std::cout<<RED<< ">= NOT working" <<RST<<std::endl;
		else		std::cout << ">= working"<< std::endl;

		v.pop_back();
		if (v <= w)	std::cout << "<= working"<< std::endl;
		else		std::cout<<RED<< "<= NOT working" <<RST<<std::endl;
		if (w >= v)	std::cout << ">= working"<< std::endl;
		else		std::cout<<RED<< ">= NOT working" <<RST<<std::endl;

	}
	
	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "memory" <<RST<< std::endl;
	{
		ft::vector<menfou> smf;

		menfou *mf = new menfou();
		smf.push_back(*mf);
		smf.pop_back();
		smf.clear();
		delete mf;					// without this line it should leak
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "front(), back() and data()" <<RST<< std::endl;
	{
		ft::vector<menfou> sfm;
		menfou *mf = new menfou();
		sfm.push_back(*mf);
		sfm.push_back(menfou());
		ft::vector<menfou>::reference rsfm = sfm.front();
		std::cout << rsfm.b << std::endl;
		rsfm = sfm.back();					// by copy to be sure
		std::cout << rsfm.b << std::endl;
		ft::vector<menfou>::const_reference crsfm = sfm.front();
		std::cout << crsfm.b << std::endl;
		ft::vector<menfou>::const_reference crsfmb = sfm.back();
		std::cout << crsfmb.b << std::endl;
		delete mf;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "reserve() without valgrind (remove comments)" <<RST<< std::endl;
	// {
	// 	ft::vector<menfou> rev;
	// 	try
	// 	{
	// 		rev.reserve(UINft::map<int, foo<int>>::value_type2_MAX);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// }
	// {
	// 	ft::vector<menfou> rev;
	// 	try
	// 	{
	// 		rev.reserve(UINT32_MAX);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout <<GRN<< e.what() <<RST<< '\n';
	// 	}
	// }

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator[]" <<RST<< std::endl;
	{
		ft::vector<menfou> ovh;
		for (int i = 0; i < 3; ++i)
			ovh.push_back(menfou('0' + i));
		std::cout << ovh[2] << ovh[0] << ovh[1];
		ft::vector<menfou>::const_reference crovh = ovh[0];
		std::cout << crovh;
		// std::cout << ovh[334] <<std::endl;	// should be a heap-buffer-overflow
	}

	std::cout <<std::endl<<CYN<< "is_integral : need to uncomment (not in c++98)" <<RST<< std::endl;
	{
		// std::cout << "char: \t"		<< ft::is_integral<char>::value		<< std::endl;
		// std::cout << "int: \t"		<< ft::is_integral<int>::value		<< std::endl;
		// std::cout << "float: \t"	<< ft::is_integral<float>::value	<< std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "insert()" <<RST<< std::endl;
	{
		ft::vector<menfou>	asd;
		ft::vector<menfou>	cpy(16, menfou('x'));

		asd.push_back(menfou('a'));
		asd.insert(asd.begin(), menfou('b'));
		asd.insert(asd.end(), menfou('c'));
		asd.insert(asd.end(), menfou('d'));
		asd.insert(asd.end() - 2, menfou('e'));
		asd.insert(asd.end(), 3, menfou('f'));
		asd.insert(asd.begin(), 2, menfou('g'));
		asd.insert(asd.begin() + 2, 2, menfou('h'));
		asd.insert(asd.end() - 3, 24, menfou('i'));

		// g g h h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f
		asd.insert(asd.end(), asd.begin(), asd.begin() + 5);
		// g g h h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b
		asd.insert(asd.begin() + 3, cpy.begin(), cpy.end());
		// g g h x x x x x x x x x x x x x x x x h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b
		asd.insert(asd.begin() + 3, asd.begin(), asd.end());
		// g g h g g h x x x x x x x x x x x x x x x x h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b x x x x x x x x x x x x x x x x h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b
		asd.insert(asd.begin() + 6, asd.rbegin(), asd.rend());

		strft = "";
		for (ft::vector<menfou>::const_iterator iasd = asd.begin();
				iasd != asd.end(); ++iasd)
			strft += iasd->c;

		std::cout << "size : " << asd.size() << std::endl;

		ft::vector<int> jkl;
		jkl.insert(jkl.begin(), 7, 7);
		std::cout << strft << std::endl;

	}

	{
		ft::vector<char>			v3(10, '1');

		v3.insert(v3.begin(), 2, 80);
		std::cout << "size : " << v3.size() << std::endl;
		std::cout << "capacity : " <<" "<<  v3.capacity() << std::endl;
		display(v3);

		v3.insert(v3.begin(), 20, 80);
		std::cout << "size : " << v3.size() << std::endl;
		std::cout << "capacity : " <<  v3.capacity() << std::endl;
		display(v3);
	}

	{
		ft::vector<int>  vec;
		vec.insert(vec.begin(), 5, 42);
		display(vec);
	}


	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "assign()" <<RST<< std::endl;
	{
		ft::vector<int> jkl;
		ft::vector<int> uio;

		uio.insert(jkl.begin(), 7, 3);	// enable_if is working
		
		jkl.assign(3, 9);				//
		display(jkl);

		// try {	jkl.assign(-3, 7);	}
		// catch(const std::exception& e){	std::cout << e.what() << '\n'; }
		
		jkl.assign(uio.begin(), uio.end());
		display(jkl);
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "erase()" <<RST<< std::endl;
	{
		// ? use vector's type in sizeof : https://stackoverflow.com/a/53259979
		ft::vector<int>	vv;
		// ft::vector<int>::iterator ivv;
		int rera;
		vv.push_back('L');
		vv.push_back('L');
		vv.push_back('U');
		vv.push_back('L');
		display(vv);
		vv.erase(vv.begin());
		display(vv);
		vv.erase(vv.end() - 1);
		display(vv);
		vv.push_back('V');
		vv.push_back('U');
		display(vv);
		vv.erase(vv.begin() + 2);
		vv.erase(vv.begin());
		display(vv);
		vv.insert(vv.begin() + 1, 'W');
		display(vv);
		vv.insert(vv.end(), vv.begin(), vv.end());
		display(vv);
		rera = vv.erase(vv.begin() + 1, vv.end() - 1) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		display(vv);
		rera = vv.erase(vv.end(), vv.end()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		display(vv);
		rera = vv.erase(vv.begin(), vv.begin()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		display(vv);
		rera = vv.erase(vv.begin(), vv.end()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		display(vv);
		ENDL
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "resize()" <<RST<< std::endl;
	{
		ft::vector<menfou> vres;
		vres.insert(vres.begin(), 6, menfou('r'));
		vres.resize(1);
		display(vres);
		// std::cout << "resize() needs to be compiled with -std=c++98 : "
		// vres.resize(5);				// ! needs to be compiled with -std=c++98
		// display(vres);
		vres.resize(9, menfou('x'));
		display(vres);
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "swap()" <<RST<< std::endl;
	{
		ft::vector<menfou> vmf1;
		ft::vector<menfou> vmf2;

		vmf1.insert(vmf1.begin(), 3, menfou('1'));
		vmf2.insert(vmf2.begin(), 5, menfou('2'));

		vmf1.swap(vmf2);

		display(vmf1);
		display(vmf2);
	}

}	//__________________________________________________________________________

// _____________________________________________________________________________
void	test_vector_iterator()
{
	ft::vector<char>							v;
	ft::vector<char>::const_reverse_iterator	cri;
	ft::vector<char>::reverse_iterator			ri;

	v.push_back('a'); v.push_back('b'); v.push_back('c'); v.push_back('d'); v.push_back('e');
	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "egualities with const_reverse_iterator and reverse_iterator" <<RST<< std::endl;
	{
		cri = v.rbegin();
		ri = v.rbegin();
		if (cri == ri)
			std::cout << "cri == ri" << std::endl;
		if (cri != ri)
			std::cout << "cri != ri" << std::endl;
		if (cri == cri)
			std::cout << "cri == cri" << std::endl;
		if (ri == ri)
			std::cout << "ri == ri" << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "const_reverse_iterator" <<RST<< std::endl;
	{
		cri = v.rbegin();
		ri = v.rbegin();
		// ri = v.begin();			// possible in ft::, not possible in std::
		while (cri != v.rend())
		{
			std::cout << *cri << " ";
			++cri;
		}
		cri = v.rbegin();
		cri += 2;
		cri -= 1;
		std::cout << std::endl << *cri << std::endl;
		cri = ri;
		std::cout << *cri << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "testing the category" <<RST<< std::endl;
	{
		ft::iterator_traits<ft::vector<int>::iterator> tt;
		(void)tt;
		typedef ft::iterator_traits<int*> traits;
		if (typeid(traits::iterator_category)==typeid(ft::random_access_iterator_tag))
			std::cout <<GRN<< "int* is a random-access iterator" <<RST<< std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "+ - * []" <<RST<< std::endl;
	{
		cri = v.rbegin();
		cri = cri + 3;
		std::cout << *cri << " ";
		cri = cri - 2;
		std::cout << *cri << " ";
		std::cout << cri[0] << cri[1] ; // << cri[-1] << " "; no bound checking is performed
		cri = 1 + cri;
		// cri = cri - cri; // ? reverse iterator doesn't have an operator=
		std::cout << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "->" <<RST<< std::endl;
	{
		ft::vector<menfou>	vmf;
		ft::vector<menfou>::iterator imf;
		vmf.push_back(menfou('c'));
		imf = vmf.begin();
		std::cout << imf->c << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "egualities const an not const" <<RST<< std::endl;
	{
		ft::vector<char>::iterator			iv1 = v.begin();
		ft::vector<char>::const_iterator	iv2(v.begin());
		(void)iv1;
		(void)iv2;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "reverse_iterator - reverse_iterator" <<RST<< std::endl;
	{
		ft::vector<int>						v(2, 42);
		ft::vector<int>::reverse_iterator	iv;
		
		std::ptrdiff_t d = v.rend() - v.rbegin();
		std::cout << d << std::endl;
		d = v.rbegin() - v.rend();
		std::cout << d << std::endl;
	}

}

// _____________________________________________________________________________
void	test_utility()
{
	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "pair" <<RST<< std::endl;
	{
		ft::pair<float, int>		prfi(1.5, 12);
		ft::pair<menfou, menfou>	prmm = ft::make_pair(menfou('A'), menfou('B'));
		std::cout << prfi.first << std::endl << prfi.second << std::endl;
		std::cout << prmm.first << prmm.second << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "iterator_traits" <<RST<< std::endl;
	{
		// typedef ft::iterator_traits<int*> ft_tt;
		// typedef std::iterator_traits<int*> std_tt;

		// ? we have to make our own so this tests have no sens
		// if ((typeid(ft_tt::iterator_category) == typeid(std::random_access_iterator_tag))
		// 	== (typeid(std_tt::iterator_category) == typeid(std::random_access_iterator_tag)))
		// 	std::cout << "ok" << std::endl;
		// else
		// 	std::cout << "Error : if ((typeid(ft_tt::iterator_category) " <<
		//		"== typeid(std::random_access_iterator_tag))" <<
		//		"== (typeid(std_tt::iterator_category) " <<
		//		"== typeid(std::random_access_iterator_tag)))" << std::endl;
	
		// std::cout <<typeid(ft_tt::iterator_category).name() << std::endl;
		// std::cout <<typeid(std::random_access_iterator_tag).name() << std::endl;

		// std::ptrdiff_t d = ft::distance(0x0, 0xA); // ? should not compile
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "equal" <<RST<< std::endl;
	{
		std::vector<int> v1(4, 4);
		std::vector<int> v2(5, 5);
		
		// ft::equal(15, 13, 29);							// should not compile
		// ft::equal(v1.begin(), v1.end(), v2.begin(), 3);	// should not compile
		
		std::cout << ft::equal(v1.begin(), v1.end(), v1.begin()) << std::endl;
		std::cout << ft::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;
		std::cout << ft::equal(v1.rbegin(), v1.rend(), v1.begin()) << std::endl;
		std::cout << ft::equal(v1.rbegin(), v1.rend(), v2.begin()) << std::endl;
		ENDL
	}

}

// ? ___________________________________________________________________________ ft::map

template <typename T>
class myless
{
public:
	typedef bool		result_type;
	typedef T			first_argument_type;
	typedef T			second_argument_type;
	myless() {}
	~myless() {}
	bool	operator()( const T& lhs, const T& rhs ) const
	{
		return (lhs > rhs);
	}
};

// _____________________________________________________________________________
void	test_map()
{
	std::cout <<std::endl<<CYN<< "___________________ 🧛 ft::map 🧙 ___________________" <<RST<< std::endl;

	ft::map<int, std::string>	m;
	ft::map<char, int>			m2;
	ft::map<menfou, menfou>		mf;
	ft::map<int, int>			m4;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "insert()" <<RST<< std::endl;
	{
		m.insert(ft::make_pair<int, std::string>(7, "😇"));
		m.insert(ft::make_pair<int, std::string>(4, "🧜‍"));
		m.insert(ft::make_pair<int, std::string>(20, "🧙"));
		m.insert(ft::make_pair<int, std::string>(3, "🧛"));
		m.insert(ft::make_pair<int, std::string>(5, "👽"));
		m.insert(ft::make_pair<int, std::string>(11, "🧚"));
		m.insert(ft::make_pair<int, std::string>(30, "🥷"));
		m.insert(ft::make_pair<int, std::string>(14, "🕵️"));

		// m.display();

		for (int i = 0; i < 1000; ++i)
			m4.insert(ft::pair<int, int>(rand(), i));

		// // m4.display();

		m2.insert(ft::make_pair<char, int>('z', 99));
		m2.insert(ft::make_pair<char, int>('a', 0));
		std::cout << m2.insert(ft::make_pair<char, int>('a', 1)).second << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator= and copy" <<RST<< std::endl;
	{
		ft::map<int, int>	mc1, mc2, mc3, mc4;

		mc1.insert(ft::make_pair(1, 1));

		mc2.insert(ft::make_pair(1, 1));
		mc2.insert(ft::make_pair(2, 2));
		mc2.insert(ft::make_pair(3, 3));

		if (mc3.size() != 0)
			std::cout << "wrong size" << std::endl;

		mc3 = mc2;
		mc3[3] = 9;
		for (ft::map<int, int>::iterator it = mc3.begin(); it != mc3.end(); ++it)
			std::cout << it->second << std::endl;
		if (mc3.size() != 3)
			std::cout << "wrong size" << std::endl;

		mc3 = mc1;
		for (ft::map<int, int>::iterator it = mc3.begin(); it != mc3.end(); ++it)
			std::cout << it->second << std::endl;
		if (mc3.size() != 1)
			std::cout << "wrong size" << std::endl;

		mc3 = mc4;
		for (ft::map<int, int>::iterator it = mc3.begin(); it != mc3.end(); ++it)
			std::cout << it->second << std::endl;
		if (mc3.size() != 0)
			std::cout << "wrong size" << std::endl;

		ft::map<int, int>	mc5(mc2);
		for (ft::map<int, int>::iterator it = mc5.begin(); it != mc5.end(); ++it)
			std::cout << it->second << std::endl;
		if (mc5.size() != 3)
			std::cout << "wrong size" << std::endl;
	}

	// _________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator[]" <<RST<< std::endl;
	{
		std::cout << m[7] << std::endl;
		m[7] = "🧙";
		std::cout << m[7] << std::endl;
		m[7] = "😇";
		std::cout << m[0] << std::endl;
		m.insert(ft::make_pair<int, std::string>(0,"👽"));
		std::cout << m[0] << std::endl;
		m[0] = "🧟‍♂️";
		std::cout << m[0] << std::endl;
	}

	// _________________________________________________________________________
	std::cout <<std::endl<<CYN<< "size()" <<RST<< std::endl;
	{
		std::cout << mf.size() << std::endl;
		std::cout << m.size() << std::endl;
		std::cout << m2.size() << std::endl;
	}

	// _________________________________________________________________________
	std::cout <<std::endl<<CYN<< "empty()" <<RST<< std::endl;
	{
		std::cout << mf.empty() << std::endl;
		std::cout << m.empty() << std::endl;
		std::cout << m2.empty() << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "erase()" <<RST<< std::endl;
	{
		while (!m.empty())
		{
			std::cout << "m.size : " << m.size() << std::endl;
			m.erase(m.begin());
			for (ft::map<int, std::string>::const_iterator im = m.begin(); im != m.end(); ++im)
				std::cout << im->first << im->second << "  ";
		}
		std::cout << std::endl;
		while (!m4.empty())
		{
			m4.erase(m4.begin());
		}
		for (ft::map<int, int>::const_iterator im = m4.begin(); im != m4.end(); ++im)
			std::cout << im->first << im->second << " " << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "clear()" <<RST<< std::endl;
	{
		m.insert(ft::make_pair<int, std::string>(7, "😇"));
		m.insert(ft::make_pair<int, std::string>(4, "🧜"));
		m.insert(ft::make_pair<int, std::string>(20, "🧙"));

		for (ft::map<int, std::string>::iterator im = m.begin(); im != m.end(); ++im)
				std::cout << im->first << im->second << " " << std::endl;

		m.clear();
		std::cout << "!m.empty() : " << (!m.empty()) <<std::endl;

		for (ft::map<int, std::string>::iterator im = m.begin(); im != m.end(); ++im)
				std::cout << im->first << im->second << " " << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "swap()" <<RST<< std::endl;
	{
		ft::map<std::string, std::string>	sw1;
		ft::map<std::string, std::string>	sw2;

		sw1.insert(ft::pair<std::string, std::string>("1", "un"));
		sw1.insert(ft::pair<std::string, std::string>("2", "deux"));
		sw1.insert(ft::pair<std::string, std::string>("3", "trois"));

		// sw2.insert(ft::pair<std::string, std::string>("v", "i"));

		for (ft::map<std::string, std::string>::iterator isw = sw1.begin();
			isw != sw1.end(); ++isw)
			std::cout << isw->first << " " << isw->second << " | ";
		std::cout << std::endl;
		for (ft::map<std::string, std::string>::iterator isw = sw2.begin();
			isw != sw2.end(); ++isw)
			std::cout << isw->first << " " << isw->second << " | ";
		std::cout << std::endl;

		sw1.swap(sw2);
		for (ft::map<std::string, std::string>::iterator isw = sw1.begin();
			isw != sw1.end(); ++isw)
			std::cout << isw->first << " " << isw->second << " | ";
		std::cout << std::endl;
		for (ft::map<std::string, std::string>::iterator isw = sw2.begin();
			isw != sw2.end(); ++isw)
			std::cout << isw->first << " " << isw->second << " | ";
		std::cout << std::endl;

		sw2.swap(sw1);
		for (ft::map<std::string, std::string>::iterator isw = sw1.begin();
			isw != sw1.end(); ++isw)
			std::cout << isw->first << " " << isw->second << " | ";
		std::cout << std::endl;
		for (ft::map<std::string, std::string>::iterator isw = sw2.begin();
			isw != sw2.end(); ++isw)
			std::cout << isw->first << " " << isw->second << " | ";
		std::cout << std::endl;

		sw2.swap(sw2);
		for (ft::map<std::string, std::string>::iterator isw = sw2.begin();
			isw != sw2.end(); ++isw)
			std::cout << isw->first << " " << isw->second << " | ";
		std::cout << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "bidirictional_iterator" <<RST<< std::endl;
	{
		ft::map<int, std::string>::iterator it;

		if (m.begin() == m.end())
			std::cout << "(m.begin() == m.end())" << std::endl;

		m.insert(ft::make_pair<int, std::string>(7, "😇"));
		m.insert(ft::make_pair<int, std::string>(4, "🧜"));
		m.insert(ft::make_pair<int, std::string>(20, "🧙"));
		m.insert(ft::make_pair<int, std::string>(3, "🧛"));
		m.insert(ft::make_pair<int, std::string>(5, "👽"));
		m.insert(ft::make_pair<int, std::string>(11, "🧚"));
		m.insert(ft::make_pair<int, std::string>(11, "👽"));	// will not be stored
		m.insert(ft::make_pair<int, std::string>(30, "🥷"));
		m.insert(ft::make_pair<int, std::string>(14, "🕵️"));

		// m.display();

		std::cout<< "begin->second : " << m.begin()->second <<std::endl;

		it = m.begin();
		ft::pair<int, std::string> pr = *it;
		std::cout << "pr = *it; pr.second : " << pr.second << std::endl;

		it++;
		std::cout << "it++ : " << it++->first << " ++ " << it->second << std::endl;

		for (it = m.begin(); it != m.end(); ++it)
			std::cout << "for ++it : " << it->first << " " << it->second << std::endl;

		// ? implementation specific
		// ++it;
		// ++it;
		// --it;
		// std::cout << "++it : " << it->first << " " << it->second << std::endl;

		for (it = --m.end(); it != m.begin(); --it)
			std::cout << "for --it : " << it->first << " " << it->second << std::endl;
		std::cout << "--it : " << it->first << " " << it->second << std::endl;
	
		// displaying m2
		for (ft::map<char, int>::iterator im = m2.begin(); im != m2.end(); ++im)
			std::cout << im->first << " " << im->second << std::endl;

		ft::map<int, menfou>							mp;
		unsigned int									lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
			mp.insert(ft::make_pair(i, 'a' + i));

		ft::map<int, menfou>::reverse_iterator			cit(mp.rbegin());
		ft::map<int, menfou>::const_reverse_iterator	cite(mp.rbegin());

		std::cout << ((++cit)->first) << std::endl;
		std::cout << ((++cit)->first) << std::endl;
		std::cout << ((++cit)->first) << std::endl;
		std::cout << ((++cit)->first) << std::endl;

		std::cout << ((++cite)->first) << std::endl;
		std::cout << ((cite++)->first) << std::endl;
		std::cout << ((cite++)->first) << std::endl;
		std::cout << ((++cite)->first) << std::endl;

		std::cout << cit->second << std::endl;
		std::cout << cite->second << std::endl;

		std::cout << ((--cit)->first) << std::endl;
		std::cout << ((--cit)->first) << std::endl;
		std::cout << ((--cit)->first) << std::endl;
		std::cout << ((--cit)->first) << std::endl;

		std::cout << ((--cite)->first) << std::endl;
		std::cout << ((cite--)->first) << std::endl;
		std::cout << ((--cite)->first) << std::endl;
		std::cout << ((cite--)->first) << std::endl;

		std::cout << (*cit).second << std::endl;
		std::cout << (*cite).second << std::endl;
	
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "key_comp" <<RST<< std::endl;
	{
		ft::map<int, char>				mya;
		ft::map<int, char>::key_compare	a = mya.key_comp();
		std::cout << a(-1, 2) << std::endl;
		std::cout << a(2, -1) << std::endl;
		std::cout << a(0, 0) << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "value_comp and custom comp" <<RST<< std::endl;
	{
		ft::map<int, char, myless<int> >					mya;
		ft::map<int, char, myless<int> >::value_compare		a = mya.value_comp();
		ft::map<int, char, std::less<int> >					myb;
		ft::map<int, char, std::less<int> >::value_compare	b = myb.value_comp();

		mya.insert(ft::pair<int, char>(1, 'a'));
		mya.insert(ft::pair<int, char>(2, 'b'));
		myb.insert(ft::pair<int, char>(1, 'a'));
		myb.insert(ft::pair<int, char>(2, 'b'));
		std::cout << a(*mya.begin(), *(++mya.begin())) << std::endl;
		std::cout << a(*(++mya.begin()), *(mya.begin())) << std::endl;
		std::cout << a(*(mya.begin()), *(mya.begin())) << std::endl;

		for (ft::map<int, char, myless<int> >::iterator it = mya.begin();
				it != mya.end(); ++it)
			std::cout << it->first << std::endl;

		std::cout << b(*mya.begin(), *(++mya.begin())) << std::endl;
		std::cout << b(*(++mya.begin()), *(mya.begin())) << std::endl;
		std::cout << b(*(mya.begin()), *(mya.begin())) << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "find" <<RST<< std::endl;
	{
		ft::map<int, std::string>::iterator			it;
		it = m.find(5);
		std::cout << it->first << " " << it->second << std::endl;
		it = m.find(12345);
		if (it == m.end())
			std::cout << "true" << std::endl;
		ft::map<int, std::string>::const_iterator	cit1(m.find(30));
		std::cout << cit1->first << " " << cit1->second << std::endl;
		ft::map<int, std::string>::const_iterator	cit2(m.find(666));
		if (cit2 == m.end())
			std::cout << "true" << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "upper_range" <<RST<< std::endl;
	{
		ft::map<char,int>				mymap;
		ft::map<char,int>::iterator		itlow,itup;
		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;
		itlow = mymap.lower_bound('b');  // itlow points to b
		itup = mymap.upper_bound('d');   // itup points to e (not d!)
		for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "lower_range" <<RST<< std::endl;
	{
		std::map<char,int>				mymap;
		std::map<char,int>::iterator	itlow,itup;
		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;
		itlow = mymap.lower_bound('b');  // itlow points to b
		itup = mymap.upper_bound('d');   // itup points to e (not d!)
		for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "equal_range" <<RST<< std::endl;
	{
		ft::map<char,int>	mymap;
		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator>	ret;
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		ret = mymap.equal_range('b');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}

	// ? Uncomment this to test -> on a const
	{
		ft::map<int, char> m;
		m.insert(ft::make_pair(0, '0'));
		m.insert(ft::make_pair(1, '1'));
		ft::map<int, char>::const_iterator cim(m.begin());
		cim = m.begin();
		++cim;
		// cim->second = 12;	// ? should not compile
		std::cout << cim->second << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "testing iterators validity" <<RST<< std::endl;
	{
		ft::map<int, std::string> mi6;

		mi6.insert(ft::make_pair<int, std::string>(1, "🧛"));
		mi6.insert(ft::make_pair<int, std::string>(2, "🧜"));
		mi6.insert(ft::make_pair<int, std::string>(3, "👽"));
		mi6.insert(ft::make_pair<int, std::string>(4, "😇"));
		mi6.insert(ft::make_pair<int, std::string>(5, "🧚"));
		mi6.insert(ft::make_pair<int, std::string>(6, "🕵️"));
		mi6.insert(ft::make_pair<int, std::string>(7, "🧙"));
		mi6.insert(ft::make_pair<int, std::string>(8, "🥷"));

		ft::map<int, std::string>::iterator it = ++mi6.begin();
		ft::map<int, std::string>::iterator it2 = --mi6.end();

		for (ft::map<int, std::string>::const_iterator im = mi6.begin(); im != mi6.end(); ++im)
			std::cout << im->first << im->second << " " << std::endl;
		std::cout << std::endl;
		mi6.erase(4);
		for (ft::map<int, std::string>::const_iterator im = mi6.begin(); im != mi6.end(); ++im)
			std::cout << im->first << im->second << " " << std::endl;
		std::cout << std::endl;

		mi6.erase(42);
		mi6.erase(5);
		mi6.erase(6);

		std::cout << it->first << std::endl;
		std::cout << it2->first << std::endl;
		mi6.insert(ft::make_pair<int, std::string>(-1, "🧛"));
		mi6.insert(ft::make_pair<int, std::string>(5, "🕵️"));
		mi6.insert(ft::make_pair<int, std::string>(40, "🕵️"));
		std::cout << it->first << std::endl;
		std::cout << it2->first << std::endl;

		std::list<ft::pair<const int, std::string> > lst;
		unsigned int lst_size = 16;
		for (unsigned int i = 1; i < lst_size; ++i)
			lst.push_back(ft::pair<const int, std::string>(i, std::string((1), i + 64)));
		ft::map<int, std::string> mp(lst.begin(), lst.end());
		for (ft::map<int, std::string>::const_iterator im = mp.begin(); im != mp.end(); ++im)
			std::cout << im->first << im->second << " " << std::endl;
		mp.erase(4);
		mp.erase(7);
		mp.erase(6);
		for (ft::map<int, std::string>::const_iterator im = mp.begin(); im != mp.end(); ++im)
			std::cout << im->first << im->second << " " << std::endl;
		std::cout << std::endl;
	}

	return ;
}

// ? ___________________________________________________________________________ ft::stack

// _____________________________________________________________________________
void	test_stack(void)
{
	std::cout <<std::endl<<CYN<< "__________________ft::stack__________________" <<RST<< std::endl;

	// _________________________________________________________________________
	std::cout <<CYN<< "test with default container (ft::vector)" <<RST<< std::endl;
	{
		ft::stack<int>	stk;
		stk.push(1);
		stk.push(2);
		stk.push(3);
		stk.push(4);
		stk.push(5);
		stk.push(6);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
		ft::stack<int>	stk2(stk);
		stk.push(7);
		stk.push(8);
		stk.push(9);
		stk.push(0);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
	}

	// _________________________________________________________________________
	std::cout <<CYN<< "test with std::vector as container" <<RST<< std::endl;
	{
		std::vector<int>					vec;
		vec.push_back(21);
		vec.push_back(42);
		ft::stack<int, std::vector<int> >	stk(vec);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		stk.push(1);
		stk.push(2);
		stk.push(3);
		stk.push(4);
		stk.push(5);
		stk.push(6);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
		stk.push(7);
		stk.push(8);
		stk.push(9);
		stk.push(0);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
	}

	// _________________________________________________________________________
	std::cout <<CYN<< "test with std::list as container" <<RST<< std::endl;
	{
		std::list<int>					vec;
		vec.push_back(21);
		vec.push_back(42);
		ft::stack<int, std::list<int> >	stk(vec);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		stk.push(1);
		stk.push(2);
		stk.push(3);
		stk.push(4);
		stk.push(5);
		stk.push(6);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
		stk.push(7);
		stk.push(8);
		stk.push(9);
		stk.push(0);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
	}

		// _____________________________________________________________________
	std::cout <<CYN<< "test with std::deque as container" <<RST<< std::endl;
	{
		std::deque<char>					vec;
		vec.push_back(21);
		vec.push_back(42);
		ft::stack<char, std::deque<char> >	stk(vec);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		stk.push('a' + 1);
		stk.push('a' + 2);
		stk.push('a' + 3);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
		stk.push('a' + 1);
		stk.push('a' + 2);
		stk.push('a' + 3);
		stk.push(9);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
	}

	// _________________________________________________________________________
	std::cout <<CYN<< "using custom class" <<RST<< std::endl;
	{
		std::vector<menfou>					vec;
		vec.push_back(menfou(21));
		vec.push_back(menfou(42));
		ft::stack<menfou, std::vector<menfou> >	stk(vec);
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		stk.push(menfou('a' + 1));
		stk.push(menfou('a' + 2));
		stk.push(menfou('a' + 3));
		stk.push(menfou('a' + 4));
		stk.push(menfou('a' + 5));
		stk.push(menfou('a' + 6));
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
		stk.push(menfou('a' + 7));
		stk.push(menfou('a' + 8));
		stk.push(menfou('a' + 9));
		stk.push(menfou('a' + 10));
		std::cout << "empty\t: " << stk.empty() << std::endl;
		std::cout << "size\t: " << stk.size() << std::endl;
		while (stk.size())
		{
			std::cout << stk.top() << std::endl;
			stk.pop();
		}
	}

	// _________________________________________________________________________
	std::cout <<CYN<< "==, !=, <, >, <=, >=" <<RST<< std::endl;
	{
		ft::stack<int, ft::vector<int> >	stk;
		stk.push(1);
		stk.push(2);
		stk.push(3);
		ft::stack<int, ft::vector<int> >	stk2(stk);
		std::cout << "(stk == stk2) : " << (stk == stk2) << std::endl;
		std::cout << "(stk != stk2) : " << (stk != stk2) << std::endl;
		std::cout << "(stk < stk2) : " << (stk < stk2) << std::endl;
		std::cout << "(stk > stk2) : " << (stk > stk2) << std::endl;
		std::cout << "(stk <= stk2) : " << (stk <= stk2) << std::endl;
		std::cout << "(stk >= stk2) : " << (stk >= stk2) << std::endl;

		std::cout << "(stk2 == stk) : " << (stk2 == stk) << std::endl;
		std::cout << "(stk2 != stk) : " << (stk2 != stk) << std::endl;
		std::cout << "(stk2 < stk) : " << (stk2 < stk) << std::endl;
		std::cout << "(stk2 > stk) : " << (stk2 > stk) << std::endl;
		std::cout << "(stk2 <= stk) : " << (stk2 <= stk) << std::endl;
		std::cout << "(stk2 >= stk) : " << (stk2 >= stk) << std::endl;
		stk2.pop();
		stk2.push(4);
		std::cout << "(stk == stk2) : " << (stk == stk2) << std::endl;
		std::cout << "(stk != stk2) : " << (stk != stk2) << std::endl;
		std::cout << "(stk < stk2) : " << (stk < stk2) << std::endl;
		std::cout << "(stk > stk2) : " << (stk > stk2) << std::endl;
		std::cout << "(stk <= stk2) : " << (stk <= stk2) << std::endl;
		std::cout << "(stk >= stk2) : " << (stk >= stk2) << std::endl;

		std::cout << "(stk2 == stk) : " << (stk2 == stk) << std::endl;
		std::cout << "(stk2 != stk) : " << (stk2 != stk) << std::endl;
		std::cout << "(stk2 < stk) : " << (stk2 < stk) << std::endl;
		std::cout << "(stk2 > stk) : " << (stk2 > stk) << std::endl;
		std::cout << "(stk2 <= stk) : " << (stk2 <= stk) << std::endl;
		std::cout << "(stk2 >= stk) : " << (stk2 >= stk) << std::endl;
	}
	
	return ;
}

// ? ___________________________________________________________________________ main

int	main(void)
{
	std::cout << std::boolalpha;

	test_utility();
	test_vector_iterator();
	test_vector();
	test_map();
	test_stack();

	return (0);
}
