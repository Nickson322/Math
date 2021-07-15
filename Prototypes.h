#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

// �������, ��������� �������
void matr_create(int* matrix, int N);
// �������, ���������� �������
void matr_copy(int* matrix, int* matrix_cpy, int N);
// �������, �������������� ����� ������� ��������
// N*N �� ������� �������
void matr_clock(int* A, int* buffer, int N);
// �������, �������������� ����� ������� ��������
// N*N �����-�������
void matr_cross(int* A, int* buffer, int N);


double Term(double x, int n);

// ��� ���������� ����� �����
double series(double x, double eps, int n0, int* n_max);

#endif