#include "board.h"
#include <iostream>
#include <vector>

void board::read_board_from_file(const char* file) {

};

void board::read_params_from_cmdline() {
	std::cout << "read" << std::endl;
	const char* testfile = "gol_examples\random250_in.gol";
	read_board_from_file(testfile);

};
void board::compute_GOL() {
	std::cout << "compute" << std::endl;
};
void board::write_to_file() {
	std::cout << "write" << std::endl;
};
