#pragma once
#include <vector>
#include <string>

class board {
private:
	int size_x;
	int size_y;
	int generations;
	bool **gol_board;
	bool **next_gol_board;
	const char* output_file;
	char* input_file;
	void read_board_from_file(const char*);
	void update_board();
	bool update_cell(int,int);
public:
	void read_params_from_cmdline();
	void compute_GOL();
	void write_to_file();
	void print_board_binary();
	void print_board_like_input();
};
