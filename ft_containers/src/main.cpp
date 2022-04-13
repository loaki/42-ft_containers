#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <deque>

#ifdef STD
	std::string rd = "std_out";
    #include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	std::string rd = "ft_out";
	#include "../inc/Vector.hpp"
#endif

void test(void)
{
    std::cout << "hello" << std::endl;

    std::cout << "### vector ###" << std::endl;
    ft::vector<int> vector_a;
    ft::vector<int> vector_b;
    for(int i = 0; i < 10; i++)
        vector_a.push_back(i);
    vector_a.swap(vector_b);
    std::cout << "vector a      : ";
    for(unsigned long i = 0; i < vector_a.size(); i++)
        std::cout << vector_a[i];
    std::cout << std::endl;
    std::cout << "vector b      : ";
    for(unsigned long i = 0; i < vector_b.size(); i++)
        std::cout << vector_b[i];
    std::cout << std::endl;
    std::cout << "b at(2)       : " << vector_b.at(2) << std::endl;
    std::cout << "a begin = end : " << (vector_a.begin() == vector_a.end()) << std::endl;
    std::cout << "b begin = end : " << (vector_b.begin() == vector_b.end()) << std::endl;
    std::cout << "a empty       : " << vector_a.empty() << std::endl;
    std::cout << "b empty       : " << vector_b.empty() << std::endl;
    std::cout << "a size        : " << vector_a.size() << std::endl;
    std::cout << "b size        : " << vector_b.size() << std::endl;
    
}

int main(void)
{
    clock_t begin = clock();
    std::cout << "\e[1;34m### " << rd << " ###\e[0m\n" <<std::endl;

    std::streambuf *coutbuf = std::cout.rdbuf();
	std::ofstream rdout(rd.c_str());
    std::cout.rdbuf(rdout.rdbuf());

    test();

	rdout.close();
    std::cout.rdbuf(coutbuf);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Execution time : " << elapsed_secs << "(sec)\n" << std::endl;
}