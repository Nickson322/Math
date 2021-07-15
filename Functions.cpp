#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Prototypes.h"

const double pi = 3.141592653589793238462643383279;
unsigned short int i, j;


// �������, ��������� �������
void matr_create(int* matrix, int N)
 {
	for(i = 0; i < 2*N; i++)
		for (j = 0; j < 2*N; j++)
			*(matrix+i*2*N+j) = rand() % 10;
 }

// �������, ���������� �������
void matr_copy(int* matrix, int* matrix_cpy, int N)
{
	for(i = 0; i < 2*N; i++)
		for (j = 0; j < 2*N; j++)
			*(matrix_cpy+i*2*N+j) = *(matrix+i*2*N+j);
 }

// �������, �������������� ����� ������� ��������
// N*N �� ������� �������
void matr_clock(int* A, int* buffer, int N)
{
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			*(buffer+i*N+j) = *(A+i*2*N+j);						//  ������� � ����� ��-� ����� 1
			*(A+i*2*N+j) = *(A+i*2*N+j + 2*N*N);				//  ������� � ���� 1 ��-� ����� 4
			*(A+i*2*N+j + 2*N*N) = *(A+i*2*N+j + (2*N+1)*N);	//  ������� � ���� 4 ��-� ����� 3
			*(A+i*2*N+j + (2*N+1)*N) = *(A+i*2*N+j+N);			//	������� � ���� 3 ��-� ����� 2
			*(A+i*2*N+j+N) = *(buffer+i*N+j);					//  �� ������ ������� ��-� � ���� 2
		}
	}
}

// �������, �������������� ����� ������� ��������
// N*N �����-�������
void matr_cross(int* A, int* buffer, int N)
{
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			*(buffer+i*N+j) = *(A+i*2*N+j);						// ������������ ��-� ����� �1 � �����
			*(A+i*2*N+j) = *(A+i*2*N+j + (2*N+1)*N);			// ������������ ��-� ����� �3 � ���� �1
			*(A+i*2*N+j + (2*N+1)*N) = *(buffer+i*N+j);			// ������������ ��-� ������ � ���� �3
			*(buffer+i*N+j) = *(A+i*2*N+j+N);					// ������������ ��-� ����� �2 � �����
			*(A+i*2*N+j+N) = *(A+i*2*N+j + 2*N*N);				// ������������ ��-� ����� �4 � ���� �2
			*(A+i*2*N+j + 2*N*N) = *(buffer+i*N+j);				// ������������ ��-� ������ � ���� �4
		}
	}
}

// �������
double Term(double x, int n)
{
	return pow(-1, n + 1) / (x*x - n * n*pi*pi);
}

//������� ���������� ����� �����
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