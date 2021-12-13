// GOL_sequential.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
    
    board myboard;
    myboard.read_params_from_cmdline();
    myboard.compute_GOL();
    myboard.write_to_file();

};