#include <iostream>
using namespace std;

struct nodo
{
	int dato;
	nodo *sig;
};
typedef nodo *pnodo;

pnodo pL;

void insertar(int x)
{
	pnodo p;
	p = new nodo; // pedir espacio de memoria para un nodo
	p->dato = x;
	p->sig = pL;
	pL = p;
}
void imprimir()
{
	pnodo p;
	p = pL;
	cout << "pL-> ";
	while (p != NULL)
	{
		cout << p->dato << "-> ";
		p = p->sig;
	}
	cout << "NULL" << endl;
}

pnodo buscar(int x)
{
	pnodo p;

	if (pL == NULL)
		return NULL;
	else
	{
		p = pL;

		while (p != NULL && (*p).dato != x)
			p = (*p).sig;

		return p;
	}
}

pnodo buscaranterior(int x)
{
	pnodo a, p;
	a = NULL;
	p = pL;
	while ((*p).dato != x)
	{
		a = p;
		p = (*p).sig;
	}
	return a;
}

void eliminar(int x)
{
	pnodo a, p;
	p = buscar(x);
	if (p == NULL)
		cout << "El elemento " << x << " no se encuentra en la lista." << endl;
	else
	{
		a = buscaranterior(x);
		if (a == NULL)
			pL = (*p).sig;
		else
			(*a).sig = (*p).sig;

		delete p;
		cout << "El elemento " << x << " se encontraba en la lista y se procedio a eliminarlo." << endl;
		cout << "La lista actualizada es la siguiente: " << endl;
		imprimir();
	}
}

int main()
{
	pL = NULL;

	insertar(4);
	insertar(3);
	insertar(1);

	cout << "La lista original es la siguiente: " << endl;
	imprimir();

	// BUSCAR
	int numero = 4; // NUMERO A BUSCAR EN LA LISTA
	pnodo nodoBuscado = buscar(numero);
	if (nodoBuscado == NULL)
		cout << "No se encontro el elemento " << numero << " en la lista" << endl;
	else
		cout << "Se encontro el elemento " << nodoBuscado->dato
			 << " con direccion " << nodoBuscado << endl;

	// ELIMINAR
	eliminar(3);

	return 0;
}
