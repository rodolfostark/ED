#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void createArray(int* vetor, int n)
{
	for (int i = 0; i < n; i++)
	{
		vetor[i] = rand() % 101 + 1;
	}
}

void printArray(int * vetor, int n)
{
	for (int i = 0; i < n; i++)
		cout << vetor[i] << " ";
	cout << endl;
}

void merge(int* vetor, int p, int q, int r)
{
	int n1 = q - p + 1, n2 = r - q;

	int* L = new int[n1+1];
	int* R = new int[n2+1];

	for (int i = 0; i < n1; i++)
	{
		L[i] = vetor[p + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = vetor[q + j + 1];
	}
	
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0, j = 0;

	for (int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			vetor[k] = L[i];
			i = i + 1;
		}
		else
		{
			vetor[k] = R[j];
			j = j + 1;
		}
	}
}

void mergesort(int* vetor, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergesort(vetor, p, q);
		mergesort(vetor, q + 1, r);
		merge(vetor, p, q, r);
	}
}

int main()
{
	srand(time(NULL));
	int n;
	cout << "Informe a quantidade de elementos de um vetor: ";
	cin >> n;
	int* vetor = new int[n];
	createArray(vetor, n);
	printArray(vetor, n);
	mergesort(vetor, 0, n - 1);
	printArray(vetor, n);
	delete[] vetor;
	return 0;
}
