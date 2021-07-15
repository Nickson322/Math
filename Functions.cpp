#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Prototypes.h"

const double pi = 3.141592653589793238462643383279;
unsigned short int i, j;


// функция, создающая матрицу
void matr_create(int* matrix, int N)
 {
	for(i = 0; i < 2*N; i++)
		for (j = 0; j < 2*N; j++)
			*(matrix+i*2*N+j) = rand() % 10;
 }

// функция, копирующая матрицу
void matr_copy(int* matrix, int* matrix_cpy, int N)
{
	for(i = 0; i < 2*N; i++)
		for (j = 0; j < 2*N; j++)
			*(matrix_cpy+i*2*N+j) = *(matrix+i*2*N+j);
 }

// функция, переставляющая блоки матрицы размером
// N*N по часовой стрелке
void matr_clock(int* A, int* buffer, int N)
{
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			*(buffer+i*N+j) = *(A+i*2*N+j);						//  заносим в буфер эл-т блока 1
			*(A+i*2*N+j) = *(A+i*2*N+j + 2*N*N);				//  заносим в блок 1 эл-т блока 4
			*(A+i*2*N+j + 2*N*N) = *(A+i*2*N+j + (2*N+1)*N);	//  заносим в блок 4 эл-т блока 3
			*(A+i*2*N+j + (2*N+1)*N) = *(A+i*2*N+j+N);			//	заносим в блок 3 эл-т блока 2
			*(A+i*2*N+j+N) = *(buffer+i*N+j);					//  из буфера заносим эл-т в блок 2
		}
	}
}

// функция, переставляющая блоки матрицы размером
// N*N крест-накрест
void matr_cross(int* A, int* buffer, int N)
{
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			*(buffer+i*N+j) = *(A+i*2*N+j);						// переставляем эл-т блока №1 в буфер
			*(A+i*2*N+j) = *(A+i*2*N+j + (2*N+1)*N);			// переставляем эл-т блока №3 в блок №1
			*(A+i*2*N+j + (2*N+1)*N) = *(buffer+i*N+j);			// переставляем эл-т буфера в блок №3
			*(buffer+i*N+j) = *(A+i*2*N+j+N);					// переставляем эл-т блока №2 в буфер
			*(A+i*2*N+j+N) = *(A+i*2*N+j + 2*N*N);				// переставляем эл-т блока №4 в блок №2
			*(A+i*2*N+j + 2*N*N) = *(buffer+i*N+j);				// переставляем эл-т буфера в блок №4
		}
	}
}

// Формула
double Term(double x, int n)
{
	return pow(-1, n + 1) / (x*x - n * n*pi*pi);
}

//функция вычисления суммы рядов
double series(double x, double eps, int n0, int* n_max)
{
	double S = 0, dS;
	int n = n0;

	do
	{
		dS = Term(x, n);
		S += dS;
		n++;
	}while(fabs(dS) > eps);

	*n_max = n;
	return S;
}