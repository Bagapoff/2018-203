#include "scherbakovdv.h"

/**
 * Введение в дисциплину
 */
void scherbakovdv::lab1()
{
	lab2();
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void scherbakovdv::lab2()
{
	//A[i][i] - матрица, b[i] - столбец свободных членов
	for (int i = 0; i < N; i++)
		{
			if (!A[i][i])
			{
				double* MaxRow = A[i];
				for (int j = i + 1; j < N; j++)
					if (A[j][i] > MaxRow[i])
					{
						double* tmp = MaxRow;
						MaxRow = A[j];
						A[j] = tmp;
					}
				if (!MaxRow[i])
					return;
			}
			for (int j = N - 1; j > i; j--)
			{
				A[i][j] /= A[i][i];
				for (int k = i + 1; k < N; k++)
					A[k][j] -= A[k][i] * A[i][j];
			}
			b[i] /= A[i][i];
			A[i][i] = 1;
			for (int j = N - 1; j > i; j--)
			{
				b[j] -= b[i] * A[j][i];
				A[j][i] = 0;
			}
		}
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				b[j] -= b[i] * A[j][i];
				A[j][i] = 0;
			}
		}
		memcpy(x,b,sizeof(double)*N);
}



/**
 * Метод прогонки
 */
void scherbakovdv::lab3()
{
	double *al = new double[N], *bt = new double[N];
	//Прямой ход
	al[0] = -A[0][1]/A[0][0];
	bt[0] = b[0]/A[0][0];
	for (int i=1;i<N-1;i++){
		al[i] = -A[i][i+1]/(A[i][i] + A[i][i-1]*al[i-1]);
		bt[i] = (b[i] - A[i][i-1]*bt[i-1])/(A[i][i] + A[i][i-1]*al[i-1]);
	}
	x[N-1] = (b[N-1]-A[N-1][N-2]*bt[N-1])/(A[N-1][N-1]+A[N-1][N-2]*al[N-2]);
	//Обратный ход
	for (int i=N-2;i!=-1;i--)
		x[i] = al[i]*x[i+1]+bt[i];
}



/**
 * Метод простых итераций
 */
void scherbakovdv::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void scherbakovdv::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void scherbakovdv::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void scherbakovdv::lab7()
{

}


void scherbakovdv::lab8()
{

}

void scherbakovdv::lab9() {}


std::string scherbakovdv::get_name()
{
  return "Scherbakov D.V.";
}
