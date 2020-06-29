#include "Lista.h"
#include "Pelicula.h"
#include "archivos.h"
using namespace std;

void imprimir(string msj) {
	cout << msj << endl;
}

void mostrarElementos(Lista<Pelicula> &pelicula){
	for (unsigned int j = 1; j <= pelicula.getTamanio(); j++) {

		imprimir( pelicula.obtener(j).getNombre());
		imprimir("* Genero: " + pelicula.obtener(j).getGenero());
		imprimir("* Puntaje: " + pelicula.obtener(j).getPuntaje());
		imprimir("* Director: " + pelicula.obtener(j).getDirector());
		imprimir("* Actores: ");

		for (unsigned int i = 1; i <= pelicula.obtener(j).getActores()->getTamanio();i++) {
			imprimir("  - " + pelicula.obtener(j).getActores()->obtener(i));
		}

		cout << endl;
	}
}

int main() {

	Lista<Pelicula> peliculas_vistas;
	Lista<Pelicula> peliculas_no_vistas;

	cargarDesdeArchivo("peliculas_vistas.txt", peliculas_vistas);
	cargarDesdeArchivo("peliculas_no_vistas.txt", peliculas_no_vistas);

	mostrarElementos(peliculas_vistas);
	mostrarElementos(peliculas_no_vistas);

	cout << "** fin **" << endl;

	return 0;
}
