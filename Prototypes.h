#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

// функци€, создающа€ матрицу
void matr_create(int* matrix, int N);
// функци€, копирующа€ матрицу
void matr_copy(int* matrix, int* matrix_cpy, int N);
// функци€, переставл€юща€ блоки матрицы размером
// N*N по часовой стрелке
void matr_clock(int* A, int* buffer, int N);
// функци€, переставл€юща€ блоки матрицы размером
// N*N крест-накрест
void matr_cross(int* A, int* buffer, int N);


double Term(double x, int n);

// дл€ вычислени€ суммы р€дов
double series(double x, double eps, int n0, int* n_max);

#endif