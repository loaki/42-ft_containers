#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# ifdef STD
    #include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
# else
	#include "../inc/vector.hpp"
# endif


template<typename V>
void display_vector(V vector)
{
    std::cout << "vector      : ";
    for(unsigned long i = 0; i < vector.size(); i++)
        std::cout << vector[i];
    std::cout << std::endl;
    try {
        std::cout << "at(0)       : " << vector.at(0) << std::endl;
    } catch (...) {
        std::cout << "index 0 out of range" << std::endl;
    }
    std::cout << "begin = end : " << (vector.begin() == vector.end()) << std::endl;
    std::cout << "empty       : " << vector.empty() << std::endl;
    std::cout << "size        : " << vector.size() << std::endl;
}

void vector_test(void)
{
    std::cout << "### vector ###" << std::endl;
    ft::vector<int> vector_a;
    ft::vector<int> vector_b;
    ft::vector<std::string> vector_c;
    for(int i = 0; i < 10; i++)
        vector_a.push_back(i);
    vector_c.push_back("hello");
    vector_c.push_back("world");
    vector_a.pop_back();
    vector_a.swap(vector_b);
    display_vector(vector_a);
    std::cout << std::endl;
    display_vector(vector_b);
    std::cout << std::endl;
    vector_b.resize(3);
    display_vector(vector_b);
    std::cout << std::endl;
    std::cout << "vector      : ";
    for(unsigned long i = 0; i < vector_c.size(); i++)
        std::cout << vector_c[i];
    std::cout << std::endl;
    try {
        std::cout << "at(0)       : " << vector_c.at(0) << std::endl;
    } catch (...) {
        std::cout << "index 0 out of range" << std::endl;
    }
    std::cout << "begin = end : " << (vector_c.begin() == vector_c.end()) << std::endl;
    std::cout << "empty       : " << vector_c.empty() << std::endl;
    std::cout << "size        : " << vector_c.size() << std::endl;    std::cout << std::endl;
}

#endif