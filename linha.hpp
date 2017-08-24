#ifndef LINHA_HPP
#define LINHA_HPP

using namespace std;

class Linha{
	private:
		char cell[20][20];
	public:
		Linha();
		~Linha();
		char getCell(int i, int j);
		void setCell(char cell, int i, int j);
		
};

#endif
