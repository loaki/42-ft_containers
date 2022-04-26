#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# ifdef STD
	#include <stack>
	namespace ft = std;
# else
	#include "../inc/stack.hpp"
# endif

void stack_test(void)
{
    std::cout << "### stack ###\n" << std::endl;
    ft::stack<int> stack_a;
    for (int i = 0; i < 10; i++)
        stack_a.push(i);
    ft::stack<int> stack_b(stack_a);
    std::cout << "stack : ";
    while(!stack_b.empty())
    {
        std::cout << stack_b.top() << "|";
        stack_b.pop();
    }
    std::cout << std::endl;
    std::cout << "empty : " << stack_a.empty() << std::endl;
    std::cout << "size  : " << stack_a.size() << std::endl;
    std::cout << "top   : " << stack_a.top() << std::endl;
    std::cout << std::endl;
}

#endif