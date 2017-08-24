#include <iostream>
include "matriz.hpp"

using namespace std;

int main(int argc, char ** argv) {
	Linha linha1;
	int i, j;

	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			cout << linha1.getElemento(i, j);
		}

		cout << endl;
	}
	
	return 0;
}
