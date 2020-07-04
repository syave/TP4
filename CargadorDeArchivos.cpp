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
	if(listaPeliculasVistas==0) std::cout << "No se abrio archivo" << std::endl;
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
			Pelicula peliculaAuxiliar;
			Lista<string> *actoresAuxiliares = new Lista<string>;

			peliculaAuxiliar.setNombre(linea);

			archivo >> linea;
			peliculaAuxiliar.setGenero(linea);

			archivo >> linea;
			peliculaAuxiliar.setPuntaje(linea);

			archivo >> linea;
			peliculaAuxiliar.setDirector(linea);

			archivo >> linea;
			actoresAuxiliares->agregar(linea);

			while (archivo.peek() != '\n') {
				archivo >> linea;
				actoresAuxiliares->agregar(linea);
			}

			peliculaAuxiliar.setActores(actoresAuxiliares);
			auxiliar->agregar(peliculaAuxiliar);
		}

		archivo.close();
	}

	return auxiliar;
}
