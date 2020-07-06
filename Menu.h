#ifndef MENU_H_
#define MENU_H_

#include "Lista.h"
#include "Pelicula.h"
#include <cstdlib>

class Menu {
private:
	Lista<Pelicula> *peliculas_vistas;
	Lista<Pelicula> *peliculas_no_vistas;
	Lista<Pelicula> *peliculas_recomendadas;
	unsigned entrada;
public:
	Menu();
	~Menu();

	void mostrarMenu();

	void agregarPeliculasVistas(Lista<Pelicula> *pelicula);
	void agregarPeliculasNoVistas(Lista<Pelicula> *pelicula);
	
	Lista<Pelicula>* obtenerPeliculasVistas();
	Lista<Pelicula>* obtenerPeliculasNoVistas();
	Lista<Pelicula>* obtenerPeliculasRecomendadas();

	void mostrarPeliculasVistas();
	void mostrarPeliculasNoVistas();
	void mostrarPeliculasRecomendadas();

	void calcularRecomendadas();
	
	void limpiarPantalla();
	void menuOpciones();
	
private:
	void mostrarElementos(Lista<Pelicula> * pelicula);

	bool puntajeMayorA(Pelicula *pelicula, int puntaje);

	bool coincidenGenero(Pelicula *peliculaA, Pelicula *peliculaB);

	bool coincidenDirector(Pelicula *peliculaA, Pelicula *peliculaB);

	bool coincidenActores(Pelicula *peliculaA, Pelicula *peliculaB);

	bool coincideDirectorOActor(Pelicula *peliculaA, Pelicula *peliculaB);
};




#endif /* MENU_H_ */
