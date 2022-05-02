#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <deque>

#include "../test/vector_test.hpp"
#include "../test/stack_test.hpp"
#include "../test/map_test.hpp"

#ifdef STD
	std::string rd = "std_out";
#else
	std::string rd = "ft_out";
#endif

int main(void)
{
    clock_t begin = clock();
    std::cout << "\e[1;34m### " << rd << " ###\e[0m\n" <<std::endl;

    std::streambuf *coutbuf = std::cout.rdbuf();
	std::ofstream rdout(rd.c_str());
    std::cout.rdbuf(rdout.rdbuf());

    vector_test();
    stack_test();
    map_test();

	rdout.close();
    std::cout.rdbuf(coutbuf);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Execution time : " << elapsed_secs << "(sec)\n" << std::endl;
}