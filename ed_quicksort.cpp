// Estruturas de dados.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void troca(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}
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
int particiona(int* vetor, int p, int r)
{
	int x = vetor[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (vetor[j] <= x)
		{
			i = i + 1;
			troca(vetor[i], vetor[j]);
		}
	}
	troca(vetor[i + 1], vetor[r]);
	return i + 1;
}
void quicksort(int* vetor, int p, int r)
{
	if (p < r)
	{
		int q = particiona(vetor, p, r);
		quicksort(vetor, p, q - 1);
		quicksort(vetor, q + 1, r);
	}
}
/* Driver code */
int main()
{
	srand(time(NULL));
	int n;
	cout << "Informe a quantidade de elementos de um vetor: ";
	cin >> n;
	int* vetor = new int[n];
	createArray(vetor, n);
	printArray(vetor, n);
	quicksort(vetor, 0, n - 1);
	printArray(vetor, n);
	delete[] vetor;
	return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
