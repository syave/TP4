#include "CargadorDeArchivos.h"

CargadorDeArchivos::CargadorDeArchivos() {
	listaPeliculasVistas = 0;
	listaPeliculasNoVistas = 0;
}

CargadorDeArchivos::~CargadorDeArchivos() {
	delete listaPeliculasVistas;
	delete listaPeliculasNoVistas;
}

void CargadorDeArchivos::cargarPeliculasVistas(std::string ruta) {
	listaPeliculasVistas = cargarDesdeArchivo(ruta);
}

void CargadorDeArchivos::cargarPeliculasNoVistas(std::string ruta) {
	listaPeliculasNoVistas = cargarDesdeArchivo(ruta);
}

Lista<Pelicula>* CargadorDeArchivos::obtenerPeliculasVistas() {
	return listaPeliculasVistas;
}

Lista<Pelicula>* CargadorDeArchivos::obtenerPeliculasNoVistas() {
	return listaPeliculasNoVistas;
}

Lista<Pelicula>* CargadorDeArchivos::cargarDesdeArchivo(std::string nombreArchivo) {
	ifstream archivo(nombreArchivo);
	string linea;

	Lista<Pelicula> *auxiliar = new Lista<Pelicula>;

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

			while (archivo.peek() != '\n') {
				archivo >> linea;
				actoresAuxiliares->agregar(linea);
			}

			p.setActores(actoresAuxiliares);
			auxiliar->agregar(p);
		}

		archivo.close();
	}

	return auxiliar;
}
