#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# ifdef STD
	#include <map>
	namespace ft = std;
# else
	#include "../inc/map.hpp"
# endif

void map_test(void)
{
    std::cout << "### map ###\n" << std::endl;
    ft::map<char, int> map_a ;
	ft::pair<char, int> p1('a', 0);
	ft::pair<char, int> p2('b', -1);
	ft::pair<char, int> p3('c', 42);
    ft::map<char, int>::iterator it;
	map_a.insert(p1);
	map_a.insert(p2);
	map_a.insert(p3);
    it = map_a.begin();
    std::cout << "map : ";
    while(it != map_a.end())
    {
        std::cout << (*it).first << " " << (*it).second << "|";
        it++;
    }
    std::cout << std::endl;
    std::cout << "empty : " << map_a.empty() << std::endl;
    std::cout << "find 'c' : " << (*(map_a.find('c'))).second << std::endl;
}

#endif