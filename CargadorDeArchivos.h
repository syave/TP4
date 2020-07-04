#ifndef CARGADORDEARCHIVOS_H_
#define CARGADORDEARCHIVOS_H_

#include <fstream>
#include <string>

#include "Pelicula.h"
#include "Lista.h"

/*
  Consideraciones:
	 - Los archivos están bien formados pero
	 o El archivo de películas vistas podría no existir. Tener en cuenta que, en ese caso, las
	 recomendaciones solo se harán por puntaje.
	 o El archivo de películas no vistas debe existir, caso contrario se debe lanzar una excepción
	 cerciorándose de que no quede memoria sin liberar.
 */

class CargadorDeArchivos {
private:
	Lista<Pelicula> *listaPeliculasVistas;
	Lista<Pelicula> *listaPeliculasNoVistas;
public:
	CargadorDeArchivos();

	~CargadorDeArchivos();

	void cargarPeliculasVistas(std::string ruta);

	void cargarPeliculasNoVistas(std::string ruta);

	Lista<Pelicula> * obtenerPeliculasVistas();
	Lista<Pelicula> * obtenerPeliculasNoVistas();

private:

	Lista<Pelicula>* cargarDesdeArchivo(std::string nombreArchivo);
};

#endif /* CARGADORDEARCHIVOS_H_ */
