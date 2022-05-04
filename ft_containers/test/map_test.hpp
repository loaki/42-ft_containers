#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# ifdef STD
	#include <map>
	namespace ft = std;
# else
	#include "../inc/map.hpp"
# endif

#include <iostream>
#include <stdlib.h>


void map_test(void)
{
    std::cout << "### map ###\n" << std::endl;
    ft::map<char, int> map_a ;
	ft::pair<char, int> p1('a', 0);
	ft::pair<char, int> p2('b', -1);
	ft::pair<char, int> p3('c', 42);
	ft::pair<char, int> p4('d', 90000);
	ft::pair<char, int> p5('e', 69);
	ft::pair<char, int> p6('e', 70);
    ft::map<char, int>::iterator it;
	map_a.insert(p1);
	map_a.insert(p2);
	map_a.insert(p3);
	map_a.insert(p4);
	map_a.insert(p5);
	map_a.insert(p6);
    (*(map_a.find('c'))).second = 13;
    it = map_a.begin();
    std::cout << "map              : ";
    while(it != map_a.end())
    {
        std::cout << (*it).first << " " << (*it).second << "|";
        it++;
    }
    std::cout << std::endl;
    std::cout << "empty            : " << map_a.empty() << std::endl;
    std::cout << "size             : " << map_a.size() << std::endl;
    std::cout << "max_size         : " << map_a.max_size() << std::endl;
    std::cout << "find('c')        : " << (*(map_a.find('c'))).second << std::endl;
    std::cout << "upper_bound('b') : " << (*(map_a.upper_bound('b'))).first << std::endl;
    std::cout << "lower_bound('b') : " << (*(map_a.lower_bound('b'))).first << std::endl;
    srand(2);
    for (int i = 0; i < 1000; i++)
    {
        map_a.insert(ft::make_pair(rand(), rand()));
    }
    it = map_a.begin();
    std::cout << "map              : ";
    while(it != map_a.end())
    {
        std::cout << (*it).first << " " << (*it).second << "|";
        it++;
    }
}

#endif