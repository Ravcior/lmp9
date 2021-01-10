#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) 
{
  
	for (int i = 0; i < mat -> c; i++)
	{
		if (mat -> data[i][i] == 0)
			return 1;
	}
	for (int h = 0; h < mat -> r; h++)
	{
		for (int i = h + 1; i < mat -> r; i++) 
		{
			
			if ( mat -> data[i][h] == 0)
			{
				break;
			}	
		
			double skalar = mat ->data[h][h] / mat -> data[i][h];
			for (int j = 0; j < mat -> c; j++)
			{
				mat -> data[i][j] *= skalar;
				mat -> data[i][j] -= mat -> data [h][j]; 
			}
			b -> data[i][0] *= skalar;
			b -> data[i][0] -= b -> data[h][0];

		}
	}	



		return 0;
}

