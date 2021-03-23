// 205.cpp: определяет точку входа для консольного приложения.
// Сосчитать число различных элементов в массиве

#include "stdafx.h"
#include <string>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// First commit to my branch

	//Ввод массива
	int M;
	int N;
	printf("Please enter the number N: ");
	scanf("%i", &N);
	printf("Please enter the number of elements of the array: ");
	scanf("%i", &M);
	printf("Please enter the elements of the array: \n");
	int *A = (int *)calloc(M, sizeof(int));
	for (int i = 0; i < M; i++) 
	{
		scanf("%i", A+i);
	}
	printf("Here is array you have entered: ");
	for (int u = 0; u < M; u++) 
	{
		if (u != M - 1) printf("%i, ", A[u]);
		else printf("%i", A[u]);
	}
	int *diffValues = (int *)calloc(M, sizeof(int)); //Массив, содержащий различные значения
	//Сравниваем каждый элемент исходного массива с каждым элементом массива diffValues
	int index = 0;
	for (int i = 0; i < M; i++) 
	{ 
		bool compare = true;
		for (int k = 0; k <= index; k++) 
		{
			if (A[i] != diffValues[k] && compare) compare = true;
			else compare = false;
		}
		if (compare) 
		{
			diffValues[index] = A[i];
			index++;
		}
	}
	//Проверяем, содержится ли число N в массиве
	bool contain = false;
	for (int c = 0; c < M; c++) 
	{
		if (A[c] == N) contain = true;
	}
	printf("\nThe number of different elements in the array: %i\n", index);
	if (contain) printf("Array contains the number N!");
	else printf("Array doesn't contain the number N!");
	free(A);
	free(diffValues);
	getch();
	return 0;
}

