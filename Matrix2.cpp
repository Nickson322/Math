#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Prototypes.h"


void main()
{
	setlocale (LC_ALL, "RUS");
	system("color F0");

	const double pi = 3.141592653589793238462643383279;
	double x, S = 0;
	
	//Создание объектов для записи в текстовые файлы
	std::ofstream file;
	file.open("Matrix_data.txt");
	if(!file.is_open())
	{
		std::cout << "Ошибка открытия файла" << std::endl;
		system("pause");
		return;
	}

	std::ofstream file2;
	file2.open("Sum_data.txt");
	if(!file2.is_open())
	{
		std::cout << "Ошибка открытия файла" << std::endl;
		system("pause");
		return;
	}
	
	// Меню программы
	for(;;)
	{
		std::cout << "Выберите какую функцию математического приложения" << std::endl;
		std::cout << "вы бы хотели использовать:" << std::endl;
		std::cout << "1 - Вычисление суммы бесконечного ряда" << std::endl;
		std::cout << "2 - Манипуляции со случайной матрицей" << std::endl;
		std::cout << "0 - Выход из программы" << std::endl;
		std::cout << "Номер команды:";
		int cmd;
		std::cin >> cmd;

		switch(cmd)
		{
			case 0:
				return;
			case 1:
				std::cout << "Вычисление суммы бесконечного ряда" << std::endl;
				file2 << "Вычисление суммы бесконечного ряда" << std::endl;
				std::cout << "Введите число х >>> ";
				file2 << "Введите число х >>> ";
				std::cin >> x;
				file2 << x << std::endl;
				int n;
				S = 4/pi * series(x, 0.000001, 1, &n);
				std::cout << "Сумма ряда S = "<< S << std::endl;
				file2 << "Сумма ряда S = "<< S << std::endl;
				std::cout << "Число слагаемых n = " << n << std::endl;
				file2 << "Число слагаемых n = " << n << std::endl;
				std::cout << std::endl;
				file2 << std::endl;
			break;
			case 2:
				unsigned short int N, i, j, x;
				int *A, *A_cpy, *buffer;

				std::cout << "Введите N: ";
				file << "Введите N: ";
				std::cin >> N;
				file << N;

				std::cout << "\n";
				file << "\n";

				// 2.Выделение памяти под матрицу
				A  = new int[2*N * 2*N];
				A_cpy  = new int[2*N * 2*N];
				buffer = new int[N * N];

				file << "Копия матрицы A:" << std::endl;


				matr_create(A, N);	// Создаём матрицу
				matr_copy(A, A_cpy, N); // Делаем копию матрицы

				// вводим оригинал матрицы в текстовый файл
				for(i = 0; i < 2*N; i++)
				{
					for (j = 0; j < 2*N; j++)
					{
						file << *(A_cpy+i*2*N+j) << "  ";
					}
					file << "\n";
				}

				file << "\n";
	
				for(;;)
				{
				std::cout << "Введите что вы хотите сделать с матрицей:" << std::endl;
				file << "Введите что вы хотите сделать с матрицей:" << std::endl;
				std::cout << "0 - для выхода из меню" << std::endl;
				file << "0 - для выхода из меню" << std::endl;
				std::cout << "1 - переставить блоки матрицы по часовой стрелке" << std::endl;
				file << "1 - переставить блоки матрицы по часовой стрелке" << std::endl;
				std::cout << "2 - переставить блоки матрицы крест-накрест" << std::endl;
				file << "2 - переставить блоки матрицы крест-накрест" << std::endl;
				std::cout << "Номер команды:";
				file << "Номер команды:";
				std::cin >> x; 
				file << x;
				std::cout << "\n";
				file << "\n";
				switch(x)
				{
					case 0:
						return;
					case 1:
						matr_clock(A_cpy, buffer, N);
						file << "\nМатрица с переставленными по часовой стрелке блоками:\n";
						for(i = 0;i < 2*N; i++)
						{   
							for(j = 0;j < 2*N; j++)
								file << *(A_cpy+i*2*N+j)<<"  ";
							file << "\n";
						}
					break;
					case 2:
						matr_cross(A_cpy, buffer, N);
						file << "\nМатрица с переставленными крест-накрест блоками:\n";
						for(i = 0;i < 2*N; i++)
						{   
							for(j = 0;j < 2*N; j++)
								   file << *(A_cpy+i*2*N+j)<<"  ";
							file << "\n";
						}
					}
				}

				file << "\n";

				//Очищаем память
				delete []A;
				delete []A_cpy;
				delete []buffer;

				// Закрываем текстовый файл
				
		}
	}

	file.close();
	file2.close();

	system("pause");
 }