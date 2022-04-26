
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "tools.hpp"
# include <iostream>
# include <memory>
# include "reverse_iterator.hpp"
# include "enable_if.hpp"

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		
		public:

		/***** MEMBERS TYPES *****/

			typedef T													value_type;	
			typedef		 		Alloc 									allocator_type;
			typedef typename 	allocator_type::reference 				reference;
			typedef typename 	allocator_type::const_reference 		const_reference;
			typedef typename 	allocator_type::pointer 				pointer;
			typedef typename 	allocator_type::const_pointer 			const_pointer;
			typedef 			T* 										iterator;
			typedef const		T*										const_iterator;
			typedef typename 	ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef				std::size_t								size_type;
			typedef				std::ptrdiff_t 							difference_type;
		

		
		/***** CONSTRUCTORS *****/
			/*empty*/
			explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0),_capacity(0), _array(NULL)
			{
				return ;
			}

			/*Constructs a container with as many and the same elements as the range [first,last) */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = 0) :
			 _allocator(alloc), _size(0), _capacity(0), _array(NULL)
			 {
				InputIterator tmp;
				size_t			size = 0;
				for (tmp  = first; tmp != last ; tmp++)
					size++;
				this->_size = size;
				this->_capacity = size;
				if (size > 0)
				{
					_array = _allocator.allocate(this->_capacity);
					pointer it = this->_array;
					for (;first != last; first++)
					{
						this->_allocator.construct(it, *first);
						it++;
					}
				}

			}

			//Constructs a container with n elements. Each element is a copy of val IS SIZE N??
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _allocator(alloc), _size(n), _capacity(n), _array(NULL)
			{
				if (n > 0)
				{
					_array = this->_allocator.allocate(this->_size);
					for (size_type i = 0; i < n; i++)
						this->_allocator.construct(this->_array + i, val);
				}
			}
		
			/***** COPY *****/
			//checker si size == 0 on peut allouer _array directement
			vector(const vector& x) : _allocator(x._allocator), _size(x._size), _capacity(x._size), _array(NULL)
			{
				if (x._size > 0)
                {
                    this->_array = this->_allocator.allocate(this->_size);
                    for (size_type i = 0, size = x._size; i < size; i++)
                    {
                        this->_allocator.construct(this->_array + i, *(x._array + i));
                    }
                }
                return;
			}

			/***** OPERATORS *****/
			vector& operator=(const vector& x)
			{
				if (*this != x)
				{
				this->clear();
				if (_capacity < x._size)
				{
					this->_allocator.deallocate(this->_array, this->_capacity);
					this->_capacity = x._size;
					if (x._size <= 0)
						return *this;
					this->_array = this->_allocator.allocate(this->_capacity);
				}
				this->_size = x._size;
				for (size_type i = 0; i < x._size; i++)
					this->_allocator.construct(_array + i, *(x._array + i));
				}
				return *this;
			}

			T &operator[](size_type index)
			{
				return *(_array + index);
			}

			const_reference operator[](size_type index) const
			{
				return *(_array + index);
			}

			reference front(void)
			{
				
				return *(this->begin());
			}

			const_reference front(void) const
			{
				
				return *(this->begin());
			}

			T &back(void)
			{
				
				int pos = _size -1;
				if (pos < 0)
					pos = 0;
				return (_array[pos]);
			}

			const_reference back(void) const
			{
				int pos = _size -1;
				if (pos < 0)
					pos = 0;
				return (_array[pos]);
			}

			T &at(size_type index)
			{
				
				if (index < _size && index >= 0)
					return *(_array + index);
				else
					throw std::out_of_range("ERROR: Element out of range");
			}

			T &at(size_type index) const
			{
				if (index < _size && index >= 0)
					return *(_array + index);
				else
					throw std::out_of_range("ERROR: Element out of range");
			}

			/*****DESTRUCTORS *****/
			virtual ~vector() 
            {
                
                for (size_t i = 0;  i < _size; i++)
                        this->_allocator.destroy(this->_array + i);
                _allocator.deallocate(_array,_size);
            };

			allocator_type get_allocator(void) const
			{
				return _allocator ;
			}

			/* EMPTY */
			bool empty() const
			{
				if (this->_size == 0)
					return (true);
				else
					return (false);
			}

			size_type size() const
			{
				return this->_size;
			}

			size_type max_size() const
			{
				return this->_allocator.max_size();
			}

			size_type	capacity() const
			{
				return this->_capacity;
			}

			/* CLEAR */
			void	clear()
			{
				if (_size == 0)
					return ;
				for (size_type i = 0, size = this->_size; i < size; i++)
					this->_allocator.destroy(this->_array + i);
				this->_size = 0;
				return ;
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type i = 0;
				iterator it = this->begin();
				for (; it + i != position && i < _size; i++);
				if (_capacity < _size + 1)
					reserve(_size + 1);
				size_type j = _capacity - 1;
				for (; j > i; j--)
				{
					this->_allocator.construct(this->_array + j, *(this->_array + (j -1)));
				}
				this->_allocator.construct(this->_array + i, val);
				_size++;
				return (iterator(_array + i));
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type elmt = position - this->_array;

                if (n == 0)
                    return;
                if (this->_size + n > this->_size * 2)
                    this->reserve(this->_size + n);
                else if (this->_size + n > this->_capacity)
                    this->reserve(this->_size * 2);
                for(pointer it = this->_array + this->_size + n - 1, ite = this->_array + elmt + n - 1; it != ite; --it) 
                {
                    this->_allocator.construct(it, *(it - n));
                    this->_allocator.destroy(it - n);
                }
                this->_size += n;
                while (n > 0)
                {
                    this->_allocator.construct(this->_array + elmt - 1 + n, val);
                    n--;
                }
                return;
            }

			template<class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last,
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) 
            {
                if (first == last)
                    return;
                difference_type elmt = position - this->_array;
                size_type n = 0;
                for (InputIterator it = first; it != last; it++)
                    n++;
                if (this->_size + n > this->_size * 2)
                    this->reserve(this->_size + n);
                else if (this->_size + n > this->_capacity)
                    this->reserve(this->_size * 2);

                for(pointer it = this->_array + this->_size + n - 1, ite = this->_array + elmt + n - 1; it != ite; it--) 
                {
                    this->_allocator.construct(it, *(it - n));
                    this->_allocator.destroy(it - n);
                }
                this->_size += n;
                while (n > 0)
                {
                    last--;
                    this->_allocator.construct(this->_array + elmt - 1 + n, *last);
                    n--;
                }
                return;
            }

			void resize(size_type count, T value = T())
			{
				if (size() > count) {
					for (size_type i = count; i != size(); ++i) {
						_allocator.destroy(_array + i);
					}
				} else if (count > size()) {
					if (count > capacity()) {
						reserve(linux_capacity_caclulator(count));
					}
					for (size_type i = size(); i != count; ++i) {
						_allocator.construct(_array + i, value);
					}
				}
				_size = count;
			}

			void push_back(const T& val)
			{
				if (_capacity == 0)
					this->reserve(1);
				else if (_capacity == _size)
				{
					this->reserve(_capacity * 2);
				}
				this->_allocator.construct(this->_array + this->_size, val);
				_size++;
			}
		
			iterator make_iter(size_type __pos)
			{return iterator(_array + __pos);}

			iterator begin()
			{
				return iterator(make_iter(0));
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(this->end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(this->end());
			}
				
			iterator end()
			{
				return iterator(_array + _size);
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			const_iterator begin() const
			{
				
				return const_iterator(this->_array);
			}

			const_iterator end() const
			{
				return const_iterator(this->_array + this->_size);
			}		
			
			void	reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				if (n <= this->_capacity)	
					return ;
				pointer new_array = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					if (i < _size)
					{
						_allocator.construct(new_array + i, *(_array + i));
						_allocator.destroy(_array + i);  
					}
				}
				if (_capacity != 0)
					_allocator.deallocate(_array, _capacity);
				_capacity = n;
				_array = new_array;
			}

			/***** LAST FT ADDED *****/

			void	pop_back()
			{
				if (this->_size)
				{
					this->_size--;
					_allocator.destroy(this->_array + this->_size);
				}
			}

			size_t	linux_capacity_caclulator(size_t n)
			{
				if (n <= _size * 2)
					return (_size * 2);
				return (n);
			}

			iterator erase (iterator position)
			{
				iterator cursor = position;
				iterator ite = this->end();

				for (; (cursor + 1) != ite; cursor++)
					cursor[0] = cursor[1];
				_allocator.destroy(this->_array + _size - 1);
				this->_size--;
				return (iterator(position));
			}

			iterator erase (iterator first, iterator last)
			{
				for(; first != last; last--)
					erase(first);
				return (iterator(first));
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}
			
			void assign (size_type n, const value_type& val)
			{
				this->clear();
                this->_size = n;
                if (this->_capacity < n)
                {
                    this->_allocator.deallocate(this->_array, this->_capacity);
                    this->_capacity = n;
                    if (n > 0)
                        this->_array = this->_allocator.allocate(this->_capacity);
                    else
                        return;
                }
                for(size_type i = 0; i < n; i++)  
                {
                    this->_allocator.construct(this->_array + i, val);
                }
                return;
			}

			void swap (vector& x)
			{
				ft::swap(_array, x._array);
				ft::swap(this->_size, x._size);
				ft::swap(_capacity, x._capacity);
			}

		/***** ATTRIBUTES ******/
		
		protected: 						// Because stack doesn't have access in private
			
			allocator_type  _allocator;
			size_type		_size;
			size_type		_capacity;
			pointer			_array;
	};

	/*NON MEMBER FUNCTIONS*/
	/*relational operators*/
	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return false;
			}
			return true;
		}
		return false;
	}

  	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs > rhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);		
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	void vec_printer(vector<T, Alloc>& vec)
	{
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << ", ";
		std::cout << std::endl;
	}
}
#endif