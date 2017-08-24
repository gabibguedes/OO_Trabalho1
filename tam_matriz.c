#include <stdio.h>
int main(){
	int m[100][100], tamanho, i, j;

	printf("Tamanho da Matriz quadrada: ");
	scanf("%d", &tamanho);

	for(i=0; i<tamanho; i++){
		for(j=0; j<tamanho; j++){
			m[i][j] = 0;
			printf("%d ", m[i][j]);
		}
		printf("\n");

	}

	return 0;
}
