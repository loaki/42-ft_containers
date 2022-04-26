#ifndef _REVERSE_ITERATOR_HPP_
# define    _REVERSE_ITERATOR_HPP_

# include "iterator_traits.hpp"
# include <cstddef>  // for ptrdiff_t

namespace ft
{
	template <typename _Iter>
	class reverse_iterator
	{
	private:
		_Iter														_t;

	protected:
		_Iter 														_current;
	public:
		typedef _Iter                                            	iterator_type;
		typedef typename iterator_traits<_Iter>::difference_type	difference_type;
		typedef typename iterator_traits<_Iter>::reference       	reference;
		typedef typename iterator_traits<_Iter>::pointer        	pointer;
		typedef typename iterator_traits<_Iter>::iterator_category  category;
	
		//void
		reverse_iterator() : _t(), _current() {}
		
		//normal construct
		explicit reverse_iterator(_Iter __x) : _t(__x), _current(__x) {}
		template <class T>

		//copy	
		reverse_iterator(const reverse_iterator<T>& __u) : _t(__u.base()), _current(__u.base()) {}
		template <class T>
			
			reverse_iterator& operator=(const reverse_iterator<T>& __u)
				{ _t = _current = __u.base(); return *this; }
		
		_Iter base() const {return _current;}
		
		reference operator*() const {_Iter _tmp = _current; return *--_tmp;}
		reverse_iterator  operator+( difference_type x) const
		{
			return reverse_iterator(_current - x);
		}
		
		reverse_iterator  operator-( difference_type x) const
		{
			return reverse_iterator(_current + x);
		}
		
		reference operator[](difference_type index)
		{
			return *(*this + index);
		}

		pointer operator->() const
		{
			_Iter _tmp = _current; 
			return std::__addressof(*--_tmp);
			// return std::addressof(*--_tmp);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			this->operator++();
			return (tmp);
		}

		reverse_iterator& operator++()
		{
			_current--;
			return *this;
		}
		reverse_iterator& operator--()
		{
			_current++;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);
			this->operator--();
			return tmp;
		}

		reverse_iterator&  operator+=( difference_type x)
		{
			_current -= x;
			return *this;
		}

		reverse_iterator&  operator-=( difference_type x)
		{
			_current += x;
			return *this;
		}
	};

	
	/**** NON MEMBER FUNCTION ****/
	template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return rhs.base() - lhs.base();
    }

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return (rev_it + n);
    }
	
	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() < rhs.base();
    }

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() <= rhs.base();
    }

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() > rhs.base();
    }

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() >= rhs.base();
    }

	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() == rhs.base();
    }
}

#endif