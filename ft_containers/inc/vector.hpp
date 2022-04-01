#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <stdexcept>
#include <stddef.h>
#include <limits>
#include <algorithm>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T                                       value_type;
		typedef Allocator                               allocator_type;
		typedef size_t                                  size_type;
		typedef ptrdiff_t                               difference_type;
		typedef T                                       &reference;
		typedef const T                                 &const_reference;
        typedef T                                       *pointer;
		typedef const T                                 const_pointer;
		typedef ft::iterator<value_type>                iterator;
		typedef ft::iterator<value_type const>          const_iterator;
		typedef ft::reverse_iterator<iterator>          reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
    };
};

#endif