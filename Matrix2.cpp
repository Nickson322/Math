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
	
	//�������� �������� ��� ������ � ��������� �����
	std::ofstream file;
	file.open("Matrix_data.txt");
	if(!file.is_open())
	{
		std::cout << "������ �������� �����" << std::endl;
		system("pause");
		return;
	}

	std::ofstream file2;
	file2.open("Sum_data.txt");
	if(!file2.is_open())
	{
		std::cout << "������ �������� �����" << std::endl;
		system("pause");
		return;
	}
	
	// ���� ���������
	for(;;)
	{
		std::cout << "�������� ����� ������� ��������������� ����������" << std::endl;
		std::cout << "�� �� ������ ������������:" << std::endl;
		std::cout << "1 - ���������� ����� ������������ ����" << std::endl;
		std::cout << "2 - ����������� �� ��������� ��������" << std::endl;
		std::cout << "0 - ����� �� ���������" << std::endl;
		std::cout << "����� �������:";
		int cmd;
		std::cin >> cmd;

		switch(cmd)
		{
			case 0:
				return;
			case 1:
				std::cout << "���������� ����� ������������ ����" << std::endl;
				file2 << "���������� ����� ������������ ����" << std::endl;
				std::cout << "������� ����� � >>> ";
				file2 << "������� ����� � >>> ";
				std::cin >> x;
				file2 << x << std::endl;
				int n;
				S = 4/pi * series(x, 0.000001, 1, &n);
				std::cout << "����� ���� S = "<< S << std::endl;
				file2 << "����� ���� S = "<< S << std::endl;
				std::cout << "����� ��������� n = " << n << std::endl;
				file2 << "����� ��������� n = " << n << std::endl;
				std::cout << std::endl;
				file2 << std::endl;
			break;
			case 2:
				unsigned short int N, i, j, x;
				int *A, *A_cpy, *buffer;

				std::cout << "������� N: ";
				file << "������� N: ";
				std::cin >> N;
				file << N;

				std::cout << "\n";
				file << "\n";

				// 2.��������� ������ ��� �������
				A  = new int[2*N * 2*N];
				A_cpy  = new int[2*N * 2*N];
				buffer = new int[N * N];

				file << "����� ������� A:" << std::endl;


				matr_create(A, N);	// ������ �������
				matr_copy(A, A_cpy, N); // ������ ����� �������

				// ������ �������� ������� � ��������� ����
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
				std::cout << "������� ��� �� ������ ������� � ��������:" << std::endl;
				file << "������� ��� �� ������ ������� � ��������:" << std::endl;
				std::cout << "0 - ��� ������ �� ����" << std::endl;
				file << "0 - ��� ������ �� ����" << std::endl;
				std::cout << "1 - ����������� ����� ������� �� ������� �������" << std::endl;
				file << "1 - ����������� ����� ������� �� ������� �������" << std::endl;
				std::cout << "2 - ����������� ����� ������� �����-�������" << std::endl;
				file << "2 - ����������� ����� ������� �����-�������" << std::endl;
				std::cout << "����� �������:";
				file << "����� �������:";
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
						file << "\n������� � ��������������� �� ������� ������� �������:\n";
						for(i = 0;i < 2*N; i++)
						{   
							for(j = 0;j < 2*N; j++)
								file << *(A_cpy+i*2*N+j)<<"  ";
							file << "\n";
						}
					break;
					case 2:
						matr_cross(A_cpy, buffer, N);
						file << "\n������� � ��������������� �����-������� �������:\n";
						for(i = 0;i < 2*N; i++)
						{   
							for(j = 0;j < 2*N; j++)
								   file << *(A_cpy+i*2*N+j)<<"  ";
							file << "\n";
						}
					}
				}

				file << "\n";

				//������� ������
				delete []A;
				delete []A_cpy;
				delete []buffer;

				// ��������� ��������� ����
				
		}
	}

	file.close();
	file2.close();

	system("pause");
 }