#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) 
{
	int tmp_r, el_gl;

	for (int i = 0; i < mat -> c; i++)
	{
		if (mat -> data[i][i] == 0)
			return 1;
	}

	for (int h = 0; h < ((mat -> c) - 1); h++)
	{
		el_gl = h;
		
		for (int i = h + 1; i < mat -> r; i++)
		{
			if (fabs(mat -> data[i][h]) > fabs(mat -> data[el_gl][h]))
			{
				el_gl = i;
			}
		}
			if (el_gl != h)
			{
				double tmp;
				for(int q = h; q < mat ->r; q++)
				{
					tmp = mat -> data[h][q];
					mat -> data[h][q] = mat -> data[el_gl][q];
					mat -> data[el_gl][q] = tmp;
				}
				tmp = b -> data[h][0];
				b -> data[h][0] = b -> data[el_gl][0];
				b -> data[el_gl][0] = tmp;
			}

			for (int j = h + 1; j < mat -> c; j++)
			{
				double skalar = mat -> data[j][h] / mat -> data[h][h];
				
				for (int i = h; i < mat -> c; i++)
				{
					mat -> data[j][i] -= mat -> data [h][i] * skalar;
				}
			
				b -> data[j][0] -= b -> data[h][0] * skalar;
			}	
	}	
	return 0;
}

