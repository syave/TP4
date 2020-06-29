#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"
#include <iostream>
using namespace std;

template<class T>
class Lista {

private:

	Nodo<T> *primero;
	unsigned int tamanio;

public:

	Lista();

	unsigned int getTamanio();
	void agregar(T elemento);
	T obtener(unsigned int posicion);
	void remover(unsigned int posicion);
	~Lista();

private:

	void agregar(T elemento, unsigned int posicion);
	Nodo<T>* obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T>
Lista<T>::Lista() {
	this->primero = 0;
	this->tamanio = 0;
}

template<class T>
unsigned int Lista<T>::getTamanio() {
	return this->tamanio;
}

template<class T>
void Lista<T>::agregar(T elemento) {
	this->agregar(elemento, this->tamanio + 1);
}

template<class T>
void Lista<T>::agregar(T elemento, unsigned int posicion) {

	if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

		Nodo<T> *nuevo = new Nodo<T>(elemento);

		if (posicion == 1) {

			nuevo->cambiarSiguiente(this->primero);
			this->primero = nuevo;

		} else {

			Nodo<T> *anterior = this->obtenerNodo(posicion - 1);
			nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
			anterior->cambiarSiguiente(nuevo);
		}

		this->tamanio++;
	}

}

template<class T>
T Lista<T>::obtener(unsigned int posicion) {

	T elemento;

	if ((posicion > 0) && (posicion <= this->tamanio)) {

		elemento = this->obtenerNodo(posicion)->obtenerDato();
	}

	return elemento;
}

template<class T>
void Lista<T>::remover(unsigned int posicion) {

	if ((posicion > 0) && (posicion <= this->tamanio)) {

		Nodo<T> *removido;

		if (posicion == 1) {

			removido = this->primero;
			this->primero = removido->obtenerSiguiente();

		} else {

			Nodo<T> *anterior = this->obtenerNodo(posicion - 1);
			removido = anterior->obtenerSiguiente();
			anterior->cambiarSiguiente(removido->obtenerSiguiente());
		}

		delete removido;
		this->tamanio--;
	}
}

template<class T>
Lista<T>::~Lista() {

	while (this->primero != NULL) {

		Nodo<T> *aBorrar = this->primero;
		this->primero = this->primero->obtenerSiguiente();

		delete aBorrar;
	}
}

template<class T>
Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

	Nodo<T> *actual = this->primero;
	for (unsigned int i = 1; i < posicion; i++) {

		actual = actual->obtenerSiguiente();
	}

	return actual;
}

#endif /* LISTA_H_ */
