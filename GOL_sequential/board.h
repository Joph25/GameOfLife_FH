#pragma once
#include <vector>
#include <string>

class board {
private:
	int size_x;
	int size_y;
	std::vector<std::vector<bool>> gol_board;
	void read_board_from_file(const char*);
public:
	void read_params_from_cmdline();
	void compute_GOL();
	void write_to_file();

};
