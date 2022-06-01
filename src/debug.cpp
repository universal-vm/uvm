#include "./debug.h"
#include <iostream>
#include <cstdarg>

using namespace std;

/*
 *	COMMENT THE VARIABLE BELOW IF YOU ARE COMPILING FOR CONSUMER
 *	USE. LEAVE IT UNCOMMENTED IF YOU WANT TO TEST THE COMPONENTS
 *	OF UVM.
 */
#define DEBUG_MODE;

void ERROR(const char *TEXT_TO_PRINT)
{
    cout << "\033[1;31m[ERROR]\t\033[1;38m" << TEXT_TO_PRINT << "\033[0m\n";
}

void INFO(const char *TEXT_TO_PRINT)
{
    cout << "\033[34m[INFO]\t\033[1;38m" << TEXT_TO_PRINT << "\033[0m\n";
}

void DEBUG(const char *TEXT_TO_PRINT)
{
    #ifdef DEBUG_MODE
    cout << "\033[36m[DEBUG]\t\033[1;38m" << TEXT_TO_PRINT << "\033[0m\n";
    #endif
}

void DEBUG_INT(int NUM_TO_PRINT)
{
    #ifdef DEBUG_MODE
    cout << "\033[36m[DEBUG]\t\033[1;38m" << NUM_TO_PRINT << "\033[0m\n";
    #endif
}