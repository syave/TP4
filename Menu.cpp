#include "Menu.h"

Menu::Menu(){
	this->peliculas_vistas = 0;
	this->peliculas_no_vistas = 0;
}

void Menu::mostrarMenu() {
	int operacion = -1;

	while (operacion != 0) {
		std::cout << "TP4" << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Elegir opcion: " << std::endl;
		std::cout << " -1) Mostrar peliculas vistas. " << std::endl;
		std::cout << " -2) Mostrar peliculas no vistas. " << std::endl;
		std::cout << " -3) Mostrar peliculas recomendadas. " << std::endl;
		std::cout << " -0) Salir. " << std::endl;
		std::cout << "------------------------" << std::endl << std::endl;

		std::cin >> operacion;

		switch (operacion) {
		case 1:
			std::cout << std::endl << "Peliculas vistas: " << std::endl << std::endl;
			mostrarPeliculasVistas();
			break;
		case 2:
			mostrarPeliculasNoVistas();
			break;
		case 3:
			//TODO
			break;
		}
	}
}

void Menu::agregarPeliculasVistas(Lista<Pelicula> *pelicula) {
	this->peliculas_vistas = pelicula;
}

Lista<Pelicula>* Menu::obtenerPeliculasVistas() {
	return peliculas_vistas;
}

void Menu::agregarPeliculasNoVistas(Lista<Pelicula> *pelicula) {
	this->peliculas_no_vistas = pelicula;
}

Lista<Pelicula>* Menu::obtenerPeliculasNoVistas() {
	return peliculas_no_vistas;
}

void Menu::mostrarPeliculasVistas() {
	mostrarElementos (peliculas_vistas);
}

void Menu::mostrarPeliculasNoVistas() {
	mostrarElementos (peliculas_no_vistas);
}

void Menu::mostrarElementos(Lista<Pelicula> * pelicula) {
	for (unsigned int j = 1; j <= pelicula->getTamanio(); j++) {

		std::cout << ( pelicula->obtener(j).getNombre()) << std::endl;
		std::cout << ("* Genero: " + pelicula->obtener(j).getGenero()) << std::endl;
		std::cout << ("* Puntaje: " + pelicula->obtener(j).getPuntaje()) << std::endl;
		std::cout << ("* Director: " + pelicula->obtener(j).getDirector()) << std::endl;
		std::cout << ("* Actores: ");

		for (unsigned int i = 1; i <= pelicula->obtener(j).getActores()->getTamanio();i++) {
			std::cout << ("  - " + pelicula->obtener(j).getActores()->obtener(i)) << std::endl;
		}

		std::cout << std::endl;
	}
}

