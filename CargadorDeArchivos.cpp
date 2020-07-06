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
	string nombre,generos,director,puntaje,actores;

	Lista<Pelicula> *auxiliar = new Lista<Pelicula>;

	if (!archivo.fail()) {

		while (archivo >> nombre) {
			Pelicula peliculaAuxiliar;
			Lista<string> *actoresAuxiliares = new Lista<string>;

			getline(archivo,linea);
			nombre +=  linea;
			peliculaAuxiliar.setNombre(nombre);

			archivo >> generos;
			getline(archivo,linea);
			generos += linea;
			peliculaAuxiliar.setGenero(generos);

			archivo >> puntaje;
			peliculaAuxiliar.setPuntaje(puntaje);

			archivo >> director;
			getline(archivo,linea);
			director += linea;
			peliculaAuxiliar.setDirector(director);

			archivo >> actores;
			actoresAuxiliares->agregar(actores);

			while (archivo.peek() != '\n') {
				archivo >> actores;
				actoresAuxiliares->agregar(actores);
			}

			peliculaAuxiliar.setActores(actoresAuxiliares);
			auxiliar->agregar(peliculaAuxiliar);
		}

		archivo.close();
	}

	return auxiliar;
}
