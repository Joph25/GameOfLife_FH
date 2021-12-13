#pragma once
class board {
private:
	int size_x;
	int size_y;
public:
	void read_params_from_cmdline();
	void compute_GOL();
	void write_to_file();

};
