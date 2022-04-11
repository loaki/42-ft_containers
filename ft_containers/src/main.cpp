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
    ft::vector<int> vector_int;
    for(int i = 0; i < 10; i++)
        vector_int.push_back(i);
    for(unsigned long i = 0; i < vector_int.size(); i++)
        std::cout << vector_int[i];
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