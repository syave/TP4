#include "archivos.h"
#include "Pelicula.h"

void cargarDesdeArchivo(std::string nombreArchivo, Lista<Pelicula> &lista) {
	ifstream archivo(nombreArchivo);
	string linea;

	if (!archivo.fail()) {

		while (archivo >> linea) {
			Pelicula p;
			Lista<string> *actoresAuxiliares = new Lista<string>;
			p.setNombre(linea);

			archivo >> linea;
			p.setGenero(linea);

			archivo >> linea;
			p.setPuntaje(linea);

			archivo >> linea;
			p.setDirector(linea);

			archivo >> linea;
			actoresAuxiliares->agregar(linea);

			while(archivo.peek()!='\n'){
				archivo >> linea;
				actoresAuxiliares->agregar(linea);
			}

			p.setActores(actoresAuxiliares);
			lista.agregar(p);
		}

		archivo.close();
	}
}
