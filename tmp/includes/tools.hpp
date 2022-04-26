#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "pair.hpp"
#include <functional>
#include <iostream>

namespace ft
{
    template <typename T>
    void swap(T &a, T &b)
    {
        T tmp;

        tmp = b;  
        b = a;
        a = tmp;
    }

    template <class value_type>
    struct tree_node
    {
        public:

        value_type  pair;
        tree_node   *right;
        tree_node   *left;
        tree_node   *parent;
        bool        is_init;
        bool        is_end;

        tree_node() : pair(), right(NULL), left(NULL), parent(NULL), is_init(false), is_end(false) {}
    };

    template <class T>
    struct less : std::binary_function<T, T, bool> 
    {
        bool operator() (const T& x, const T& y) const {return x<y;}
    };

    template <class It1, class It2 >
    bool lexicographical_compare(It1 it1_first, It1 it1_last, It2 it2_first, It2 it2_last)
    {
        while (it1_first != it1_last)
        {
                if (it2_first == it2_last || *it2_first < *it1_first)
                    return false;
                else if (*it1_first < *it2_first)
                    return true;
                it1_first++;
                it2_first++;
        }
        return (it2_first != it2_last);
    }

    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 begin1, InputIterator2 end1, InputIterator2 begin2)
    {
        while (begin1 != end1)
        {
            if (!(*begin1 != *begin2))
                return (false);
            ++begin1;
            ++begin2;
        }
        return (true);
    }
}

#endif