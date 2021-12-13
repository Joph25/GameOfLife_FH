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
	this->gol_board = new bool*[this->size_y];
	for (int i = 0;i < size_y;++i) {
		this->gol_board[i] = new bool[this->size_x];
	};
	this->next_gol_board = new bool* [this->size_y];
	for (int i = 0;i < size_y;++i) {
		this->next_gol_board[i] = new bool[this->size_x];
	};
	int line_counter = 0;
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
				this->gol_board[line_counter-1][column_counter] = true;
				//cout << "true";
			}
			else if (*it == '.') {
				this->gol_board[line_counter - 1][column_counter] = false;
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
	//this->print_board_binary();
};

void board::print_board_binary() {
	for (int i = 0;i < this->size_y;i++) {
		for (int j = 0;j < this->size_x;j++) {
			cout << this->gol_board[i][j];
		};
		cout << endl;
	};
}

void board::read_params_from_cmdline() {
	const char* testfile = "..\\gol_examples\\random250_in.gol";
	//const char* testfile = "C:\\Root_Philipp\\FH_AI\Visual_Studio_Projekte\\GameOfLife\\gol_examples\\random250_in.gol";
	read_board_from_file(testfile);

};

void board::compute_GOL() {
	std::cout << "compute" << std::endl;
	for (int gen = 0; gen < this->generations;gen++) {
		this->update_board();
	};
};

void board::update_board() {
	for (int row = 0;row < this->size_y;++row) {
		for (int col = 0;col < this->size_x;++col) {
			this->next_gol_board[row][col] = this->update_cell(row, col);
		};
	};

	//board switching
	bool** temp_board = this->gol_board;
	for (int i = 0;i < this->size_y;++i) {
		temp_board[i] = this->gol_board[i];
	};
	this->gol_board = this->next_gol_board;
	for (int i = 0;i < this->size_y;++i) {
		this->gol_board[i] = this->next_gol_board[i];
	};
	this->next_gol_board = temp_board;
	for (int i = 0;i < this->size_y;++i) {
		this->next_gol_board[i] = temp_board[i];
	};
	
};

bool board::update_cell(int row, int col) {
	//cout << row << "," << col << endl;
	int dead_counter = 0;
	int live_counter = 0;
	bool cell_status = this->gol_board[row][col];
	for (int y = row - 1; y < row + 1;++y) {
		for (int x = col - 1; x < col + 1;++x) {
			if ((x == row) && (y == col)) {
				continue;
			}
			else if (this->gol_board[y % this->size_y][x % this->size_x]) { //if true -> alive
				live_counter++;
			}
			else {
				dead_counter++;
			}
		};
	};
	//Rules
	if (!cell_status && (live_counter == 3)) return true;
	if (cell_status && ((live_counter == 2) || (live_counter == 3))) return true;
	if (cell_status && (live_counter < 2)) return false;
	if (cell_status && (live_counter > 3)) return false;


};


void board::write_to_file() {
	std::cout << "write" << std::endl;
};
