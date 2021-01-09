#include <stdio.h>
#include <stdlib.h>
#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

int  backsubst(Matrix *x, Matrix *A, Matrix *b) {

	int i, g, h;

	if(A->r != b->r || A->r != A->c) {
		return 2;
	}

	for(i = 0; i < A->r; i++) {	

		if(A->data[i][i] == 0) {
			return 1;
		}
	
	}

	x->data[b->r - 1][0] = b->data[b->r - 1][0] / A->data[A->r - 1][A->c - 1];

	for(g = 2; g <= b->r; g++) {

		double value = 0;

		for(h = A->c - g + 1; h < b->r; h++) {			

			value -= x->data[h][0] * A->data[A->c - g][h];

		}
		
		x->data[b->r - g][0] = (1/A->data[A->r - g][A->c - g]) * (b->data[b->r - g][0] + value);

	}

	return 0;
}


