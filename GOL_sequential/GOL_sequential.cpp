// GOL_sequential.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"
#include <vector>
#include "timing.h"

int main(int argc, char** argv) {
    Timing* timing = Timing::getInstance();
    timing->startSetup();
    board myboard;
    myboard.read_params_from_cmdline(argc,argv);
    timing->stopSetup();
    timing->startComputation();
    myboard.compute_GOL();
    timing->stopComputation();
    timing->startFinalization();
    //myboard.print_board_like_input();
    myboard.write_to_file();
    timing->stopFinalization();
    std::string output = timing->getResults();
    if (myboard.get_measure_flag())cout << output << endl;
};