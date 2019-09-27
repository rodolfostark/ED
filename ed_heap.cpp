#include <iostream>
#define MAX 100
using namespace std;

void troca(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}

class HeapMax 
{
public:
	int heap[MAX];
	int quantidade_de_elementos = 0;
	void inserir(int novo_elemento)
	{
		if (quantidade_de_elementos < MAX)
		{
			quantidade_de_elementos = quantidade_de_elementos + 1;
			heap[quantidade_de_elementos - 1] = novo_elemento;
			subir(quantidade_de_elementos);
		}
		else
		{
			cout << "Heap cheia." << endl;
		}
		arranjar();

	}
	void remover()
	{
		if (quantidade_de_elementos > 0)
		{
			int elemento = heap[0];
			heap[0] = heap[quantidade_de_elementos - 1];
			quantidade_de_elementos = quantidade_de_elementos - 1;
			descer(1, quantidade_de_elementos);
		}
		else
		{
			cout << "Heap vazia." << endl;
		}
	}
	void imprimir()
	{
		cout << "Heap [ ";
		for (int i = 0; i < quantidade_de_elementos; i++)
		{
			cout << heap[i] << " ";
		}
		cout << "]" << endl;
	}
private:
	void descer(int posicao_do_elemento, int quantidade_de_elementos)
	{
		int j = 2 * posicao_do_elemento - 1;
		
		if (j <= quantidade_de_elementos - 1)
		{
			if (j < quantidade_de_elementos - 1)
			{
				if (heap[j + 1] > heap[j])
				{
					j = j + 1;
				}
			}
			if (heap[posicao_do_elemento] < heap[j])
			{
				troca(heap[posicao_do_elemento], heap[j]);
				descer(j, quantidade_de_elementos);
			}
		}
	}
	void subir(int posicao_do_elemento)
	{
		int j = floor(posicao_do_elemento / 2);

		if (j >= 1)
		{
			if (heap[posicao_do_elemento] > heap[j])
			{
				troca(heap[posicao_do_elemento], heap[j]);
				subir(j);
			}
		}
	}
	void arranjar()
	{
		for (int j = floor(quantidade_de_elementos / 2); j >= 0; j++)
		{
			descer(heap[j], quantidade_de_elementos);
		}
	}
};



int main()
{
	HeapMax lista;
	lista.inserir(14);
	lista.inserir(10);
	lista.inserir(9);
	lista.inserir(3);
	lista.inserir(2);
	lista.inserir(16);
	lista.imprimir();
	return 0;
}