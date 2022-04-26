#ifndef _PAIR_HPP_
# define _PAIR_HPP_

namespace ft
{
    
    template<class T1,class T2>
    class pair{ 
    
    public:
    /*ATTRIBUTES*/
    typedef T1  first_type;
    typedef T2 second_type;
    T1  first; 
    T2 second;
    
    /*CONSTRUCTORS*/
    pair() :first(T1()), second(T2()) { }

    pair(const T1&x, const T2&y):first(x),second(y){} 
    
    template<class U,class V>
    pair(const pair<U,V>&p) : first(p.first), second(p.second) {}

    /*OPERATOR =*/
    pair& operator=( const pair& other )
    {
        first = other.first;
        second = other.second;
        return *this;
    }
};

    /*NON-MEMBER FUNCTIONS*/
    template<class T1, class T2>
    pair<T1,T2> make_pair(T1 to1,T2 to2) 
    {
        return pair<T1,T2>(to1,to2);
    }

    /*OPERATORS NON-MEMBER*/ 
    template< class T1, class T2 >
    bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        if (lhs.first == rhs.first && lhs.second == rhs.second)
            return (true);
        else
            return (false);
    }

    template< class T1, class T2 >
    bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        if (!(lhs == rhs))
            return (true);
        else
            return (false);
    }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }
}

#endif