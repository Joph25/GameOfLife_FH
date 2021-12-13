// GOL_sequential.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"
#include <vector>

int main(int argc, char** argv) { 
    board myboard;
    myboard.read_params_from_cmdline(argc,argv);
    myboard.compute_GOL();
    myboard.print_board_like_input();
    myboard.write_to_file();

};