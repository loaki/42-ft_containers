#include <iostream>
#include "../includes/vector.hpp"
#include "../includes/map.hpp"
#include "vector_tests.cpp"
#include "stack_test.cpp"
#include "map_tests.cpp"

typedef void (*ft_ptr)();

void	time_calculate( ft_ptr my_function)
{
	struct timeval start, end;
    gettimeofday(&start, NULL);
	(*(my_function))();
    gettimeofday(&end, NULL);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - 
                              start.tv_usec)) * 1e-6;
    std::cout << "Time taken by program is : " << std::fixed
         << time_taken;
    std::cout << " sec" << std::endl;
}

void	vector_tests()
{
	std::cout << "\n***** INSERT() TESTS *****\n" << std::endl;
	time_calculate( &testInsert );
	std::cout << "\n***** CLEAR() TESTS *****\n" << std::endl;
	time_calculate( &testClear );
	std::cout << "\n***** COPY CONSTRUCT() TESTS *****\n" << std::endl;
	time_calculate( &construct_copy);
	std::cout << "\n*****  CONSTRUCT() TESTS *****\n" << std::endl;
	time_calculate( &construct);
	std::cout << "\n***** OPERATOR=() TESTS *****\n" << std::endl;
	time_calculate( &opEqual);
	std::cout << "\n***** BEGIN() && END() TESTS *****\n" << std::endl;
	time_calculate( &begin);
	std::cout << "\n***** RBEGIN() &&REND() TESTS *****\n" << std::endl;
	time_calculate( &rbegin);
	std::cout << "\n***** MAXSIZE()&& CAPACITY() TESTS *****\n" << std::endl;
	time_calculate( &maxSizeCap);
	std::cout << "\n***** EMPTY() TESTS *****\n" << std::endl;
	time_calculate( &empty);
	std::cout << "\n***** RESERVE() TESTS *****\n" << std::endl;
	time_calculate( &reserveCapacity);
	std::cout << "\n***** OPERATOR[]() TESTS *****\n" << std::endl;
	time_calculate( &operatorIndex);
	std::cout << "\n***** CONST OPERATOR[]() TESTS *****\n" << std::endl;
	time_calculate( &constoperatorIndex);
	std::cout << "\n***** AT() TESTS *****\n" << std::endl;
	time_calculate( &operatorAt);
	std::cout << "\n***** CONST AT() TESTS *****\n" << std::endl;
	time_calculate( &constoperatorAt);
	std::cout << "\n*****FRONT() TESTS *****\n" << std::endl;
	time_calculate( &front);
	std::cout << "\n*****CONST FRONT() TESTS *****\n" << std::endl;
	time_calculate( &constfront);
	std::cout << "\n***** BACK() TESTS *****\n" << std::endl;
	time_calculate( &	back);
	std::cout << "\n***** ERASE() TESTS *****\n" << std::endl;
	time_calculate( &testErase);
	std::cout << "\n***** POP_BACK() TESTS *****\n" << std::endl;
	time_calculate( &testPop_back);
	std::cout << "\n***** PUSH_BACK() TESTS *****\n" << std::endl;
	time_calculate( &testPush_back);
	std::cout << "\n***** ASSIGN() TESTS *****\n" << std::endl;
	time_calculate( &testAssign);
	std::cout << "\n***** SWAP() TESTS *****\n" << std::endl;
	time_calculate( &testSwap);
	std::cout << "\n***** GET_ALLOCATOR() TESTS *****\n" << std::endl;
	time_calculate( &getAlloc);
	std::cout << "\n***** CONST ITERATORS TESTS *****\n" << std::endl;
	time_calculate( &testConstIterators);
	std::cout << "\n***** REVITERATORS TESTS *****\n" << std::endl;
	time_calculate( &testRevIterators);
	std::cout << "\n***** RESIZE() TESTS *****\n" << std::endl;
	time_calculate( &testResize);
	std::cout << "\n***** printSize() TESTS *****\n" << std::endl;	
	time_calculate( &printSize);
	std::cout << "\n***** RELATIONNAL OP() TESTS *****\n" << std::endl;	
	time_calculate( &relationnalOp);
}

void	stack_tests()
{
	std::cout << "\n***** CONSTRUCTOR() TESTS *****\n" << std::endl;	
	time_calculate (&stackConstruct);
	std::cout << "\n***** EMPTY() TESTS *****\n" << std::endl;	
	time_calculate( &stackEmpty);
	std::cout << "\n***** SIZE() TESTS *****\n" << std::endl;	
	time_calculate( &stackSize);
	std::cout << "\n***** TOP() TESTS *****\n" << std::endl;	
	time_calculate( &stackTop);
	std::cout << "\n***** PUSH() TESTS *****\n" << std::endl;	
	time_calculate( &stackPush);
	std::cout << "\n***** RELATIONNAL OP() TESTS *****\n" << std::endl;	
	time_calculate( &stackOp);
}

void	map_tests()
{
	std::cout << "\n***** ITERATOR() && INSERT() TESTS *****\n" << std::endl;
	time_calculate( &testMapInsertnIterator);
	std::cout << "\n***** ++IT TESTS *****\n" << std::endl;
	time_calculate( &plusminus);
	std::cout << "\n***** INSERT(IT first, IT last) TESTS *****\n" << std::endl;
	time_calculate( &testMapItLastFirstInsert);
	std::cout << "\n***** INSERT(POS, VALUE) TESTS *****\n" << std::endl;
	time_calculate( &testMapPosInsert);
	std::cout << "\n***** OPERATIONS FUNCTIONS TEST: FT VS STD *****\n" << std::endl;
	time_calculate( &testOperations);
	std::cout << "\n***** CONST ITERATOR() && INSERT() TESTS *****\n" << std::endl;
	time_calculate( &testMapInsertnConstIterator);
	std::cout << "\n***** REV ITERATOR() *****\n" << std::endl;
	time_calculate( &testMapRevIt);
	std::cout << "\n***** CONST REV ITERATOR() && [] TESTS *****\n" << std::endl;
	time_calculate( &testMapConstRevIt);
	std::cout << "\n***** MAP SWAP TESTS *****\n" << std::endl;
	time_calculate( &testMapSwap);
	std::cout << "\n***** MAP VALUE COMP && OPERATOR= && OPERATOR[] TESTS *****\n" << std::endl;	
	time_calculate( &testValComp);
	std::cout << "\n***** MAP EMPTY() TESTS *****\n" << std::endl;	
	time_calculate( &testMapEmpty);
	std::cout << "\n***** MAP KEY_COMP() TESTS *****\n" << std::endl;	
	time_calculate( &testMapKeyComp);
	std::cout << "\n***** MAP FIND() TESTS *****\n" << std::endl;	
	time_calculate( &testMapFind);
	std::cout << "\n***** MAP COUNT() TESTS *****\n" << std::endl;	
	time_calculate( &testMapCount);
	std::cout << "\n***** MAP EQUAL_RANGE() TESTS *****\n" << std::endl;	
	time_calculate( &testMapEqRange);
	std::cout << "\n***** MAP CONSTRUCT() TESTS *****\n" << std::endl;	
	time_calculate( &testConstructs);
	std::cout << "\n***** MAP ERASE() TESTS *****\n" << std::endl;	
	time_calculate( &mapErase);
	std::cout << "\n***** MAP LOWER_BOUND() && UPPER_BOUND TESTS *****\n" << std::endl;	
	time_calculate( &mapLowerUpper);
	std::cout << "\n***** MAP CLEAR() TESTS *****\n" << std::endl;	
	time_calculate( &mapClear);
}

int main ()
{
	std::cout << "\n=============== VECTOR TESTS ===============\n" << std::endl;
	vector_tests();
	std::cout << "\n=============== STACK TESTS ===============\n" << std::endl;
	stack_tests();
	std::cout << "\n===============  MAP TESTS   ===============\n" << std::endl;
	map_tests();
  	return 0;
}