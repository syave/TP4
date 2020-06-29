#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {
    private:
        T dato;
        Nodo<T>* siguiente;

    public:

        Nodo(T dato) {
            this->dato = dato;
            this->siguiente = 0;
        }

        T obtenerDato() {
            return this->dato;
        }

        void cambiarDato(T nuevoDato) {
            this->dato = nuevoDato;
        }

        Nodo<T>* obtenerSiguiente() {
            return this->siguiente;
        }
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

            this->siguiente = nuevoSiguiente;
        }
};

#endif /* NODO_H_ */
