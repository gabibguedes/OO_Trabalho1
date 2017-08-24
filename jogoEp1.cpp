#include <iostream>
#include "linha.hpp"
#include "matriz.hpp"

void bordaH(int g){
	int l;

	cout << endl << "GERAÇÃO "<< g << endl;

	cout << "   ";
	for (l = 0; l < 20; l++) {
		if (l< 9) {
			cout << (l+1) << "  ";
		}else{
			cout << (l+1) << " ";
		}
	}
	cout << endl;
}
void bordaV(int i) {
	if (i < 9) {
		cout << (i+1) << "  ";
	}else{
		cout << (i+1) << " ";
	}
}

int quantVivas(char memoria[20][20], int i, int j){
	int vivas = 0;
	if (memoria[i-1][j-1] == '*'){
		vivas++;
	}
	if (memoria[i-1][j] == '*'){
		vivas++;
	}
	if (memoria[i-1][j+1] == '*'){
		vivas++;
	}

	if (memoria[i][j-1] == '*'){
		vivas++;
	}
	if (memoria[i][j+1] == '*'){
		vivas++;
	}

	if (memoria[i+1][j-1] == '*'){
		vivas++;
	}
	if (memoria[i+1][j] == '*'){
		vivas++;
	}
	if (memoria[i+1][j+1] == '*'){
		vivas++;
	}

	return vivas;
}

int main(int argc, char ** argv) {
	Linha l1;
	int i, j, g = 0, p, l, vivas;
	char memoria[20][20], hab[20][20];


// Print da l1 antes de entrar no while
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			cout << l1.getCell(i,j) << " ";
			memoria[i][j] = l1.getCell(i,j);
			hab[i][j] = l1.getCell(i,j);
		}
		cout << endl;
	}

//Começa o loop que da a vida
	while (g < 10) {
		g++;
		bordaH(g);

//Começando a ler a matriz
		for(i = 0; i < 20; i++){
			bordaV(i);

//Entra no 2o for para efetuar a real leitura dos elementos
			for(j = 0; j < 20; j++){

				cout << hab[i][j] << "  ";

				if (i > 0 && i < 19 && j > 0 && j < 19) {

					quantVivas(memoria, i,j);

					if (memoria[i][j] == '*' && (vivas < 2 || vivas > 3)) {
						hab[i][j] = '-';
					}else if(memoria[i][j] == '-' && vivas == 3){
						hab[i][j] = '*';
					}else if(memoria[i][j] == '*' && (vivas == 2 || vivas == 3)){
						hab[i][j] = '*';
					}
				}
			}
			cout << endl;

			for (p = 0; p < 20; p++) {
				for (l = 0; l < 20; l++) {
					memoria[i][j] = hab[i][j] ;
				}
			}
		}
	}

	return 0;
}
