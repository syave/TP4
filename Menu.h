#ifndef MENU_H_
#define MENU_H_

#include "Lista.h"
#include "Pelicula.h"

class Menu {
private:
	Lista<Pelicula> *peliculas_vistas;
	Lista<Pelicula> *peliculas_no_vistas;
public:

	Menu();
	void mostrarMenu();

	void agregarPeliculasVistas(Lista<Pelicula> *pelicula);
	void agregarPeliculasNoVistas(Lista<Pelicula> *pelicula);
	Lista<Pelicula> * obtenerPeliculasVistas();
	Lista<Pelicula> * obtenerPeliculasNoVistas();

	void mostrarPeliculasVistas();
	void mostrarPeliculasNoVistas();
private:
	void mostrarElementos(Lista<Pelicula> * pelicula);
};




#endif /* MENU_H_ */
