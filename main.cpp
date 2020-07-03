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
///Falta algunos arreglos
/*
void mostrarRecomendados(Lista<Pelicula> &pelicula_reco){
	for (unsigned int i = 1; i <= pelicula_reco.getTamanio(); i++) {

		imprimir("*Recomendadas: " + pelicula_reco.obtener(i).getNombre());
		cout << endl;
	}
}

void compararArchivo(Lista<Pelicula> &pelicula_nv,Lista<Pelicula> &pelicula_v,Lista<Pelicula> &pelicula_r) {
	//int puntaje;
	for (unsigned int j = 1; j <= pelicula_nv.getTamanio(); j++) {
		for (unsigned int i = 1; i <= pelicula_v.getTamanio(); i++) {
			//puntaje = atoi(pelicula_nv.obtener(j).getPuntaje().c_str());
			if((pelicula_v.obtener(i).getGenero() == pelicula_nv.obtener(j).getGenero()) && (pelicula_v.obtener(i).getDirector() == pelicula_nv.obtener(j).getDirector())) {
				//imprimir("*Recomendadas: " + pelicula_v.obtener(i).getNombre());
				cout << endl;
				mostrarRecomendados(pelicula_r);
			}
		}
	}
}
*/

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
