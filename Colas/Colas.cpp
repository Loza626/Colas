#include <iostream>

using namespace std;
double AreaTriangulo(double* altura, double* base) {
	return ((*base) * (*altura) / 2);
};
struct  Nodo
{
	int valor;
	Nodo* siguiente;
	Nodo* anterior;
};

struct Nodo* lista = NULL;
void insertar(int n) {

	struct  Nodo* nuevonodo = new Nodo();

	if (nuevonodo != NULL)
	{

		nuevonodo->valor = n;
		nuevonodo->siguiente = NULL;
		nuevonodo->anterior = NULL;

		if (lista == NULL)
		{
			lista = nuevonodo;
		}
		else 
		{

			nuevonodo->siguiente = lista;
			lista->anterior = nuevonodo;
			lista = nuevonodo;

		}
	}
	else {
		cout << "No se pueden agrgar mas listas \n";
	}
}

Nodo* EliminarInicio() {
	struct  Nodo* temporal = lista;
	if (lista != NULL) {
		if (temporal->siguiente != NULL) {
			delete temporal;
			lista->anterior = NULL;
		}
		else {
			delete lista;
			lista = NULL;
		}
	}
	else {
		cout << "Lista vacia";
	}
	return lista;
}

Nodo* EliminarFinal() {
	struct  Nodo* temporal = lista;
	struct  Nodo* temporal2 = lista;

	if (lista != NULL) {
		if (lista->siguiente != NULL) {
			while (temporal->siguiente != NULL)
			{
				temporal = temporal->siguiente;
			}

			temporal2 = temporal->siguiente;
			delete temporal2;
		}
	}

	return lista;
}

void Imprimir() {
	struct Nodo* temporal = lista;
	if (temporal != NULL) {
		while (temporal != NULL)
		{
			cout << "Lista " << temporal->valor << " Direccion " << temporal << " Dir siguiente " << temporal->siguiente << " Dir anterior " << temporal->anterior << endl;
			temporal = temporal->siguiente;
		}
	}
	else {
		cout << "Lista vacia";
	}
}

int main()
{
	insertar(1);
	insertar(2);
	insertar(3);
	Imprimir();
}


