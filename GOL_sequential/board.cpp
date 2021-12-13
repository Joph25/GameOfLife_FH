#include "board.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void board::read_board_from_file(const char* board_file) {
	std::cout << board_file << std::endl;
	std::ifstream infile(board_file);
	if (!infile.is_open()) {
		cout << "Cant open file " << board_file << endl;
		return;
	};
	std::string line;
	getline(infile, line);
	string generations_str,size_str;
	bool comma_flg = false;
	for (auto it = line.cbegin(); it != line.cend(); ++it) {
		if (*it == ',') {
			comma_flg = true;
			continue;
		};
		if (comma_flg) {
			size_str.push_back(*it);
		}
		if (!comma_flg) {
			generations_str.push_back(*it);
		};
		


	}
	cout << generations_str << endl;
	cout << size_str << endl;
	int generations = atoi(generations_str.c_str());
	cout << generations << endl;

	while (getline(infile, line))
	{
		//std::cout << line << std::endl;
	};
};

void board::read_params_from_cmdline() {
	const char* testfile = "..\\gol_examples\\random250_in.gol";
	//const char* testfile = "C:\\Root_Philipp\\FH_AI\Visual_Studio_Projekte\\GameOfLife\\gol_examples\\random250_in.gol";
	read_board_from_file(testfile);

};
void board::compute_GOL() {
	std::cout << "compute" << std::endl;
};
void board::write_to_file() {
	std::cout << "write" << std::endl;
};
