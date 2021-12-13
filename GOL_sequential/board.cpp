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
	//getline(infile, line);
	char b;
	infile >> this->generations >> b >> this->size_x;
	this->size_y = this->size_x;
	//cout << a << b << c<<endl;
	int line_counter = 0;
	this->gol_board = new bool[this->size_y*this->size_x];
	while (getline(infile, line))
	{
		if (line_counter == 0)
		{
			line_counter++;
			continue;
		}
		int column_counter = 0;
		for (auto it = line.cbegin(); it != line.cend(); ++it) {
			if (*it == 'x') {
				this->gol_board[(line_counter-1)*size_y+column_counter] = true;
				//cout << "true";
			}
			else if (*it == '.') {
				this->gol_board[(line_counter-1) * size_y + column_counter] = false;
				//cout << "false";
			}
			else {
				cout << "unexpected character " << *it << " while reading board" << endl;
				return;
			};
			column_counter++;
			//cout << endl;
		};
		line_counter++;
	};
	for (int i = 0;i < 250;i++) {
		cout << this->gol_board[i] << endl;
	};
	cout << this->gol_board << endl;
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
