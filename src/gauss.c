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
  	//double tmp, tmp2;

//	for (int i = 0; i < mat -> c; i++)
//	{
//		if (mat -> data[i][i] == 0)
//			return 1;
//	}

	for (int h = 0; h < ((mat -> c) - 1); h++)
	{
		el_gl = h;//labs(mat -> data[h][h]);
		//printf ("[%f]\n", el_gl);
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
		
	//	printf("[%f] - wiersz %d ", el_gl, tmp_r);
		
		/*for (int j = h; j < mat -> c; j++)
		{
			tmp = mat -> data[h][j];
			mat -> data[h][j] = mat -> data[tmp_r][j];
			mat -> data[tmp_r][j] = tmp;
		}
		tmp2 = b -> data[h][0];
	 	b -> data[h][0] = b -> data[tmp_r][0];
		b -> data[tmp_r][0] = tmp2;
		*/
		
		
			for (int j = h + 1; j < mat -> c; j++)
			{
				double skalar = mat -> data[j][h] / mat -> data[h][h];
		//		printf("[%f]\n",skalar);
				for (int i = h; i < mat -> c; i++)
				{
					mat -> data[j][i] -= mat -> data [h][i] * skalar;
				}
				b -> data[j][0] -= b -> data[h][0] * skalar;
			}
		
		
	}




	/*for (int h = 0; h < (mat -> r) - 1; h++)
	{
		int z = tmp_r2[h];
		for (int i = 0; i < mat -> c; i++)
		{
			tmp = (mat -> data[h][i]);
			(mat -> data[h][i]) = (mat -> data[z][i]);
		//	mat -> data[z][i] = tmp;
		}
	}*/



	for (int h = 0; h < mat -> r; h++)
	{
		//el_gl = mat -> data[h][h];

		for (int i = h + 1; i < mat -> r; i++) 
		{
			/*for (z = i - 1; z < mat -> r; z++) //( mat -> data[z][h] > mat -> data[h][h]  )
			{

				if (mat -> data[z+1][h] > el_gl)
				{
					el_gl = mat -> data[z][h];
					tmp_r = z;
				}
				//printf("[%d] [%f]", tmp_r, el_gl);
			}
			for (int k = 0; k < mat -> c; k++)
			{
					tmp = mat -> data[i-1][k];
					mat -> data[i-1][k] = mat -> data[z][k];
					mat -> data[z][k] = tmp;
			}

			*/	
			//printf("[%f] - linia %d", el_gl, tmp_r);
			double skalar = mat ->data[i][h] / mat -> data[h][h];
			for (int j = 0; j < mat -> c; j++)
			{
				//mat -> data[i][j] -= mat -> data [h][j] * skalar; 
			}
			//b -> data[i][0] -= b -> data[h][0] * skalar;

		}
	}	



		return 0;
}

