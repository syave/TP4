#include "Menu.h"

Menu::Menu(){
	peliculas_vistas = 0;
	peliculas_no_vistas = 0;
	peliculas_recomendadas = 0;
	entrada = 0;
}

Menu::~Menu() {
		delete peliculas_vistas;
		delete peliculas_no_vistas;
		delete peliculas_recomendadas;
}

void Menu::mostrarMenu() {
	while (entrada != 4) {
		menuOpciones();

		std::cin >> entrada;

		switch (entrada) {
		case 1:
			std::cout << std::endl << "Peliculas vistas: " << std::endl << std::endl;
			mostrarPeliculasVistas();
			break;
		case 2:
			mostrarPeliculasNoVistas();
			break;
		case 3:
			mostrarPeliculasRecomendadas();
			break;
		case 4:
			limpiarPantalla();
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

void Menu::mostrarPeliculasRecomendadas() {
	mostrarElementos (peliculas_recomendadas);
}

void Menu::mostrarElementos(Lista<Pelicula> * pelicula) {
	limpiarPantalla();
	
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
void Menu::calcularRecomendadas(){
	limpiarPantalla();
	
	if (peliculas_vistas != 0 && peliculas_no_vistas != 0) {

		peliculas_recomendadas = new Lista<Pelicula>;
		Pelicula peliculaVista;
		Pelicula peliculaNoVista;

//		No se si es muy optimo pero es lo unico que se me ocurrio xd
		for (unsigned int i = 1; i <= peliculas_vistas->getTamanio(); i++) {

			peliculaVista = peliculas_vistas->obtener(i);

			if (puntajeMayorA(&peliculaVista, 7)) {
				peliculas_recomendadas->agregar(peliculaVista);
			}

			for (unsigned int j = 1; j <= peliculas_no_vistas->getTamanio(); j++) {

				peliculaNoVista = peliculas_no_vistas->obtener(j);

				if(coincidenDirector(&peliculaVista, &peliculaNoVista)){

					peliculas_recomendadas->agregar(peliculaNoVista);
				}
/*
* 		A SOLUCIONAR: deberia (creo) poder verificar que coincidan
* 			          director o actores con esta funcion, pero
* 			          los elementos dentro de la lista recomendadas
* 			          se duplican..
*
				if(coincideDirectorOActor(&peliculaVista, &peliculaNoVista)){

					peliculas_recomendadas->agregar(peliculaNoVista);
				}
*/
			}
		}
	}
}

bool Menu::puntajeMayorA(Pelicula *pelicula, int puntaje){
	return (atoi(pelicula->getPuntaje().c_str()) >= puntaje);
}

bool Menu::coincidenGenero(Pelicula *peliculaA, Pelicula *peliculaB) {
	return (peliculaA->getGenero() == peliculaB->getGenero());
}

bool Menu::coincidenDirector(Pelicula *peliculaA, Pelicula *peliculaB) {
	return (peliculaA->getDirector() == peliculaB->getDirector());
}

bool Menu::coincidenActores(Pelicula *peliculaA, Pelicula *peliculaB) {
	bool hayCoincidendia = false;

	for (unsigned int i = 0; i <= peliculaA->getActores()->getTamanio(); i++) {
		for (unsigned int j = 0; j <= peliculaB->getActores()->getTamanio(); j++) {
			if (peliculaA->getActores()->obtener(i) == peliculaB->getActores()->obtener(j)) {
				hayCoincidendia = true;
			}
		}
	}

	return hayCoincidendia;
}

bool Menu::coincideDirectorOActor(Pelicula *peliculaA, Pelicula *peliculaB) {
	return (coincidenDirector(peliculaA, peliculaB)) || coincidenActores(peliculaA, peliculaB);
}

void Menu::limpiarPantalla(){

	#ifdef linux
    		system("clear");
	#else
    		system ("cls");
	#endif
}

void Menu::menuOpciones() {
	std::cout << "TP4" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Por favor introduzca una opcion: " << std::endl;
	std::cout << 	" -1) Mostrar peliculas vistas.\n"
			" -2) Mostrar peliculas no vistas.\n"
			" -3) Mostrar peliculas recomendadas.\n"
			" -4) Salir.\n";
	std::cout << "--------------------------------------" << std::endl << std::endl;
	std::cout << "Entrada: ";
}
