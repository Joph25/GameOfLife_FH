#pragma once
#include <vector>
#include <string>
using namespace std;

class board {
private:
	int size_x;
	int size_y;
	int generations;
	bool **gol_board;
	bool **next_gol_board;
	string output_file;
	string input_file;
	bool measure_flag;
	void read_board_from_file();
	void update_board();
	bool update_cell(int,int);
public:
	void read_params_from_cmdline(int, char**);
	void compute_GOL();
	void write_to_file();
	void print_board_binary();
	void print_board_like_input();
};
